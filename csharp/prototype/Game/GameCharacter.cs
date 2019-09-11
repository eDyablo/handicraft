using System;

namespace prototype.Game
{
  public class GameCharacter : GameObject {
    public string Name { get; set; }
    public float HitPoints { get; set; }

    public GameCharacter() {
      Position = new GameMapPosition();
    }

    public override GameObject Clone() {
      return new GameCharacter {
        Name = Name,
        HitPoints = HitPoints,
        Position = GameMapPosition.CopyFrom(Position),
      };
    }

    public void MoveTo(GameMapPosition position) {
      Position = GameMapPosition.CopyFrom(position);
    }
  }
}
