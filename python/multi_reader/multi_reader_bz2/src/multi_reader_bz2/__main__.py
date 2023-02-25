from multi_reader.utility import writer
from . import bzipped

writer.main(bzipped.opener, bzipped.filename_extension)
