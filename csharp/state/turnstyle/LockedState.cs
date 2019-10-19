namespace Turnstyle
{
  public class LockedState : State
  {
    public override void Coin(Machine machine)
    {
      machine.Unlock();
      machine.SetState(new UnlockedState());
    }

    public override void Pass(Machine machine)
    {
      machine.Alarm();
    }
  }
}
