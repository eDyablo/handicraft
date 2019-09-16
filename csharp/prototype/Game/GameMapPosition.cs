namespace prototype.Game
{
    public class GameMapPosition {
    public int Latitude { get; private set; }

    public int Longitude { get; private set; }

    public static GameMapPosition FromCoordinates(int latitude, int longitude) {
      return new GameMapPosition {
        Latitude = latitude,
        Longitude = longitude,
      };
    }

    public static GameMapPosition CopyFrom(GameMapPosition source) {
      return new GameMapPosition {
        Latitude = source.Latitude,
        Longitude = source.Longitude,
      };
    }
  }
}
