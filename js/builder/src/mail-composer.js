'use strict';

module.exports = class MailComposer {
  constructor(builder, options) {
    this.builder = builder;
    this.to = options.to;
    this.from = options.from;
    this.body = options.body;
    this.header = options.header;
    this.footer = options.footer;
  }

  compose() {
    this.builder.buildHeading(this.header);
    this.builder.buildParagraph('Dear ' + this.to + ',');
    this.builder.buildParagraph(this.body);
    this.builder.buildParagraph('Sincerely yours,');
    this.builder.buildParagraph(this.from);
    this.builder.buildHeading(this.footer);
  }
}
