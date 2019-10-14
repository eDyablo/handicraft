class Repository:
  def __init__(self, name):
    self.name = name


class SourceRepository(Repository):
  def __init__(self, name):
    super().__init__(name)

  def AcceptVisitor(self, visitor):
    visitor.VisitSourceRepository(self)


class ArtifactRepository(Repository):
  def __init__(self, name):
    super().__init__(name)

  def ListArtifacts(self):
    return []

  def AcceptVisitor(self, visitor):
    visitor.VisitArtifactRepository(self)
