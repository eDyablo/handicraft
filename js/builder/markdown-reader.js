'use strict';

module.exports = class MarkdownReader {
  constructor(builder) {
    this.builder = builder;
  }

  read(markdown) {
    if (markdown) {
      const lines = markdown.split('\n');
      lines.forEach(line => {
        if (line.startsWith('# ')) {
          this.builder.buildHeading(line.substr(2));
        } else {
          this.builder.buildParagraph(line);
        }
      });
    }
  }
}
