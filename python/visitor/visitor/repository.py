class Repository:
  def __init__(self, name):
    self.name = name


class SourceRepository(Repository):
  def __init__(self, name):
    super().__init__(name)

  def list_revisions(self):
    return []

  def accept_visitor(self, visitor):
    visitor.visit_source_repository(self)


class ArtifactRepository(Repository):
  def __init__(self, name):
    super().__init__(name)

  def list_artifacts(self):
    return []

  def accept_visitor(self, visitor):
    visitor.visit_artifact_repository(self)
