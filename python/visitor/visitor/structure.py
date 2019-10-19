class Infrastructure:
  def __init__(self):
    self.components = []

  def add_component(self, component):
    self.components.append(component)

  def accept_visitor(self, visitor):
    for component in self.components:
      component.accept_visitor(visitor)
