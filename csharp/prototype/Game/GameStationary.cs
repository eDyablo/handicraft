namespace prototype.Game
{
  class GameStationary : GameObject {
    public int Durability { get; set; }

    public override GameObject Clone() {
      return new GameStationary {
        Durability = Durability
      };
    }
  }
}
