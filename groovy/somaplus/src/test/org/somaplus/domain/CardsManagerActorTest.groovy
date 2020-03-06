package org.somaplus.domain

import org.somaplus.actor.*
import org.junit.*
import static org.hamcrest.MatcherAssert.*
import static org.hamcrest.Matchers.*
import static org.mockito.hamcrest.MockitoHamcrest.*
import static org.mockito.Mockito.*

class CardsManagerActorTest {
  final system = spy(new ActorSystem('test'))
  final actor = new CardsManagerActor(system)

  @Test void handle_register_card_message() {
    actor.handleRegisterCardMessage(new RegisterCardMessage())
  }
}
