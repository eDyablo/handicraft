using System;

namespace prototype.Game
{
  public class GameMapPosition {
    public int Latitude { get; private set; }

    public int Longetude { get; private set; }

    public static GameMapPosition FromCoordinates(int latitude, int longetude) {
      return new GameMapPosition {
        Latitude = latitude,
        Longetude = longetude,
      };
    }

    public static GameMapPosition CopyFrom(GameMapPosition source) {
      return new GameMapPosition {
        Latitude = source.Latitude,
        Longetude = source.Longetude,
      };
    }
  }
}
