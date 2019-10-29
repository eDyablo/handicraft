using System.Collections.Generic;

namespace Marsrover
{
  public class Mission
  {
    private List<string> result = new List<string>();

    public string[] Plan { private get; set; }

    public Range Range { get; private set; }

    public IEnumerable<string> Result { get => result; }

    private Rover rover;

    public const char LEFT = 'L';
    public const char RIGHT = 'R';
    public const char MOVE = 'M';

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
      Range = new Range
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
        case RIGHT: SpinRoverRight(); break;
        case LEFT: SpinRoverLeft(); break;
        case MOVE: MoveRover(); break;
      }
    }

    private void MoveRover()
    {
      switch (rover.Direction)
      {
        case Direction.EAST: rover.X++; break;
        case Direction.WEST: rover.X--; break;
        case Direction.NORTH: rover.Y++; break;
        case Direction.SOUTH: rover.Y--; break;
      }
    }

    private void SpinRoverRight()
    {
      switch (rover.Direction)
      {
        case Direction.NORTH: rover.Direction = Direction.EAST; break;
        case Direction.EAST: rover.Direction = Direction.SOUTH; break;
        case Direction.SOUTH: rover.Direction = Direction.WEST; break;
        case Direction.WEST: rover.Direction = Direction.NORTH; break;
      }
    }

    private void SpinRoverLeft()
    {
      switch (rover.Direction)
      {
        case Direction.NORTH: rover.Direction = Direction.WEST; break;
        case Direction.WEST: rover.Direction = Direction.SOUTH; break;
        case Direction.SOUTH: rover.Direction = Direction.EAST; break;
        case Direction.EAST: rover.Direction = Direction.NORTH; break;
      }
    }

    private void ReportRover()
    {
      result.Add($"{ rover.X } { rover.Y } { rover.Direction }");
    }
  }
}
