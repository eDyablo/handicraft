package main

import (
  "log"
  "net/http"
  tr "translate/translate"

  "github.com/gorilla/mux"
)

var handlers = []tr.Handler{
  tr.NewTranslatorHandler(),
  tr.NewTranslationHandler(),
}

func main() {
  router := mux.NewRouter()
  for _, h := range handlers {
    h.RegisterHandlers(router)
  }
  log.Fatal(http.ListenAndServe(":80", router))
}
