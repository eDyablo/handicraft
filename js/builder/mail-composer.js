'use strict';

module.exports = class MailComposer {
  constructor(builder, options) {
    this.builder = builder;
    this.to = options.to;
    this.from = options.from;
    this.body = options.body;
  }

  compose() {
    this.builder.buildParagraph('Dear ' + this.to + ',');
    this.builder.buildParagraph(this.body);
    this.builder.buildParagraph('Sincerely yours,');
    this.builder.buildParagraph(this.from);
  }
}
