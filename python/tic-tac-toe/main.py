from player import FirstEmptyBotPlayer
from player import HumanPlayer
from game import Game

players = []
game_type = input('[b]ot mode or [h]uman mode: ').lower()
if game_type == 'b' or game_type == '':
  players = [
    HumanPlayer('X', input('player 1 name: ')),
    FirstEmptyBotPlayer('O', 'bot')
  ]
elif game_type == 'h':
  players = [
    HumanPlayer('X', input('player 1 name: ')),
    HumanPlayer('O', input('player 2 name: '))
  ]

game = Game(players)
game.play()
