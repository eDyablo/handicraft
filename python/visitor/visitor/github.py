from repository import ArtifactRepository, SourceRepository

class GithubRepository(SourceRepository):
  def sync(self):
    pass


class GithubArtifactRepository(ArtifactRepository):
  def retire_artifacts(self):
    pass
