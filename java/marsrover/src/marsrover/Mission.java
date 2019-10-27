package marsrover;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Iterator;
import java.util.List;

public class Mission {
  public int xRange;
  public int yRange;
  public String[] plan;
  public List<String> result = new ArrayList<String>();
  private String[] rover;

	public void explore() {
    Iterator<String> record = Arrays.asList(plan).iterator();
    if (record.hasNext()) {
      determineRange(record.next());
    }
    while (record.hasNext()) {
      landRover(record.next());
      if (record.hasNext()) {
        commandRover(record.next());
      }
      reportRover();
    }
  }

  private void landRover(String record) {
    rover = record.split(" ");
  }

  private void reportRover() {
    result.add(String.join(" ", rover));
  }
  
  private void determineRange(String record) {
    String[] range = record.split(" ");
    xRange = Integer.parseInt(range[0]);
    yRange = Integer.parseInt(range[1]);
  }

  private void commandRover(String record) {
    for (Character command : record.toCharArray()) {
      commandRover(command);
    }
  }

  private void commandRover(Character command) {
    if (command == 'L') {
      spinRoverLeft();
    }
    if (command == 'R') {
      spinRoverRight();
    }
    if (command == 'M') {
      moveRover();
    }
  }

  private void spinRoverLeft() {
    if (rover[2].equals("N")) {
      rover[2] = "W";
    } else if (rover[2].equals("W")) {
      rover[2] = "S";
    } else if (rover[2].equals("S")) {
      rover[2] = "E";
    } else if (rover[2].equals("E")) {
      rover[2] = "N";
    }
  }

  private void spinRoverRight() {
    if (rover[2].equals("N")) {
      rover[2] = "E";
    } else if (rover[2].equals("E")) {
      rover[2] = "S";
    } else if (rover[2].equals("S")) {
      rover[2] = "W";
    } else if (rover[2].equals("W")) {
      rover[2] = "N";
    }
  }

  private void moveRover() {
    int x = Integer.parseInt(rover[0]);
    int y = Integer.parseInt(rover[1]);
    if (rover[2].equals("N")) {
      ++y;
    } else if (rover[2].equals("S")) {
      --y;
    } else if (rover[2].equals("E")) {
      ++x;
    } else if (rover[2].equals("W")) {
      --x;
    }
    rover[0] = String.valueOf(x);
    rover[1] = String.valueOf(y);
  }
}
