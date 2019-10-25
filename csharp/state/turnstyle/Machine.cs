namespace Turnstyle
{
  public class Machine
  {
    public State State { get; internal set; }

    public Lightbulb GreenLightbulb { get; private set; }

    public Lightbulb RedLightbulb { get; private set; }

    public Latch Latch { get; private set; }

    public virtual void Unlock()
    {
      GreenLightbulb.Lit();
      RedLightbulb.TurnOff();
      Latch.Open();
    }

    public virtual void Alarm()
    {
      RedLightbulb.Lit();
      Latch.Close();
    }

    public virtual void Lock()
    {
      RedLightbulb.Lit();
      GreenLightbulb.TurnOff();
      Latch.Close();
    }

    public void Coin() => State.Coin(this);

    public void Pass() => State.Pass(this);
  }
}
