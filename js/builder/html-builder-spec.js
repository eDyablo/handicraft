'use strict';

const HtmlBuilder = require('./html-builder');

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

  it('does not add paragraph when input is empty', () => {
    builder.buildParagraph('');
    expect(builder.getHtml()).toEqual('');
  });

  it('does not add heading when its text is empty', () => {
    builder.buildHeading('');
    expect(builder.getHtml()).toEqual('');
  });
});
