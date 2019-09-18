const MarkdownReader = require('./markdown-reader.js')
const DomBuilder = require('./dom-builder.js')

const markdown = `
# greeting

hello world
i am a js code

# farewell

good bye
`

const builder = new DomBuilder();
const reader = new MarkdownReader(builder);
reader.read(markdown)
const document = builder.getDom();

console.log(document.body.innerHTML);
