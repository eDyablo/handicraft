package translate

import (
  "strings"
  "net/http"

  "github.com/gorilla/mux"
)

type Translator struct {
}

type TranslatorHandler struct {
}

func NewTranslatorHandler() *TranslatorHandler {
  return &TranslatorHandler{}
}

func (handler TranslatorHandler) RegisterHandlers(router *mux.Router) {
  router.HandleFunc("/translators", handler.getOptions).Methods(http.MethodOptions)
  router.HandleFunc("/translators", handler.getTranslators).Methods(http.MethodGet)
  router.HandleFunc("/translators", handler.createTranslator).Methods(http.MethodPost)
  router.HandleFunc("/translators", handler.updateTranslator).Methods(http.MethodPut)
  router.HandleFunc("/translators", handler.deleteTranslator).Methods(http.MethodDelete)
}

func (handler TranslatorHandler) getOptions(response http.ResponseWriter, request *http.Request) {
  methods := []string{
    http.MethodOptions,
    http.MethodGet,
    http.MethodPost,
    http.MethodPut,
    http.MethodDelete,
  }
  response.Header().Add("Allow", strings.Join(methods, ", "))
}

func (handler TranslatorHandler) getTranslators(response http.ResponseWriter, request *http.Request) {
}

func (handler TranslatorHandler) createTranslator(response http.ResponseWriter, request *http.Request) {
}

func (handler TranslatorHandler) updateTranslator(response http.ResponseWriter, request *http.Request) {
}

func (handler TranslatorHandler) deleteTranslator(response http.ResponseWriter, request *http.Request) {
}
