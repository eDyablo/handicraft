package main

import (
	"fmt"
	"net/http"
	"time"
)

var pages = []string{
	"https://www.jython.org",
	"http://olympus.realpython.org/dice",
}

func get_pages() []string {
	var result []string
	for i := 0; i < 10; i++ {
		result = append(result, pages...)
	}
	return result
}

func download_page(page string) {
	response, err := http.Get(page)
	if err != nil {
		panic(fmt.Sprintf("failed to get %s", page))
	}
	if response.StatusCode == http.StatusOK {
		fmt.Printf("%s OK\n", page)
	} else {
		fmt.Printf("%s FAIL %s\n", page, response.Status)
	}
}

func main() {
	startTime := time.Now()
	for _, page := range get_pages() {
		download_page(page)
	}
	elapsedTime := time.Since(startTime)
	fmt.Printf("done in %s\n", elapsedTime.Round(time.Second))
}
