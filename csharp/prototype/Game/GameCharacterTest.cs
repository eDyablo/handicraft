using Xunit;
using FluentAssertions;

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
    public void Clone_has_its_own_postion() {
      var origin = new GameCharacter();
      var clone = origin.Clone() as GameCharacter;
      clone.Position.Should().NotBeSameAs(origin.Position);
    }

    [Fact]
    public void Clone_copies_name_from_source() {
      var source = new GameCharacter { Name = "name" };
      var clone = source.Clone() as GameCharacter;
      clone.Name.Should().Be("name");
    }
  }
}
