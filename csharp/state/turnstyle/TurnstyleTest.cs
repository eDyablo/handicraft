
using System.Collections.Generic;
using NUnit.Framework;

namespace Turnstyle
{
  public class TestableMachine : Machine
  {
    public IList<string> ActionsLog = new List<string>();

    public override void Unlock()
    {
      ActionsLog.Add("unlock");
    }

    public override void Alarm()
    {
      ActionsLog.Add("alarm");
    }

    public override void Lock()
    {
      ActionsLog.Add("lock");
    }
  }

  public class LockedMachine
  {
    TestableMachine Machine;

    [SetUp]
    public void BeforeEachTest()
    {
      Machine = new TestableMachine();
      Machine.State = new LockedState();
    }

    [Test]
    public void Gets_unlocked_by_a_coin()
    {
      Machine.Coin();
      Assert.That(Machine.ActionsLog, Is.EqualTo(new []{"unlock"}));
    }

    [Test]
    public void Sets_alarm_when_passed()
    {
      Machine.Pass();
      Assert.That(Machine.ActionsLog, Is.EqualTo(new []{"alarm"}));
    }

    [Test]
    public void Toogles_when_paid_and_passed()
    {
      Machine.Coin();
      Machine.Pass();
      Assert.That(Machine.ActionsLog, Is.EqualTo(new []{"unlock", "lock"}));
    }
  }

  public class UnlockedMachine
  {
    TestableMachine Machine;

    [SetUp]
    public void BeforeEachTest()
    {
      Machine = new TestableMachine();
      Machine.State = new UnlockedState();
    }

    [Test]
    public void Lockes_after_has_been_passed()
    {
      Machine.Pass();
      Assert.That(Machine.ActionsLog, Is.EqualTo(new []{"lock"}));
    }

    [Test]
    public void Does_not_allow_to_pass_twice()
    {
      Machine.Pass();
      Machine.Pass();
      Assert.That(Machine.ActionsLog, Is.EqualTo(new []{"lock", "alarm"}));
    }

    [Test]
    public void Does_nothing_for_a_coin()
    {
      Machine.Coin();
      Assert.That(Machine.ActionsLog, Is.Empty);
    }
  }
}
