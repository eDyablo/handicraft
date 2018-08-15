package book

// Person represents peronal data
type Person struct {
  ID        string `json:"id"`
  FirstName string `json:"firstname,omitempty"`
  LastName  string `json:"lastname,omitempty"`
  Address   *Address `json:"address,omitempty"`
}
