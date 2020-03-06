package org.somaplus.domain

import groovy.transform.MapConstructor

@MapConstructor
class AskCommandMessage {
  final String prompt = '>'
}
