package stringer

import "fmt"

type Person struct {
  Name string
  Age int
}

func (person Person) String() string {
  return fmt.Sprintf("%v (%v years)", person.Name, person.Age)
}

func Exercise() {
  first := Person{"Arthur Dent", 42}
  second := Person{"Zaphod Beeblebrox", 9001}
  fmt.Println(first, second)
}
