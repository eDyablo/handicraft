'use strict';

const TextBuilder = require('./text-builder.js')

describe('text builder', () => {
  var builder

  beforeEach(() => {
    builder = new TextBuilder();
  });

  it('returns empty text when newly created', () => {
    expect(builder.getText()).toEqual('');
  });

  it('returns text containing paragraph for one line input', () => {
    builder.buildParagraph('paragraph');
    expect(builder.getText()).toEqual('paragraph\n');
  });

  it('returns empty text when paragraph is empty', () => {
    builder.buildParagraph('');
    expect(builder.getText()).toEqual('');
  });

  it('returns text with decorated heading', () => {
    builder.buildHeading('heading');
    expect(builder.getText()).toEqual([
      'heading',
      '=======',
      '',
    ].join('\n'));
  });
});
