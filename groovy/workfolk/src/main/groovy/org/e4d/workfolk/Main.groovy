package org.e4d.workfolk

import groovy.transform.CompileStatic
import org.codehaus.groovy.control.CompilerConfiguration
import groovy.lang.GroovyShell

/**
 * Program
 */
@CompileStatic
class Main {

  static class DSL {
    static class Worker {
      void setName(String name) {
      }

      void doing(Closure declarator) {
        declarator()
      }
    }

    void worker(Closure declarator) {
      declarator.delegate = new Worker()
      declarator()
    }
  }

  static void main(String[] args) {
    if (args.length > 0) {
      final cc = new CompilerConfiguration()
      cc.setScriptBaseClass(DelegatingScript.class.getName())
      final sh = new GroovyShell(new Binding(), cc)
      final script = (DelegatingScript)sh.parse(new File(args[0]))
      script.setDelegate(new DSL())
      script.run()
    }
  }

}
