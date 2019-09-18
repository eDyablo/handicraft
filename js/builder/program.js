'use strict';

const MarkdownReader = require('./markdown-reader');
const DomBuilder = require('./dom-builder');
const TextBuilder = require('./text-builder');
const HtmlBuilder = require('./html-builder');

const markdown = `
# greeting

hello world
i am a js code

# farewell

good bye
`;

function toDom(markdown) {
  const builder = new DomBuilder();
  const reader = new MarkdownReader(builder);
  reader.read(markdown);
  return builder.getDom().body.innerHTML;
}

function toText(markdown) {
  const builder = new TextBuilder();
  const reader = new MarkdownReader(builder);
  reader.read(markdown);
  return builder.getText();
}

function toHtml(markdown) {
  const builder = new HtmlBuilder();
  const reader = new MarkdownReader(builder);
  reader.read(markdown);
  return builder.getHtml();
}

console.log('DOM\n');
console.log(toDom(markdown));

console.log('\ntext\n');
console.log(toText(markdown));

console.log('\nHTML\n');
console.log(toHtml(markdown));
