import bz2

from ..utility import writer

filename_extension = ".bz2"
opener = bz2.open

if __name__ == "__main__":
  writer.main(opener, filename_extension)
