namespace Turnstyle
{
  public class Machine
  {
    public State State { get; internal set; }

    public bool GreenLightbulb { get; private set; }

    public bool RedLightbulb { get; private set; }

    public bool Latch { get; private set; }

    public virtual void Unlock()
    {
      GreenLightbulb = true;
      RedLightbulb = false;
      Latch = false;
    }

    public virtual void Alarm()
    {
      RedLightbulb = true;
      Latch = true;
    }

    public virtual void Lock()
    {
      RedLightbulb = true;
      GreenLightbulb = false;
      Latch = true;
    }

    public void Coin() => State.Coin(this);

    public void Pass() => State.Pass(this);
  }
}
