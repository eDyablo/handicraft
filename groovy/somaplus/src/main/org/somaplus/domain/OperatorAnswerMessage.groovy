package org.somaplus.domain

import groovy.transform.MapConstructor

@MapConstructor
class OperatorAnswerMessage {
  final String question
  final String answer
}
