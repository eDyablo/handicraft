'use strict';

const MarkdownTranslator = require('./markdown-translator');
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
  const translator = new MarkdownTranslator(builder);
  translator.translate(markdown);
  return builder.getDom().body.innerHTML;
}

function toText(markdown) {
  const builder = new TextBuilder();
  const translator = new MarkdownTranslator(builder);
  translator.translate(markdown);
  return builder.getText();
}

function toHtml(markdown) {
  const builder = new HtmlBuilder();
  const translator = new MarkdownTranslator(builder);
  translator.translate(markdown);
  return builder.getHtml();
}

console.log('markdown to DOM\n');
console.log(toDom(markdown));

console.log('\nmarkdown to text\n');
console.log(toText(markdown));

console.log('\nmarkdown to HTML\n');
console.log(toHtml(markdown));
