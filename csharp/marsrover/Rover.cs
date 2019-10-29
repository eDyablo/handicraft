using System.Collections.Generic;

namespace Marsrover
{
  public struct Rover
  {
    public int X { get; set; }

    public int Y { get; set; }

    public char Direction { get; set; }
  }

  public static class RoverConvertion
  {
    public static Rover ToRover(this string text)
    {
      return ToRover(text.Split(" ", 3));
    }
    public static Rover ToRover(this IList<string> fields)
    {
      return new Rover
      {
        X = int.Parse(fields[0]),
        Y = int.Parse(fields[1]),
        Direction = fields[2][0],
      };
    }
  }
}
