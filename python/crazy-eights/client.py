from http.client import HTTPConnection
import json
from cmd import Cmd


class Server:
    def __init__(self, connection):
        self.__connection = connection

    def describe(self):
        self.__connection.request('GET', '/')
        return json.loads(self.__connection.getresponse().read())

    def create_game(self, player_id=None):
        data = {}
        if player_id:
            data['player'] = player_id
        self.__connection.request(
            'POST', '/game', json.dumps(data), {'content-type': 'application/json'})
        return json.loads(self.__connection.getresponse().read())['game']

    def delete_game(self, game_id):
        self.__connection.request('DELETE', f'/game/{game_id}')
        self.__connection.getresponse().read()

    def get_game(self, game_id):
        self.__connection.request('GET', f'/game/{game_id}')
        return json.loads(self.__connection.getresponse().read())['game']

    def get_open_games(self):
        self.__connection.request('GET', '/game?hands_count=1')
        return json.loads(self.__connection.getresponse().read())

    def create_player(self):
        self.__connection.request('POST', '/player')
        return json.loads(self.__connection.getresponse().read())['player']

    def delete_player(self, player_id):
        self.__connection.request('DELETE', f'/player/{player_id}')
        self.__connection.getresponse().read()

    def add_player_to_game(self, player_id, game_id):
        self.__connection.request('PUT', f'/game/{game_id}/player', json.dumps(
            {'player': player_id}), {'content-type': 'application/json'})
        self.__connection.getresponse().read()

    def get_playing_hand(self, game_id, player_id):
        self.__connection.request('GET', f'/game/{game_id}/hand/{player_id}')
        return json.loads(self.__connection.getresponse().read())['hand']

    def get_discard_pile_top(self, game_id):
        self.__connection.request('GET', f'/game/{game_id}/discard_pile_top')
        return json.loads(self.__connection.getresponse().read())['card']

    def make_buy(self, game_id, player_id):
        self.__connection.request('POST', f'/game/{game_id}/buy', json.dumps(
            {'game': game_id, 'player': player_id}), {'content-type': 'application/json'})
        self.__connection.getresponse().read()

    def game_drop(self, game_id, player_id, card_id):
        self.__connection.request('POST', f'/game/{game_id}/drop', json.dumps(
            {'player': player_id, 'card': card_id}), {'content-type': 'application/json'})
        self.__connection.getresponse().read()


class Player:
    def __init__(self, server, **data):
        self.__server = server
        self.name = data.get('id')


class Game(Cmd):
    def __init__(self, server, **data):
        super().__init__()
        self.__server = server
        self.name = data.get('id')
        self.prompt = f'({self.name}) '

    def add_player(self, player):
        self.__server.add_player_to_game(player.name, self.name)
        self.__player = player
        self.prompt = f'({player.name} playing {self.name}) '

    def do_hand(self, arg):
        'Show playing hand'
        print(self.__server.get_playing_hand(self.name, self.__player.name))

    def do_top(self, arg):
        'Show discard pile top'
        print(self.__server.get_discard_pile_top(self.name))

    def do_buy(self, arg):
        'Receive card from the game deck'
        self.__server.make_buy(self.name, self.__player.name)

    def do_drop(self, arg):
        'Place card from hand on top of discard pile'
        if arg:
            card_id = int(arg.split()[0])
        else:
            card_id = int(input('select a card: '))
        self.__server.game_drop(self.name, self.__player.name, card_id)

    def do_quit(self, arg):
        'Quit the game'
        self.__server.delete_game(self.name)
        return True


class Client(Cmd):
    def __init__(self, server):
        super().__init__()
        self.__server = server
        self.prompt = f'({self.__server.describe()["name"]}) '

    def new_game(self):
        game = Game(self.__server, **
                    self.__server.create_game(self.__player.name))
        game.add_player(self.__player)
        return game

    def join_game(self, name=None):
        if name:
            game = Game(self.__server, **self.__server.get_game(name))
        else:
            game = Game(self.__server, **self.__server.get_open_games()[0])
        game.add_player(self.__player)
        return game

    def preloop(self):
        self.__player = Player(self.__server, **self.__server.create_player())

    def postloop(self):
        self.__server.delete_player(self.__player.name)

    def do_new(self, arg):
        'Start a new game'
        self.new_game().cmdloop()

    def do_list(self, arg):
        'List open games'
        games = self.__server.get_open_games()
        if games:
            print(' '.join(game['id'] for game in games))

    def do_join(self, arg):
        'Join existing game by given name or first open game found when the name is omitted'
        name = arg.split()[0] if arg else None
        self.join_game(name).cmdloop()

    def do_exit(self, arg):
        'Exit the program'
        return True


if __name__ == '__main__':
    Client(Server(HTTPConnection('localhost', 5000))).cmdloop()
