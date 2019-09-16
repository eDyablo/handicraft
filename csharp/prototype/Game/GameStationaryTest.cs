using Xunit;
using FluentAssertions;

namespace prototype.Game
{
  public class GameStationaryTest {
    [Fact]
    public void Clone_copies_durability_from_origin() {
      var origin = new GameStationary { Durability = 100 };
      var clone = origin.Clone() as GameStationary;
      clone.Durability.Should().Be(origin.Durability);
    }
  }
}
