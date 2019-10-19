namespace Turnstyle
{
  public class Machine
  {
    public State State;

    public virtual void Unlock()
    {
    }

    public virtual void Alarm()
    {
    }

    public virtual void Lock()
    {
    }

    public void Coin() => State.Coin(this);

    public void Pass() => State.Pass(this);
  }
}
