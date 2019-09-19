'use strict';

const DocumentBuilder = require('./document-builder');

describe('document builder', () => {
  it('throws when instantiated directly', () => {
    expect(() => { new DocumentBuilder() }).toThrow();
  });

  it('does not throw when instantiated via inheritance', () => {
    class Inherited extends DocumentBuilder {}
    expect(() => { new Inherited() }).not.toThrow();
  })
});

describe('document builder inherited', () => {
  class InheritedBuilder extends DocumentBuilder {}

  const methodMustBeImplemented = new Error('the method must be implemented');

  var builder;

  beforeEach(() => {
    builder = new InheritedBuilder();
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
