class Infrastructure:
  def __init__(self):
    self.components = []

  def AddComponent(self, component):
    self.components.append(component)

  def AcceptVisitor(self, visitor):
    for component in self.components:
      component.AcceptVisitor(visitor)
