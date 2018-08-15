package book

// Book represents a book of people
type Book struct {
  People []Person
}

// NewBook creates a new book
func NewBook() Book {
  var people []Person
  people = append(people, Person {
    ID: "1",
    FirstName: "Ed",
    LastName: "Yablonsky",
    Address: &Address {
      City: "Odesa",
    },
  })
  people = append(people, Person { ID: "2" })
  people = append(people, Person { ID: "3" })
  return Book { People: people }
}
