namespace prototype.Game
{
  public abstract class GameObject {
    public GameMapPosition Position { get; protected set; }

    public abstract GameObject Clone();
  }
}
