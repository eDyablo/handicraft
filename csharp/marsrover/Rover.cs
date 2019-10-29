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
      var fields = text.Split(" ", 3);
      return new Rover
      {
        X = int.Parse(fields[0]),
        Y = int.Parse(fields[1]),
        Direction = fields[2][0],
      };
    }
  }
}
