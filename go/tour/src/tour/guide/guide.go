package main

import (
	"tour/errors"
	errors_exercicse "tour/exercise/errors"
	stringer_exercise "tour/exercise/stringer"
	"tour/hello"
	"tour/methods"
	"tour/reader"
	"tour/sandbox"
	"tour/stringer"
	"tour/template"
)

func main() {
	hello.Exercise()
	sandbox.Exercise()
	methods.Exercise()
	errors.Exercise()
	stringer.Exercise()
	stringer_exercise.Exercise()
	errors_exercicse.Exercise()
	reader.Exercise()
	template.Exercise()
}
