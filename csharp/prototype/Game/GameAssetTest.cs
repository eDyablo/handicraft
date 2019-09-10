using Xunit;
using Moq;
using FluentAssertions;
using System;

namespace prototype.Game
{
  public class GameAssetTest {
    [Fact]
    public void Gives_prototype_registered_with_the_key() {
      var asset = new GameAsset();
      var prototype = Mock.Of<GameObject>();
      asset.RegisterPrototype("key", prototype);
      asset.GetObjectPrototype("key").Should().BeSameAs(prototype);
    }

    [Fact]
    public void Throws_when_no_prototype_registered_for_the_key() {
      var asset = new GameAsset();
      Action getProtype = () => asset.GetObjectPrototype("non-registered");
      getProtype.Should().Throw<Exception>();
    }

    [Fact]
    public void Registers_multiple_prototypes_and_gives_proper_for_each_key() {
      var asset = new GameAsset();
      var first = asset.RegisterPrototype("first", Mock.Of<GameObject>());
      var second = asset.RegisterPrototype("second", Mock.Of<GameObject>());
      asset.GetObjectPrototype("first").Should().BeSameAs(first);
      asset.GetObjectPrototype("second").Should().BeSameAs(second);
    }
  }
}
