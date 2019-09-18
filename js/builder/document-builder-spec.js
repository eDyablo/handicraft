'use strict';

const DocumentBuilder = require('./document-builder');

describe('document builder', () => {
  it('constructor should throw', () => {
    expect(function() { new DocumentBuilder() }).toThrow();
  });
});

describe('document builder inherited class', () => {
  class TheBuilder extends DocumentBuilder {}

  const methodMustBeImplemented = new Error('the method must be implemented');

  var builder;

  beforeEach(() => {
    builder = new TheBuilder();
  });

  it('must implement build paragraph method', () => {
    expect(function() { builder.buildParagraph() })
      .toThrow(methodMustBeImplemented);
  });

  it('must implement build heading method', () => {
    expect(function() { builder.buildHeading() })
      .toThrow(methodMustBeImplemented);
  });
});
