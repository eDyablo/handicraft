import sys
import os


def main(opener, extension):
  base_name, name_extension = os.path.splitext(sys.argv[1])
  if not name_extension:
    name_extension = extension
  with opener(base_name + name_extension, mode="wt") as file:
    file.write(" ".join(sys.argv[2:]))
