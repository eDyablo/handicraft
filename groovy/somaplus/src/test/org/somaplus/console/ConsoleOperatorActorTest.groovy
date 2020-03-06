package org.somaplus.console

import org.somaplus.actor.*
import org.somaplus.domain.*
import org.junit.*
import static org.hamcrest.MatcherAssert.*
import static org.hamcrest.Matchers.*
import static org.mockito.hamcrest.MockitoHamcrest.*
import static org.mockito.Mockito.*

class ConsoleOperatorActorTest {
  final system = spy(new ActorSystem('test'))
  final actor = spy(new ConsoleOperatorActor(system))

  @Test void handle_ask_operator_message() {
    final output = new ByteArrayOutputStream()
    doReturn(new PrintStream(output)).when(actor).output
    doReturn(new StringBufferInputStream('answer')).when(actor).input
    actor.handleAskOperatorMessage(new AskOperatorMessage(question: 'question'))
    assertThat(output.toString(), is(equalTo('question ')))
  }
}
