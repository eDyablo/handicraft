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
	for i := 0; i < 100; i++ {
		result = append(result, pages...)
	}
	return result
}

func download_page(page string) chan bool {
	result := make(chan bool)
	go func() {
		defer close(result)
		response, err := http.Get(page)
		if err != nil {
			panic(fmt.Sprintf("failed to get %s", page))
		}
		if response.StatusCode == http.StatusOK {
			fmt.Printf("%s OK\n", page)
		} else {
			fmt.Printf("%s FAIL %s\n", page, response.Status)
		}
	}()
	return result
}

func download_pages(pages []string) {
	var results []chan bool
	for _, page := range pages {
		results = append(results, download_page(page))
	}
	for _, result := range results {
		<-result
	}
}

func main() {
	startTime := time.Now()
	download_pages(get_pages())
	elapsedTime := time.Since(startTime)
	fmt.Printf("done in %s\n", elapsedTime.Round(time.Millisecond))
}
