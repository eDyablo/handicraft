import os
import pkg_resources


plugins = {
  entry_point.load()
  for entry_point
  in pkg_resources.iter_entry_points("multi_reader.plugins")
}

extension_mapping = {
  module.filename_extension: module.opener for module in plugins
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
