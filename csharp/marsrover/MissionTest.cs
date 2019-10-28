using NUnit.Framework;

namespace Marsrover
{
  public class MissionTest
  {
    Mission mission;

    [SetUp]
    public void BeforeEachTest()
    {
      mission = new Mission();
    }

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

    [Test]
    public void Plan_with_one_R_command_spins_north_rotated_rover_to_east()
    {
      mission.Plan = new string[] {
        "1 1",
        "0 0 N",
        "R",
      };
      mission.Explore();
      Assert.AreEqual(new [] { "0 0 E" }, mission.Result);
    }

    [Test]
    public void Plan_with_one_L_command_spins_north_rotated_rover_to_west()
    {
      mission.Plan = new string[] {
        "1 1",
        "0 0 N",
        "L",
      };
      mission.Explore();
      Assert.AreEqual(new [] { "0 0 W" }, mission.Result);
    }

    [Test]
    public void Plan_with_one_M_command_moves_east_oriented_rover_one_step_towards_east()
    {
      mission.Plan = new string[] {
        "1 1",
        "0 0 E",
        "M",
      };
      mission.Explore();
      Assert.AreEqual(new [] { "1 0 E"}, mission.Result);
    }

    [Test]
    public void Plan_with_R_and_M_commands_correctly_places_north_oriented_rover()
    {
      mission.Plan = new string[] {
        "1 1",
        "0 0 N",
        "RM",
      };
      mission.Explore();
      Assert.AreEqual(new string[] { "1 0 E" }, mission.Result);
    }

    [Test]
    public void Four_R_commands_do_full_rover_rotation()
    {
      mission.Plan = new string[] {
        "1 1",
        "0 0 N",
        "RRRR",
      };
      mission.Explore();
      Assert.AreEqual(new string[] { "0 0 N" }, mission.Result);
    }

    [Test]
    public void Four_L_commands_do_full_rover_rotation()
    {
      mission.Plan = new string[] {
        "1 1",
        "0 0 N",
        "LLLL",
      };
      mission.Explore();
      Assert.AreEqual(new string[] { "0 0 N" }, mission.Result);
    }

    [Test]
    public void Plan_with_one_M_command_moves_west_oriented_rover_one_step_towards_west()
    {
      mission.Plan = new string[] {
        "1 1",
        "1 0 W",
        "M",
      };
      mission.Explore();
      Assert.AreEqual(new [] { "0 0 W"}, mission.Result);
    }
  }
}
