import os

from .compressed import bzipped
from .compressed import gzipped

extension_mapping = {
  bzipped.filename_extension: bzipped.opener,
  gzipped.filename_extension: gzipped.opener,
}


class MultiReader:

  def __init__(self, filename):
    base_name, name_extension = os.path.splitext(filename)
    opener = extension_mapping.get(name_extension, open)
    self._file = opener(filename, mode="rt")

  def read(self):
    return self._file.read()

  def close(self):
    self._file.close()
