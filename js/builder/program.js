const MarkdownReader = require('./markdown-reader')
const DomBuilder = require('./dom-builder')
const TextBuilder = require('./text-builder');

const markdown = `
# greeting

hello world
i am a js code

# farewell

good bye
`

function toDom(markdown) {
  const builder = new DomBuilder();
  const reader = new MarkdownReader(builder);
  reader.read(markdown)
  return builder.getDom().body.innerHTML;
}

function toText(markdown) {
  const builder = new TextBuilder();
  const reader = new MarkdownReader(builder);
  reader.read(markdown)
  return builder.getText();
}

console.log('DOM\n');
console.log(toDom(markdown));

console.log('\ntext\n');
console.log(toText(markdown));
