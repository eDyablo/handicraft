using NUnit.Framework;

namespace Marsrover
{
  public class MissionTest
  {
    [Test]
    public void Exploration_without_a_plan_gives_no_result()
    {
      var mission = new Mission();
      mission.Explore();
      Assert.IsEmpty(mission.Result);
    }
  }
}
