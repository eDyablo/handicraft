from multi_reader.utility import writer
from . import gzipped

writer.main(gzipped.opener, gzipped.filename_extension)
