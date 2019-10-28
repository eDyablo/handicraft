using NUnit.Framework;

namespace Marsrover
{
  public class MissionTest
  {
    Mission mission = new Mission();

    [Test]
    public void Exploration_without_a_plan_gives_no_result()
    {
      mission.Explore();
      Assert.IsEmpty(mission.Result);
    }

    [Test]
    public void Reads_exploration_range_from_the_plan()
    {
      mission.Plan = new string[] {
        "1 2",
      };
      mission.Explore();
      Assert.AreEqual(1, mission.Range.X);
      Assert.AreEqual(2, mission.Range.Y);
    }

    [Test]
    public void Lands_rover_with_coordinates_and_direction_according_to_the_plan()
    {
      mission.Plan = new string[] {
        "1 2",
        "1 2 N",
      };
      mission.Explore();
      Assert.AreEqual(new [] { "1 2 N" }, mission.Result);
    }
  }
}
