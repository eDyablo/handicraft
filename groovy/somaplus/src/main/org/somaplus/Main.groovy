package org.somaplus

import org.somaplus.actor.*
import org.somaplus.domain.*
import org.somaplus.console.*

class Main {
  static main(args) {
    final domainActors = new ActorSystem(
      'domain',
      CardsManagerActor,
      ConsoleOperatorActor,
    )
    domainActors.send(new AskOperatorMessage(
      question: 'who are you?'
    ))
    domainActors.dispatch()
  }
}
