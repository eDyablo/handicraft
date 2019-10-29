using System.Collections.Generic;

namespace Marsrover
{
  public class Mission
  {
    private Rover rover;
    private List<string> result = new List<string>();

    public string[] Plan { private get; set; }

    public Range Range { get; private set; }

    public IEnumerable<string> Result { get => result; }

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
      Range = Plan[0].ToRange();
    }

    private void LandRover()
    {
      rover = Plan[1].ToRover();
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
        case Command.RIGHT: SpinRoverRight(); break;
        case Command.LEFT: SpinRoverLeft(); break;
        case Command.MOVE: MoveRover(); break;
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
