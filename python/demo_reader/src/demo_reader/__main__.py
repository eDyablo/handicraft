import sys

from .multireader import MultiReader

reader = MultiReader(sys.argv[1])
print(reader.read())
reader.close()
