class Board:
  h_line = '\n--+---+--\n'
  v_line = ' | '

  def __init__(self):
    self.cells = [
      [' ', ' ', ' '],
      [' ', ' ', ' '],
      [' ', ' ', ' ']
    ]

  def draw(self):
    print(self.h_line.join([self.v_line.join(row) for row in self.cells]))

  def has_empty_cell(self):
    return self.empty_cell() != None

  def empty_cell(self):
    for row in range(3):
      for column in range(3):
        if self.cells[row][column] == ' ':
          return row, column
    return None

  def win_row(self, row, symbol):
    for column in range(3):
      if self.cells[row][column] != symbol:
        return False
    return True

  def win_a_row(self, symbol):
    for row in range(3):
      if self.win_row(row, symbol):
        return True
    return False

  def win_column(self, column, symbol):
    for row in range(3):
      if self.cells[row][column] != symbol:
        return False
    return True

  def win_a_column(self, symbol):
    for column in range(3):
      if self.win_column(column, symbol):
        return True
    return False

  def win_a_diagonal(self, symbol):
    first = self.cells[0][0] == symbol and self.cells[1][1] == symbol and self.cells[2][2] == symbol
    second  = self.cells[2][0] == symbol and self.cells[1][1] == symbol and self.cells[0][2] == symbol
    return first or second

  def win_board(self, symbol):
    return self.win_a_row(symbol) or self.win_a_column(symbol) or self.win_a_diagonal(symbol)


class Game:
  def __init__(self, players):
    self.board = Board()
    self.players = players

  def play(self):
    while self.board.has_empty_cell():
      for player in self.players:
        self.board.draw()
        player.take_turn(self.board)
      winner = self.winner()
      if winner:
        self.board.draw()
        print(f'{ winner.name.upper() } win!')
        break

  def winner(self):
    for player in self.players:
      if self.board.win_board(player.symbol):
        return player
