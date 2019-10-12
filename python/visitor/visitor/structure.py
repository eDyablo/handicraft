class Infrastructure:
  def __init__(self):
    self.components = []

  def AddComponent(self, component):
    self.components.append(component)

  def Visit(self, visitor):
    for component in self.components:
      component.AcceptVisitor(visitor)


class Repository:
  def __init__(self, name):
    self.name = name

  def AcceptVisitor(self, visitor):
    visitor.VisitRepository(self)


class SourceRepository(Repository):
  def __init__(self, name):
    super().__init__(name)

  def AcceptVisitor(self, visitor):
    visitor.VisitSourceRepository(self)


class ArtifactRepository(Repository):
  def __init__(self, name):
    super().__init__(name)
    self.artifacts = []

  def PublishArtifact(self, name, size):
    package = (name, size)
    artifacts.append(package)

  def AcceptVisitor(self, visitor):
    visitor.VisitArtifactRepository(self)
