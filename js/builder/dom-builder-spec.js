'use strict';

const DomBuilder = require('./dom-builder')

describe('dom builder', () => {
  var builder;

  beforeEach(() => {
    builder = new DomBuilder();
  });

  it('build paragraph adds paragraph element to dom',  () => {
    builder.buildParagraph('paragraph');
    const dom = builder.getDom();
    expect(dom.body.getElementsByTagName('p')[0].textContent)
      .toEqual('paragraph');
  });

  it('build paragraph does not add paragraph element for empty text', () => {
    builder.buildParagraph('');
    const dom = builder.getDom();
    expect(dom.body.getElementsByTagName('p').length).toEqual(0);
  });

  it('build heading adds heading element to dom', () => {
    builder.buildHeading('heading');
    const dom = builder.getDom();
    expect(dom.body.getElementsByTagName('h1')[0].textContent)
      .toEqual('heading');
  });
});
