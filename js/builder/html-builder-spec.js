'use strict';

const HtmlBuilder = require('./html-builder');

describe('html builder', () => {
  var builder;
  
  beforeEach(() => {
    builder = new HtmlBuilder();
  });

  it('adds paragraph to html', () => {
    builder.buildParagraph('paragraph');
    expect(builder.getHtml()).toContain('<p>paragraph</p>');
  })

  it('adds heading to html', () => {
    builder.buildHeading('heading');
    expect(builder.getHtml()).toContain('<h1>heading</h1>');
  });

  it('does not add paragraph when its text is empty', () => {
    builder.buildParagraph('');
    expect(builder.getHtml()).toEqual('');
  });

  it('does not add heading when its text is empty', () => {
    builder.buildHeading('');
    expect(builder.getHtml()).toEqual('');
  });
});
