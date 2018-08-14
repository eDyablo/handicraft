package main

import (
	"encoding/json"
  "rest/book"
	"net/http"
	"log"
  "github.com/gorilla/mux"
)

var theBook = book.NewBook()

// GetPeople returns people from the book
func GetPeople(w http.ResponseWriter, r *http.Request) {
  w.Header().Set("Content-Type", "application/json")
  json.NewEncoder(w).Encode(theBook.People)
}

// GetPerson returns one person from the book
func GetPerson(w http.ResponseWriter, r *http.Request) {
  params := mux.Vars(r)
  for _, item := range theBook.People {
    if item.ID == params["id"] {
      w.Header().Set("Content-Type", "application/json")
      json.NewEncoder(w).Encode(item)
    }
  }
}

// CreatePerson adds new person to the book
func CreatePerson(w http.ResponseWriter, r *http.Request) {
  params := mux.Vars(r)
  var person book.Person
  _ = json.NewDecoder(r.Body).Decode(&person)
  person.ID = params["id"]
  theBook.People = append(theBook.People, person)
  GetPeople(w, r)
}

// DeletePerson deletes one person from the book
func DeletePerson(w http.ResponseWriter, r *http.Request) {
  params := mux.Vars(r)
  people := theBook.People
  for index, item := range people {
    if item.ID == params["id"] {
      people = append(people[:index], people[index+1:]...)
      break
    }
    GetPeople(w, r)
  }
}

func main() {
  router := mux.NewRouter()
  router.HandleFunc("/people", GetPeople).Methods("GET")
  router.HandleFunc("/people/{id}", GetPerson).Methods("GET")
  router.HandleFunc("/people/{id}", CreatePerson).Methods("POST")
  router.HandleFunc("/people/{id}", DeletePerson).Methods("DELETE")
  log.Fatal(http.ListenAndServe(":8000", router))
}
