namespace prototype.Game
{
  public class GameCharacter : GameObject {
    public string Name { get; set; }

    public GameCharacter() {
      Position = new GameMapPosition();
    }

    public override GameObject Clone() {
      return new GameCharacter {
        Name = Name,
        Position = new GameMapPosition(),
      };
    }
  }
}
