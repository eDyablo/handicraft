namespace Turnstyle
{
  public abstract class State
  {
    public abstract void Coin(Machine machine);

    public abstract void Pass(Machine machine);
  }
}
