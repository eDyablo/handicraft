package org.somaplus.domain

import org.somaplus.actor.*

class CardsManagerActor extends Actor {
  CardsManagerActor(ActorSystem system) {
    super(system)
    receive(RegisterCardMessage)
  }

  void handleRegisterCardMessage(message) {
  }
}
