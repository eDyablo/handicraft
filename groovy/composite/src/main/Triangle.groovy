package composite

class Triangle extends Shape {
  float[][] points

  List<Shape> explode() {
    [
      new Line(start: points[0], end: points[1]),
      new Line(start: points[0], end: points[2]),
      new Line(start: points[1], end: points[2]),
    ]
  }
}
