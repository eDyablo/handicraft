package translate

import (
  "strings"
  "net/http"

  "github.com/gorilla/mux"
)

type Translation struct {
}

type TranslationHandler struct {
}

func NewTranslationHandler() *TranslationHandler {
  return &TranslationHandler{}
}

func (handler TranslationHandler) RegisterHandlers(router *mux.Router) {
  router.HandleFunc("/translators/{translator}/translations", handler.getOptions).Methods(http.MethodOptions)
  router.HandleFunc("/translators/{translator}/translations", handler.getTranslations).Methods(http.MethodGet)
}

func (handler TranslationHandler) getOptions(response http.ResponseWriter, request *http.Request) {
  methods := []string{
    http.MethodOptions,
    http.MethodGet,
    http.MethodPost,
    http.MethodPut,
    http.MethodDelete,
  }
  response.Header().Add("Allow", strings.Join(methods, ", "))
}

func (handler TranslationHandler) getTranslations(response http.ResponseWriter, request *http.Request) {
}
