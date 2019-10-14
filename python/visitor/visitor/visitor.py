class RepositoryAuditor:
  def __init__(self):
    self.source_repository_number = 0
    self.artifact_repository_number = 0

  def VisitSourceRepository(self, repository):
    self.source_repository_number += 1

  def VisitArtifactRepository(self, repository):
    self.artifact_repository_number += 1


class SourceAnalyzer:
  def VisitSourceRepository(self, repository):
    pass

  def VisitArtifactRepository(self, repository):
    pass
