'use strict';

const MailComposer = require('./mail-composer')
const TextBuilder = require('./text-builder')
const HtmlBuilder = require('./html-builder')

const mail = {
  from: 'Ed',
  to: 'Santa',
  body: 'Would you kindly do me a favor and ...',
  header: 'ACME Inc.',
};

function textMail(mail) {
  const builder = new TextBuilder();
  const composer = new MailComposer(builder, mail);
  composer.compose();
  return builder.getText();
}

function htmlMail(mail) {
  const builder = new HtmlBuilder();
  const composer = new MailComposer(builder, mail);
  composer.compose();
  return builder.getHtml();
}

console.log('mail as text\n')
console.log(textMail(mail));

console.log('\nmail as HTML\n')
console.log(htmlMail(mail));
