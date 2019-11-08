package composite

class Complex extends Shape {
  final List<Shape> shapes = new ArrayList<Shape>()

  void add(Shape shape) {
    shapes << shape
  }

  List<Shape> explode() {
    shapes
  }
}
