package main

import (
  "accumulate/model"
  "encoding/json"
  "log"
  "net/http"

  "github.com/gorilla/mux"
)

var repository = model.NewRepository()

// GetAccumulators returns all accumulators
func GetAccumulators(response http.ResponseWriter, request *http.Request) {
  response.Header().Set("Content-Type", "application/json")
  json.NewEncoder(response).Encode(repository.Accumulators)
}

// CreateAccumulator creates new accumulator
func CreateAccumulator(response http.ResponseWriter, request *http.Request) {
  accumulator := repository.NewAccumulator()
  response.Header().Set("Content-Type", "application/json")
  json.NewEncoder(response).Encode(accumulator)
}

// GetAccumulator returns specific accumulator
func GetAccumulator(response http.ResponseWriter, request *http.Request) {
  params := mux.Vars(request)
  accumulator := repository.GetAccumulator(params["id"])
  response.Header().Set("Content-Type", "application/json")
  json.NewEncoder(response).Encode(accumulator)
}

// Accumulate adds amount to specified accumulator
func Accumulate(response http.ResponseWriter, request *http.Request) {
  params := mux.Vars(request)
  accumulator := repository.GetAccumulator(params["id"])
  accumulator.Value++
  repository.UpdateAccumulator(accumulator)
  response.Header().Set("Content-Type", "application/json")
  json.NewEncoder(response).Encode(accumulator)
}

// DeleteAccumulator deletes specified accumulator
func DeleteAccumulator(response http.ResponseWriter, request *http.Request) {
  params := mux.Vars(request)
  accumulator := repository.GetAccumulator(params["id"])
  repository.DeleteAccumulator(accumulator)
  response.Header().Set("Content-Type", "application/json")
  json.NewEncoder(response).Encode(accumulator)
}

func main() {
  router := mux.NewRouter()
  router.HandleFunc("/accumulators", GetAccumulators).Methods("GET")
  router.HandleFunc("/accumulators", CreateAccumulator).Methods("POST")
  router.HandleFunc("/accumulators/{id}", GetAccumulator).Methods("GET")
  router.HandleFunc("/accumulators/{id}", Accumulate).Methods("PATCH")
  router.HandleFunc("/accumulators/{id}", DeleteAccumulator).Methods("DELETE")
  log.Fatal(http.ListenAndServe(":80", router))
}
