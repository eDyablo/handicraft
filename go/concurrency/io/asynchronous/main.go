package main

import (
	"fmt"
	"net/http"
	"time"
	"sync"
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

func download_page(page string, wg *sync.WaitGroup) {
	defer wg.Done()
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

func download_pages(pages []string) {
	var wg sync.WaitGroup
	for _, page := range pages {
		wg.Add(1)
		go download_page(page, &wg)
	}
	wg.Wait()
}

func main() {
	startTime := time.Now()
	download_pages(get_pages())
	elapsedTime := time.Since(startTime)
	fmt.Printf("done in %s\n", elapsedTime.Round(time.Microsecond))
}
