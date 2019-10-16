from repository import ArtifactRepository

demo_artifacts = [
  ("first",   "v1",     1554080400),
  ("first",   "v1.1",   1546304400),
  ("first",   "v1.3",   1562717400),
  ("second",  "v1.0.0", 1556672400),
  ("second",  "v1.0.1", 1548982800),
  ("second",  "v1.1",   1565395800),
  ("third",   "v1.1.1", 1559350800),
  ("third",   "v1.2.3", 1551402000),
  ("third",   "v2.0.1", 1568074200),
]

class NexusRepository(ArtifactRepository):
  def list_artifacts(self):
    return demo_artifacts
