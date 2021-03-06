'use strict';

const DocumentBuilder = require('./document-builder');

module.exports = class HtmlBuilder extends DocumentBuilder {
  constructor() {
    super();
    this.text = '';
  }

  buildParagraph(text) {
    if (text) {
      this.text += '<p>' + text + '</p>';
    }
  }

  buildHeading(text) {
    if (text) {
      this.text += '<h1>' + text + '</h1>';
    }
  }

  getHtml() {
    return this.text;
  }
}
