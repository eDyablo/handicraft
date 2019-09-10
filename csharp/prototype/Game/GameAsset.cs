using System.Collections.Generic;

namespace prototype.Game
{
  class GameAsset {
    readonly IDictionary<string, GameObject> prototypes =
      new Dictionary<string, GameObject>();

    public GameObject GetObjectPrototype(string key) {
      return prototypes[key];
    }

    public GameObject RegisterPrototype(string key, GameObject prototype) {
      prototypes[key] = prototype;
      return prototype;
    }
  }
}
