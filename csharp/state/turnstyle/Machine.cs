namespace Turnstyle
{
  public class Machine
  {
    State state;

    public void SetState(State newState)
    {
      state = newState;
    }

    public virtual void Unlock()
    {
    }

    public virtual void Alarm()
    {
    }

    public virtual void Lock()
    {
    }

    public void Coin() => state.Coin(this);

    public void Pass() => state.Pass(this);
  }
}
