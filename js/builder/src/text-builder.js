'use strict';

const DocumentBuilder = require('./document-builder');

module.exports = class TextBuilder extends DocumentBuilder {
  constructor() {
    super();
    this.text = ''
  }

  buildParagraph(text) {
    if (text) {
      this.text += text + '\n';
    }
  }

  buildHeading(text) {
    if (text) {
      this.text += text + '\n'
        + '='.repeat(text.length) + '\n';
    }
  }

  getText() {
    return this.text
  }
}
