package translate

import "github.com/gorilla/mux"

type Handler interface {
  RegisterHandlers(*mux.Router)
}
