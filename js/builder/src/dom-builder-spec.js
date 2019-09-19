'use strict';

const DomBuilder = require('./dom-builder');

describe('dom builder', () => {
  var builder;

  beforeEach(() => {
    builder = new DomBuilder();
  });

  it('adds paragraph element to dom',  () => {
    builder.buildParagraph('paragraph');
    const dom = builder.getDom();
    expect(dom.body.getElementsByTagName('p')[0].textContent)
      .toEqual('paragraph');
  });

  it('does not add paragraph element when its text is empty', () => {
    builder.buildParagraph('');
    const dom = builder.getDom();
    expect(dom.body.getElementsByTagName('p').length).toEqual(0);
  });

  it('adds heading element to dom', () => {
    builder.buildHeading('heading');
    const dom = builder.getDom();
    expect(dom.body.getElementsByTagName('h1')[0].textContent)
      .toEqual('heading');
  });

  it('does not add heading element when its text is empty', () => {
    builder.buildHeading();
    builder.buildHeading('');
    const dom = builder.getDom();
    expect(dom.body.getElementsByTagName('h1').length).toEqual(0);
  });
});
