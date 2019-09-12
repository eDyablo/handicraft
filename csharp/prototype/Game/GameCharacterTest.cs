using Xunit;
using FluentAssertions;
using Moq;

namespace prototype.Game
{
  public class GameCharacterTest {
    [Fact]
    public void Newly_created_Has_Position() {
      var character = new GameCharacter();
      character.Position.Should().NotBeNull();
    }

    [Fact]
    public void Newly_created_Has_No_Name() {
      var character = new GameCharacter();
      character.Name.Should().BeNull();
    }

    [Fact]
    public void MoveTo_changes_characters_position() {
      var character = new GameCharacter();
      character.MoveTo(GameMapPosition.FromCoordinates(1, 2));
      character.Position.Should().Match<GameMapPosition>(p =>
        p.Latitude == 1 && p.Longitude == 2
      );
    }

    [Fact]
    public void Clone_has_its_own_postion() {
      var origin = new GameCharacter();
      var clone = origin.Clone() as GameCharacter;
      clone.Position.Should().NotBeSameAs(origin.Position);
    }

    [Fact]
    public void Clone_copies_postion_from_source() {
      var source = new GameCharacter();
      source.MoveTo(GameMapPosition.FromCoordinates(1, 2));
      var clone = source.Clone() as GameCharacter;
      clone.Position.Should().Match<GameMapPosition>(p =>
        p.Latitude == source.Position.Latitude
        && p.Longitude == source.Position.Longitude
      );
    }

    [Fact]
    public void Clone_copies_name_from_source() {
      var source = new GameCharacter { Name = "name" };
      var clone = source.Clone() as GameCharacter;
      clone.Name.Should().Be("name");
    }

    [Fact]
    public void Clone_copies_hit_points_from_source() {
      var source = new GameCharacter { HitPoints = 1.0f };
      var clone = source.Clone() as GameCharacter;
      clone.HitPoints.Should().Be(1.0f);
    }

    [Fact]
    public void Clone_shares_model_with_source() {
      var source = new GameCharacter { Model = Mock.Of<GameCharacterModel>() };
      var clone = source.Clone() as GameCharacter;
      clone.Model.Should().BeSameAs(source.Model);
    }
  }
}
