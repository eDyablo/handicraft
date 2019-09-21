import unittest
import text_printing as tp
import io

class TestCase(unittest.TestCase):
  def setUp(self):
    self.output = io.StringIO()

  def read_output(self):
    return self.output.getvalue()

class TextPrinterTest(TestCase):
  def setUp(self):
    super().setUp()
    self.printer = tp.TextPrinter(self.output)

  def test_prints_one_word(self):
    self.printer.print("word")
    self.assertEqual(self.read_output(), "word")

  def test_does_not_print_whitespace(self):
    self.printer.print(" ")
    self.assertEqual(self.read_output(), "")

  def test_feeds_one_line(self):
    self.printer.line_feed()
    self.assertEqual(self.read_output(), "\n")

class NumberedTextPrinterTest(TestCase):
  def setUp(self):
    super().setUp()
    self.printer = tp.NumberedTextPrinter(tp.TextPrinter(self.output));

  def test_prints_first_text_numbered_by_one(self):
    self.printer.print("text")
    self.assertEqual("1 text", self.read_output())

  def test_numbers_each_print_sequentially(self):
    self.printer.print("first")
    self.printer.line_feed()
    self.printer.print("second")
    self.assertEqual("1 first\n2 second", self.read_output())

class CapitalizedTextPrinterTest(TestCase):
  def setUp(self):
    super().setUp()
    self.printer = tp.CapitalizedTextPrinter(tp.TextPrinter(self.output))

  def test_prints_capitalized_text(self):
    self.printer.print("text")
    self.assertEqual(self.read_output(), "Text")

class DentedTextPrinterTest(TestCase):
  def setUp(self):
    super().setUp()
    self.printer = tp.DentedTextPrinter(tp.TextPrinter(self.output))

  def test_prints_dented_text(self):
    self.printer.print("text")
    self.assertEqual(self.read_output(), "t e x t")

class QuotedTextPrinterTest(TestCase):
  def setUp(self):
    super().setUp()
    self.printer = tp.QuotedTextPrinter(tp.TextPrinter(self.output))
    self.printer.quote = "`"

  def test_prints_quoted_text(self):
    self.printer.print("text")
    self.assertEqual(self.read_output(), "`text`")

class ReversedTextPrinterTest(TestCase):
  def setUp(self):
    super().setUp()
    self.printer = tp.ReversedTextPrinter(tp.TextPrinter(self.output))

  def test_prints_reversed_text(self):
    self.printer.print("text")
    self.assertEqual(self.read_output(), "txet")
