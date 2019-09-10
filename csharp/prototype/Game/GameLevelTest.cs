using Xunit;
using Moq;

namespace prototype.Game {
  public class GameLevelTest {
    [Fact]
    public void Builds_itself_using_provided_prototypes() {
      // Given
      var asset = new GameAsset();
      var wall = asset.RegisterPrototype("wall", Mock.Of<GameObject>());
      var door = asset.RegisterPrototype("door", Mock.Of<GameObject>());
      var hero = asset.RegisterPrototype("hero", Mock.Of<GameObject>());
      var enemy = asset.RegisterPrototype("enemy", Mock.Of<GameObject>());
      var level = new GameLevel();
      // When
      level.Build(asset);
      // Then
      Mock.Get(wall).Verify(w => w.Clone(), Times.AtLeastOnce);
      Mock.Get(door).Verify(d => d.Clone(), Times.AtLeastOnce);
      Mock.Get(enemy).Verify(e => e.Clone(), Times.AtLeastOnce);
      Mock.Get(hero).Verify(h => h.Clone(), Times.Once);
    }
  }
}
