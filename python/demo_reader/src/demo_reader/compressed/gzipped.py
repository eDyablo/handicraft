import gzip

from ..utility import writer

filename_extension = ".gz"
opener = gzip.open

if __name__ == "__main__":
  writer.main(opener, filename_extension)
