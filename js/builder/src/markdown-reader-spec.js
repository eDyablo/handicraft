'use strict';

const MarkdownTranslator = require('./markdown-reader');
const DocumentBuilder = require('./document-builder');

describe('markdown translator', () => {
  class BuilderStub extends DocumentBuilder {}

  var builder, translator;

  beforeEach(() => {
    builder = new BuilderStub();
    translator = new MarkdownTranslator(builder);
  });

  it('does not build paragraph for empty input', () => {
    spyOn(builder, 'buildParagraph');
    translator.translate('');
    expect(builder.buildParagraph).not.toHaveBeenCalled();
  });

  it('builds paragraph for one line input', () => {
    spyOn(builder, 'buildParagraph');
    translator.translate('line');
    expect(builder.buildParagraph).toHaveBeenCalledWith('line');
  });

  it('builds paragraph for each line in input', () => {
    spyOn(builder, 'buildParagraph');
    translator.translate('first\nsecond\n');
    expect(builder.buildParagraph).toHaveBeenCalledWith('first');
    expect(builder.buildParagraph).toHaveBeenCalledWith('second');
  });

  it('builds heading for line that starts with "# "', () => {
    spyOn(builder, 'buildHeading');
    translator.translate('# heading');
    expect(builder.buildHeading).toHaveBeenCalledWith('heading');
  });
});
