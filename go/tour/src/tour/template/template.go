package template

import (
	"os"
	"text/template"
)

// Person holds personal data
type Person struct {
	FirstName string
	LastName  string
}

// Book is a book of contacts
type Book struct {
	Contacts []Person
}

var templatesDefinition = `
{{define "contact" -}}
{{.FirstName}} {{.LastName}}
{{end}}
{{define "book" -}}
{{range .Contacts}}{{template "contact" .}}{{end}}
{{- end}}
`

// Exercise does the exercise
func Exercise() {
	templates, err := template.New("book").Parse(templatesDefinition)
	if err != nil {
		panic(err)
	}
	book := Book{
		Contacts: []Person{
			Person{"Alexey", "Chayka"},
			Person{"Mykola", "Zima"},
			Person{"Halyna", "Zelenko"},
			Person{"Symon", "Sobol"},
			Person{"Yulia", "Kohut"},
		},
	}
	err = templates.ExecuteTemplate(os.Stdout, "book", book)
}
