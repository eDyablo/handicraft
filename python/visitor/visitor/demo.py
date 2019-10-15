from structure import Infrastructure
from visitor import RepositoryAuditor, SourceAnalyzer, SourceSynchronizer, ArtifactRetirement
from nexus import NexusRepository
from github import GithubRepository, GithubArtifactRepository


class Demo:
  def __init__(self):
    self.infra = Infrastructure()
    self.auditor = RepositoryAuditor()
    self.analyzer = SourceAnalyzer()
    self.synchronizer = SourceSynchronizer()
    self.retirement = ArtifactRetirement()

  def run(self):
    self.load()
    self.analyze()
    self.report()

  def load(self):
    self.infra.add_component(GithubRepository("core"))
    self.infra.add_component(GithubRepository("config"))
    self.infra.add_component(GithubArtifactRepository("docker"))
    self.infra.add_component(NexusRepository("debug-pypi"))
    self.infra.add_component(GithubArtifactRepository("pypi"))
    self.infra.add_component(NexusRepository("debug-nuget"))
    self.infra.add_component(GithubArtifactRepository("nuget"))

  def analyze(self):
    self.infra.accept_visitor(self.auditor)
    self.infra.accept_visitor(self.analyzer)
    self.infra.accept_visitor(self.synchronizer)
    self.infra.accept_visitor(self.retirement)

  def report(self):
    print("source repositories:\t", self.auditor.source_repository_number)
    print("artifact repositories:\t", self.auditor.artifact_repository_number)
