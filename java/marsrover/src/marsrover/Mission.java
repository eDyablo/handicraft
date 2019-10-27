package marsrover;

public class Mission {
  public int xRange;
  public int yRange;

	public String[] explore(String[] plan) {
    if (plan.length > 0) {
      String[] range = plan[0].split(" ");
      xRange = Integer.parseInt(range[0]);
      yRange = Integer.parseInt(range[1]);
      if (plan.length > 1) {
        return new String[] {
          plan[1],
        };
      }
    }
    return new String[]{};
	}
}
