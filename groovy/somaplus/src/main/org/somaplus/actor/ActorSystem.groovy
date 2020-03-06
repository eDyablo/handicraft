package org.somaplus.actor

class ActorSystem {
  final String id
  final List<Actor> actors = []

  ActorSystem(String id, Class[] actorTypes) {
    this.id = id
    actorTypes.collect(actors) {
      it.newInstance(this)
    }
  }

  void send(Object[] messages) {
    actors*.send(messages)
  }
}
