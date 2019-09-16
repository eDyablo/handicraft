using Xunit;
using FluentAssertions;

namespace prototype.Game
{
  public class GameMapPositionTest {
    [Fact]
    public void Newly_created_has_zero_coordinates() {
      var position = new GameMapPosition();
      position.Should().Match<GameMapPosition>(p =>
        p.Longitude == 0 && p.Latitude == 0);
    }

    [Fact]
    public void Created_from_coordinates_stores_them() {
      var position = GameMapPosition.FromCoordinates(1, 2);
      position.Should().Match<GameMapPosition>(p =>
        p.Latitude == 1 && p.Longitude == 2);
    }

    [Fact]
    public void Copied_from_another_position_copies_its_coordinates() {
      var source = GameMapPosition.FromCoordinates(1, 2);
      var position = GameMapPosition.CopyFrom(source);
    }
  }
}
