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

    [Test]
    public void Reads_exploration_range_from_the_plan()
    {
      var mission = new Mission();
      mission.Plan = new string[] {
        "1 2",
      };
      mission.Explore();
      Assert.AreEqual(1, mission.Range.X);
      Assert.AreEqual(2, mission.Range.Y);
    }
  }
}
