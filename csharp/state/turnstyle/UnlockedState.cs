namespace Turnstyle
{
  public class UnlockedState : State
  {
    public override void Coin(Machine machine)
    {
    }

    public override void Pass(Machine machine)
    {
      machine.Lock();
    }
  }
}
