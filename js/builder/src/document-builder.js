'use strict';

module.exports = class DocumentBuilder {
  constructorError = new Error('the class is not intended to be instantiated');
  methodError = new Error('the method must be implemented');

  constructor() {
    if (this.constructor === DocumentBuilder) {
      throw this.constructorError;
    }
  }

  buildParagraph(text) {
    throw this.methodError;
  }

  buildHeading(text) {
    throw this.methodError;
  }
}
