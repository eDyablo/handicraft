package org.somaplus.console

import org.somaplus.actor.*
import org.somaplus.domain.*

class ConsoleOperatorActor extends Actor {
  ConsoleOperatorActor(ActorSystem system) {
    super(system)
    receive(
      AskCommandMessage,
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
    output.print("${ message.question } ")
    system.send(
      new OperatorAnswerMessage(
        question: message.question,
        answer: input.newReader().readLine(),
      )
    )
  }

  void handleDisplayTextMessage(message) {
    output.println(message.text)
  }

  void handleAskCommandMessage(message) {
    output.print("${ message.prompt } ")
    system.send(
      new CommandEnteredMessage(
        command: input.newReader().readLine()
      )
    )
  }
}
