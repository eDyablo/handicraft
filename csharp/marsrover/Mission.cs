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

    public const char NORTH = 'N';
    public const char SOUTH = 'S';
    public const char EAST = 'E';
    public const char WEST = 'W';

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
        case EAST: rover.X++; break;
        case WEST: rover.X--; break;
        case NORTH: rover.Y++; break;
        case SOUTH: rover.Y--; break;
      }
    }

    private void SpinRoverRight()
    {
      switch (rover.Direction)
      {
        case NORTH: rover.Direction = EAST; break;
        case EAST: rover.Direction = SOUTH; break;
        case SOUTH: rover.Direction = WEST; break;
        case WEST: rover.Direction = NORTH; break;
      }
    }

    private void SpinRoverLeft()
    {
      switch (rover.Direction)
      {
        case NORTH: rover.Direction = WEST; break;
        case WEST: rover.Direction = SOUTH; break;
        case SOUTH: rover.Direction = EAST; break;
        case EAST: rover.Direction = NORTH; break;
      }
    }

    private void ReportRover()
    {
      result.Add($"{ rover.X } { rover.Y } { rover.Direction }");
    }
  }
}
