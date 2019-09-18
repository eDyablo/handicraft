'use strict';

const MarkdownReader = require('./markdown-reader');
const DocumentBuilder = require('./document-builder');

describe('markdown reader', () => {
  class BuilderStub extends DocumentBuilder {}

  var builder, reader;

  beforeEach(() => {
    builder = new BuilderStub();
    reader = new MarkdownReader(builder);
  });

  it('does not build paragraph for empty input', () => {
    spyOn(builder, 'buildParagraph');
    reader.read('');
    expect(builder.buildParagraph).not.toHaveBeenCalled();
  });

  it('builds paragraph for one line input', () => {
    spyOn(builder, 'buildParagraph');
    reader.read('line');
    expect(builder.buildParagraph).toHaveBeenCalledWith('line');
  });

  it('builds paragraph for each line in input', () => {
    spyOn(builder, 'buildParagraph');
    reader.read('first\nsecond\n');
    expect(builder.buildParagraph).toHaveBeenCalledWith('first');
    expect(builder.buildParagraph).toHaveBeenCalledWith('second');
  });

  it('builds heading for line that strarts with "# "', () => {
    spyOn(builder, 'buildHeading');
    reader.read('# heading');
    expect(builder.buildHeading).toHaveBeenCalledWith('heading');
  });
});
