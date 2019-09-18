'use strict';

const HtmlBuilder = require('./html-builder.js');

describe('html builder', () => {
  var builder;
  
  beforeEach(() => {
    builder = new HtmlBuilder();
  });

  it('build paragraph adds paragraph', () => {
    builder.buildParagraph('paragraph');
    expect(builder.getHtml()).toContain('<p>paragraph</p>');
  })

  it('build heading adds heading', () => {
    builder.buildHeading('heading');
    expect(builder.getHtml()).toContain('<h1>heading</h1>');
  });
});
