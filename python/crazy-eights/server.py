from flask import Flask, jsonify, request
from playcard import Deck, EnglishPattern
import json
import random
import string


class NameGenerator:
    def __init__(self):
        self.__adjectives = [line.strip() for line in open('adjectives.txt')]
        self.__nouns = [line.strip() for line in open('nouns.txt')]

    def generate_game_name(self):
        return f'{random.choice(self.__adjectives)}-{random.choice(self.__nouns)}'

    def generate_player_name(self):
        prefix = ''.join(random.choice(string.ascii_lowercase)
                         for _ in range(5))
        number = ''.join(random.choice(string.digits) for _ in range(3))
        return f'{prefix}-{number}'


class Player:
    def __init__(self, id):
        self.id = id

    def serialized(self):
        return {
            'id': self.id,
        }


class Game:
    def __init__(self, id, pattern):
        self.id = id
        self.__deck = pattern.build_deck()
        self.__deck.shuffle()
        self.__discardpile = Deck()
        self.__hands = {}

    def add_player(self, player):
        if self.hands_count() < 2:
            self.__hands[player.id] = Deck()
            if self.hands_count() == 2:
                self.__deal_cards()

    def hands_count(self):
        return len(self.__hands)

    def __deal_cards(self):
        for i in range(0, 5):
            for (player, hand) in self.__hands.items():
                hand.put(self.__deck.draw())
        self.__discardpile.put(self.__deck.draw())

    def serialized(self):
        return {
            'id': self.id,
            'deck': str(self.__deck),
            'discardpile': str(self.__discardpile),
            'hands_count': self.hands_count(),
            'hands': {player: str(deck) for (player, deck) in self.__hands.items()},
        }


class Server(Flask):
    def __init__(self):
        super().__init__(__name__)
        self.games = {}
        self.players = {}
        self.names = NameGenerator()

    def create_game(self):
        game = Game(server.names.generate_game_name(), EnglishPattern())
        self.games[game.id] = game
        return game

    def create_player(self):
        player = Player(server.names.generate_player_name())
        self.players[player.id] = player
        return player

    def get_player(self, id):
        return self.players[id]


server = Server()


@server.route('/')
def home():
    return jsonify({
        'name': 'crazy eights',
        'player-count': len(server.players),
        'game-count': len(server.games),
    }), 200


@server.route('/game/all', methods=['GET'])
def get_all_games():
    return jsonify([game.serialized() for game in server.games.values()]), 200


@server.route('/game', methods=['POST'])
def create_new_game():
    data = request.get_json()
    game = server.create_game()
    if 'player' in data:
        game.add_player(server.get_player(data['player']))
    return jsonify({'game': game.serialized()}), 200


@server.route('/game/<game_id>', methods=['GET'])
def get_game(game_id):
    game = server.games.get(game_id)
    if game:
        return jsonify({'game': game.serialized()}), 200
    else:
        return jsonify({'message': 'game not found'}), 404


@server.route('/game', methods=['GET'])
def get_games():
    games = server.games.values()
    if 'hands_count' in request.args:
        hands_count = int(request.args['hands_count'])
    games = [game for game in games if game.hands_count() == hands_count]
    return jsonify([game.serialized() for game in games]), 200


@server.route('/game/<game_id>', methods=['DELETE'])
def delete_game(game_id):
    del server.games[game_id]
    return jsonify({'message': f'game {game_id} has been deleted'}), 200


@server.route('/game/<game_id>/player', methods=['PUT'])
def add_game_player(game_id):
    game = server.games.get(game_id)
    if not game:
        return jsonify({'message': 'game not found'}), 404
    data = request.get_json()
    player = server.players.get(data['player'])
    if not player:
        return jsonify({'message': 'player not found'}), 404
    game.add_player(player)
    return jsonify({
        'game': game.serialized(),
        'message': f'player {player.id} has been added to {game_id} game',
    }), 200


@server.route('/player/all', methods=['GET'])
def get_all_players():
    return jsonify([player.serialized() for player in server.players.values()]), 200


@server.route('/player', methods=['POST'])
def create_new_player():
    data = request.get_json()
    player = server.create_player()
    return jsonify({'player': player.serialized()}), 200


@server.route('/player/<player_id>', methods=['GET'])
def get_player(player_id):
    player = server.players.get(player_id)
    if player:
        return jsonify(player.serialized()), 200
    else:
        return jsonify({'message': 'player not found'}), 404


@server.route('/player/<id>', methods=['DELETE'])
def delete_player(id):
    del server.players[id]
    return jsonify({'message': f'player {id} had been deleted'}), 200


if __name__ == '__main__':
    server.run(debug=True)
