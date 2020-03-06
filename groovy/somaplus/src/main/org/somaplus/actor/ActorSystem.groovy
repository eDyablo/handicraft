package org.somaplus.actor

import java.util.concurrent.LinkedBlockingQueue

class ActorSystem {
  final String id
  final List<Actor> actors = []
  final Queue messageQueue = new LinkedBlockingQueue()

  ActorSystem(String id, Class[] actorTypes) {
    this.id = id
    actorTypes.collect(actors) {
      it.newInstance(this)
    }
  }

  void send(Object[] messages) {
    messages.each {
      messageQueue.add(it)
    }
  }

  void dispatch(Object[] messages) {
    send(messages)
    while(messageQueue.size()) {
      actors*.send(messageQueue.poll())
    }
  }
}
