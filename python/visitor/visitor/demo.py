from structure import Infrastructure
from visitor import RepositoryAuditor, SourceAnalyzer
from nexus import NexusRepository
from github import GithubRepository, GithubArtifactRepository


class Demo:
  def __init__(self):
    self.infra = Infrastructure()
    self.auditor = RepositoryAuditor()
    self.analyzer = SourceAnalyzer()

  def run(self):
    self.load()
    self.analyze()
    self.report()

  def load(self):
    self.infra.AddComponent(GithubRepository("core"))
    self.infra.AddComponent(GithubRepository("config"))
    self.infra.AddComponent(GithubArtifactRepository("docker"))
    self.infra.AddComponent(NexusRepository("debug-pypi"))
    self.infra.AddComponent(GithubArtifactRepository("pypi"))
    self.infra.AddComponent(NexusRepository("debug-nuget"))
    self.infra.AddComponent(GithubArtifactRepository("nuget"))

  def analyze(self):
    self.infra.AcceptVisitor(self.auditor)
    self.infra.AcceptVisitor(self.analyzer)

  def report(self):
    print("source repositories:\t", self.auditor.source_repository_number)
    print("artifact repositories:\t", self.auditor.artifact_repository_number)
