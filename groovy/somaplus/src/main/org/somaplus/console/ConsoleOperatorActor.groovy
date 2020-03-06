package org.somaplus.console

import org.somaplus.actor.*
import org.somaplus.domain.*

class ConsoleOperatorActor extends Actor {
  ConsoleOperatorActor(ActorSystem system) {
    super(system)
    receive(
      AskOperatorMessage,
      DisplayTextMessage,
    )
  }

  PrintStream getOutput() {
    System.out
  }

  InputStream getInput() {
    System.in
  }

  void handleAskOperatorMessage(message) {
    output.print(message.question + ' ')
    final answer = input.newReader().readLine()
    system.send(
      new OperatorAnswerMessage(
        question: message.question,
        answer: answer,
      ),
      new DisplayTextMessage(
        text: "hello " + answer
      ),
    )
  }

  void handleDisplayTextMessage(message) {
    System.out.println(message.text)
  }
}
