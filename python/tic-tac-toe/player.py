class HumanPlayer:
  def __init__(self, symbol, name):
    self.symbol = symbol
    self.name = name

  def take_turn(self, board):
    row, column = input(f'{ self.name.upper() } row & column: ').split()
    board.cells[int(row)][int(column)] = self.symbol


class FirstEmptyBotPlayer:
  def __init__(self, symbol, name):
    self.symbol = symbol
    self.name = name

  def take_turn(self, board):
    row, column = board.empty_cell()
    board.cells[row][column] = self.symbol
    board.cells[int(row)][int(column)] = self.symbol
    print(f'{ self.name.upper() } row & column: {row} {column}')


class BotPlayer:
  turns = [
    (1, 1),
    (0, 0), (2, 2),
    (0, 2), (2, 0),
    (0, 1), (1, 0), (1, 2), (2, 1)
  ]

  def __init__(self, symbol, name):
    self.symbol = symbol
    self.name = name

  def find_turn(self, board):
    for turn in self.turns:
      row, column = turn
      if board.cells[row][column] == ' ':
        return turn

  def take_turn(self, board):
    row, column = self.find_turn(board)
    board.cells[row][column] = self.symbol
    print(f'{ self.name.upper() } row & column: {row} {column}')
