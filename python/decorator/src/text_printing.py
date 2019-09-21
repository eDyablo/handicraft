class TextPrinter:
  def __init__(self, output):
    self.output = output

  def print(self, text):
    if text.isspace() == False:
      self.output.write(text)

  def line_feed(self):
    self.output.write("\n")

class NumberedTextPrinter(TextPrinter):
  def __init__(self, printer):
    self.printer = printer
    self.counter = 0

  def print(self, text):
    self.counter += 1
    self.printer.print(str(self.counter) + " " + text)
    #self.printer.print(str(self.counter) + " ")
    #self.printer.print(text)

  def line_feed(self):
    return self.printer.line_feed()

class CapitalizedTextPrinter(TextPrinter):
  def __init__(self, printer):
    self.printer = printer

  def print(self, text):
    self.printer.print(text.capitalize())

  def line_feed(self):
    return self.printer.line_feed()

class DentedTextPrinter(TextPrinter):
  def __init__(self, printer):
    self.printer = printer

  def print(self, text):
    self.printer.print(' '.join(list(text)))

  def line_feed(self):
    return self.printer.line_feed()

class QuotedTextPrinter(TextPrinter):
  def __init__(self, printer):
    self.printer = printer

  def print(self, text):
    self.printer.print("`" + text + "`")

  def line_feed(self):
    return self.printer.line_feed()

class ReversedTextPrinter(TextPrinter):
  def __init__(self, printer):
    self.printer = printer

  def print(self, text):
    self.printer.print(text[::-1])

  def line_feed(self):
    return self.printer.line_feed()

if __name__ == "__main__":
  pass
