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


class Player:
    def __init__(self, server, **data):
        self.__server = server
        self.name = data.get('id')


class Game(Cmd):
    def __init__(self, server, **data):
        super().__init__()
        self.__server = server
        self.__name = data.get('id')
        self.prompt = f'({self.__name}) '

    def add_player(self, player_id):
        self.__server.add_player_to_game(player_id, self.__name)

    def do_quit(self, arg):
        'Quit the game'
        self.__server.delete_game(self.__name)
        return True


class Client(Cmd):
    def __init__(self, server):
        super().__init__()
        self.__server = server
        self.prompt = f'({self.__server.describe()["name"]}) '

    def new_game(self):
        return Game(self.__server, **self.__server.create_game(self.__player.name))

    def join_game(self, name):
        game = Game(self.__server, **self.__server.get_game(name))
        game.add_player(self.__player.name)
        return game

    def preloop(self):
        self.__player = Player(self.__server, **self.__server.create_player())

    def postloop(self):
        self.__server.delete_player(self.__player.name)

    def do_new(self, arg):
        'Start a new game'
        self.new_game().cmdloop()

    def do_join(self, arg):
        'Join existing game by given name'
        self.join_game(arg.split()[0]).cmdloop()

    def do_exit(self, arg):
        'Exit the program'
        return True


if __name__ == '__main__':
    Client(Server(HTTPConnection('localhost', 5000))).cmdloop()
