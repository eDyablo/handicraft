'use strict';

const DocumentBuilder = require('./document-builder');

const { JSDOM } = require("jsdom");

module.exports = class DomBuilder extends DocumentBuilder {
  constructor() {
    super();
    this.dom = new JSDOM(``, {
      contentType: 'text/html'
    });
    this.document = this.dom.window.document;
  }

  buildParagraph(text) {
    if (text) {
      const paragraph = this.document.createElement("p");
      paragraph.textContent = text;
      this.document.body.appendChild(paragraph);
    }
  }

  buildHeading(text) {
    if (text) {
      const heading = this.document.createElement("h1");
      heading.textContent = text;
      this.document.body.appendChild(heading);
    }
  }

  getDom() {
    return this.document;
  }
}
