namespace Turnstyle
{
  public class Machine
  {
    private const bool ON  = true;

    private const bool OFF = false;

    public State State { get; internal set; }

    public bool GreenLightbulb { get; private set; }

    public bool RedLightbulb { get; private set; }

    public bool Latch { get; private set; }

    public virtual void Unlock()
    {
      GreenLightbulb = ON;
      RedLightbulb = OFF;
      Latch = OFF;
    }

    public virtual void Alarm()
    {
      RedLightbulb = ON;
      Latch = ON;
    }

    public virtual void Lock()
    {
      RedLightbulb = ON;
      GreenLightbulb = OFF;
      Latch = ON;
    }

    public void Coin() => State.Coin(this);

    public void Pass() => State.Pass(this);
  }
}
