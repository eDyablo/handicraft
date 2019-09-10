using System.Collections.Generic;

namespace prototype.Game
{
  class GameLevel {
    readonly IList<string> map = new[] {
      "###############",
      "|   #         #",
      "#   #     #   #",
      "# E #  H  # E #",
      "#   #     #   #",
      "#         #   #",
      "############-##",
    };

    public void Build(GameAsset asset) {
      foreach (var row in map) {
        foreach (var cell in row) {
          GameObject go;
          switch (cell) {
            case '#':
              go = asset.GetObjectPrototype("wall").Clone();
              break;
            case '|':
            case '-':
              go = asset.GetObjectPrototype("door").Clone();
              break;
            case 'E':
              go = asset.GetObjectPrototype("enemy").Clone();
              break;
            case 'H':
              go = asset.GetObjectPrototype("hero").Clone();
              break;
            case ' ':
              break;
            default:
              throw new System.Exception("Unknown cell type");
          }
        }
      }
    }
  }
}