class RepositoryAuditor:
  def __init__(self):
    self.source_repository_number = 0
    self.artifact_repository_number = 0
    self.artifact_number = 0

  def visit_source_repository(self, repository):
    self.source_repository_number += 1

  def visit_artifact_repository(self, repository):
    self.artifact_repository_number += 1
    self.artifact_number += len(repository.list_artifacts())


class SourceAnalyzer:
  def visit_source_repository(self, repository):
    revisions = repository.list_revisions()

  def visit_artifact_repository(self, repository):
    pass


class SourceSynchronizer:
  def visit_source_repository(self, repository):
    pass

  def visit_artifact_repository(self, repository):
    pass


class ArtifactRetirement:
  def visit_source_repository(self, repository):
    pass

  def visit_artifact_repository(self, repository):
    artifacts = repository.list_artifacts()
