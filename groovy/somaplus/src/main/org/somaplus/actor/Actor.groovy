package org.somaplus.actor

class Actor {
  final ActorSystem system
  final List<Class> messageTypes = []

  Actor(ActorSystem system) {
    this.system = system
  }

  void receive(Class[] messageTypes) {
    messageTypes.collect(this.messageTypes) { it }
  }

  void send(Object[] messages) {
    messages.findAll {
      it.class in messageTypes
    }.each {
      handle(it)
    }
  }

  void handle(message) {
    "handle${ message.class.simpleName }"(message)
  }
}
