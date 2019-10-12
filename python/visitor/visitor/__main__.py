from structure import Infrastructure
from visitors import RepositoryAuditor, SourceAnalyzer
from nexus import NexusRepository
from github import GithubRepository, GithubArtifactRepository

def load():
  infra = Infrastructure()
  infra.AddComponent(GithubRepository("core"))
  infra.AddComponent(GithubRepository("config"))
  infra.AddComponent(GithubArtifactRepository("docker"))
  infra.AddComponent(NexusRepository("debug-pypi"))
  infra.AddComponent(GithubArtifactRepository("pypi"))
  infra.AddComponent(NexusRepository("debug-nuget"))
  infra.AddComponent(GithubArtifactRepository("nuget"))
  return infra

def analyse(infra):
  auditor = RepositoryAuditor()
  analyzer = SourceAnalyzer()
  infra.Visit(auditor)
  infra.Visit(analyzer)

def main():
  analyse(load())

if __name__ == "__main__":
  main()
