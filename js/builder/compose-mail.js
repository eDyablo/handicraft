'use strict';

const MailComposer = require('./mail-composer')
const TextBuilder = require('./text-builder')

const builder = new TextBuilder();
const composer = new MailComposer(builder, {
  from: 'Ed',
  to: 'Santa',
  body: 'Would you kindly do me a favor and ...'
});
composer.compose();
const mail = builder.getText();

console.log(mail);
