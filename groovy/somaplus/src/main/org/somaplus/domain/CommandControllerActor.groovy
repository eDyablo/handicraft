package org.somaplus.domain

import org.somaplus.actor.*

class CommandControllerActor extends Actor {
  CommandControllerActor(ActorSystem system) {
    super(system)
    receive(CommandEnteredMessage)
  }

  void handleCommandEnteredMessage(message) {
    switch(message.command) {
      case 'help':
      system.send(new DisplayTextMessage(text: '''\
      Commands:
        help    Display help information
        quit    Exit the application
      '''.stripIndent().trim()))
      break
    }
    if (message.command != 'quit') {
      system.send(new AskCommandMessage())
    }
  }
}
