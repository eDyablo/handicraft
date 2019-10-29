using System.Collections.Generic;

namespace Marsrover
{
  public class Mission
  {
    private List<string> result = new List<string>();

    public string[] Plan { private get; set; }

    public RangeType Range { get; private set; }

    public IEnumerable<string> Result { get => result; }

    private Rover rover;

    public struct RangeType
    {
      public int X { get; set; }
      public int Y { get; set; }
    }

    public struct Rover
    {
      public int X { get; set; }

      public int Y { get; set; }

      public char Direction { get; set; }
    }

    public void Explore()
    {
      if (Plan != null && Plan.Length > 0)
      {
        ReadRange();
        if (Plan.Length > 1)
        {
          LandRover();
          if (Plan.Length > 2)
          {
            CommandRover();
          }
          ReportRover();
        }
      }
    }

    private void ReadRange()
    {
      var fields = Plan[0].Split(" ", 2);
      Range = new RangeType
      {
        X = int.Parse(fields[0]),
        Y = int.Parse(fields[1]),
      };
    }

    private void LandRover()
    {
      var fields = Plan[1].Split(" ", 3);
      rover = new Rover {
        X = int.Parse(fields[0]),
        Y = int.Parse(fields[1]),
        Direction = fields[2][0],
      };
    }

    private void CommandRover()
    {
      foreach (var command in Plan[2])
      {
        CommandRover(command);
      }
    }

    private void CommandRover(char command)
    {
      switch (command)
      {
        case 'R': SpinRoverRight(); break;
        case 'L': SpinRoverLeft(); break;
        case 'M': MoveRover(); break;
      }
    }

    private void MoveRover()
    {
      switch (rover.Direction)
      {
        case 'E': rover.X++; break;
        case 'W': rover.X--; break;
        case 'N': rover.Y++; break;
        case 'S': rover.Y--; break;
      }
    }

    private void SpinRoverRight()
    {
      switch (rover.Direction)
      {
        case 'N': rover.Direction = 'E'; break;
        case 'E': rover.Direction = 'S'; break;
        case 'S': rover.Direction = 'W'; break;
        case 'W': rover.Direction = 'N'; break;
      }
    }

    private void SpinRoverLeft()
    {
      switch (rover.Direction)
      {
        case 'N': rover.Direction = 'W'; break;
        case 'W': rover.Direction = 'S'; break;
        case 'S': rover.Direction = 'E'; break;
        case 'E': rover.Direction = 'N'; break;
      }
    }

    private void ReportRover()
    {
      result.Add($"{ rover.X } { rover.Y } { rover.Direction }");
    }
  }
}
