import sys
import text_printing as tp


def print_text(printer):
  printer.print("hello world")
  printer.line_feed()
  printer.print("how are you")
  printer.line_feed()
  printer.line_feed()

def run():
  raw_printer = tp.TextPrinter(sys.stdout)
  printers = [
    tp.TextPrinter(sys.stdout),
    tp.NumberedTextPrinter(raw_printer),
    tp.CapitalizedTextPrinter(raw_printer),
    tp.DentedTextPrinter(raw_printer),
    tp.QuotedTextPrinter(raw_printer),
    tp.ReversedTextPrinter(raw_printer),
    tp.TitledTextPrinter(raw_printer),
    tp.UpperTextPrinter(raw_printer),
    tp.LowerTextPrinter(raw_printer),
    tp.CapitalizedTextPrinter(tp.NumberedTextPrinter(raw_printer)),
    tp.CapitalizedTextPrinter(tp.DentedTextPrinter(raw_printer)),
    tp.DentedTextPrinter(tp.QuotedTextPrinter(raw_printer)),
    tp.QuotedTextPrinter(tp.NumberedTextPrinter(raw_printer)),
    tp.NumberedTextPrinter(tp.QuotedTextPrinter(raw_printer)),
    tp.NumberedTextPrinter(tp.DentedTextPrinter(tp.QuotedTextPrinter(raw_printer))),
    tp.ReversedTextPrinter(tp.CapitalizedTextPrinter(tp.ReversedTextPrinter(raw_printer))),
    tp.TiedTextPrinter(tp.UpperTextPrinter(raw_printer), tp.ReversedTextPrinter(raw_printer)),
  ]

  for printer in printers:
    print_text(printer)


if __name__ == "__main__":
  run()
