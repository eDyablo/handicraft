namespace Turnstyle
{
  public class Machine
  {
    public State State;

    public bool GreenLightbulb { get; private set; }

    public bool RedLightbulb { get; private set; }

    public virtual void Unlock()
    {
      GreenLightbulb = true;
      RedLightbulb = false;
    }

    public virtual void Alarm()
    {
      RedLightbulb = true;
    }

    public virtual void Lock()
    {
      RedLightbulb = true;
      GreenLightbulb = false;
    }

    public void Coin() => State.Coin(this);

    public void Pass() => State.Pass(this);
  }
}
