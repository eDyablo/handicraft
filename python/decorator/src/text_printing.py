class TextPrinter:
  def __init__(self, output):
    self.output = output

  def print(self, text):
    if text.isspace() == False:
      self.output.write(text)

  def line_feed(self):
    self.output.write("\n")


class TextPrinterDecorator:
  def __init__(self, printer):
    self.printer = printer

  def print(self, text):
    return self.printer.print(text)

  def line_feed(self):
    return self.printer.line_feed()


class NumberedTextPrinter(TextPrinterDecorator):
  def __init__(self, printer):
    super().__init__(printer)
    self.counter = 0

  def print(self, text):
    self.counter += 1
    self.printer.print(str(self.counter) + " " + text)
    #self.printer.print(str(self.counter) + " ")
    #self.printer.print(text)


class CapitalizedTextPrinter(TextPrinterDecorator):
  def __init__(self, printer):
    super().__init__(printer)

  def print(self, text):
    self.printer.print(text.capitalize())


class DentedTextPrinter(TextPrinterDecorator):
  def __init__(self, printer):
    super().__init__(printer)

  def print(self, text):
    self.printer.print(' '.join(list(text)))


class QuotedTextPrinter(TextPrinterDecorator):
  def __init__(self, printer):
    super().__init__(printer)

  def print(self, text):
    self.printer.print("`" + text + "`")


class ReversedTextPrinter(TextPrinterDecorator):
  def __init__(self, printer):
    super().__init__(printer)

  def print(self, text):
    self.printer.print(text[::-1])
