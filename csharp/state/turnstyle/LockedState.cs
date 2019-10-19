namespace Turnstyle
{
  public class LockedState : State
  {
    public override void Coin(Machine machine)
    {
      machine.Unlock();
      machine.State = new UnlockedState();
    }

    public override void Pass(Machine machine)
    {
      machine.Alarm();
    }
  }
}
