package org.somaplus.domain

import org.somaplus.actor.*

class CommandControllerActor extends Actor {
  CommandControllerActor(ActorSystem system) {
    super(system)
    receive(CommandEnteredMessage)
  }

  void handleCommandEnteredMessage(message) {
    if (message.command != 'quit') {
      system.send(new AskCommandMessage())
    }
  }
}
