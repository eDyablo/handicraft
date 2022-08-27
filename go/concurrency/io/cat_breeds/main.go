package main

import (
	"encoding/json"
	"fmt"
	"io"
	"net/http"
	"time"
)

var base_url = "https://catfact.ninja/"

type Breed struct {
	Name    string `json:"breed"`
	Country string
	Origin  string
	Coat    string
	Pattern string
}

func (breed Breed) String() string {
	return fmt.Sprintf("%s from %s", breed.Name, breed.Country)
}

func GetBreeds() chan Breed {
	channel := make(chan Breed)
	go func() {
		defer close(channel)
		url := fmt.Sprintf("%sbreeds?page=1", base_url)
		for url != "" {
			response, err := http.Get(url)
			if err != nil {
				panic(fmt.Sprint("failed to get", url))
			}
			defer response.Body.Close()
			content, err := io.ReadAll(response.Body)
			if err != nil {
				panic(fmt.Sprint("failed to read content from", url))
			}
			var data struct {
				CurrentPage int     `json:"current_page"`
				Breeds      []Breed `json:"data"`
				NextPageUrl string  `json:"next_page_url"`
			}
			err = json.Unmarshal(content, &data)
			if err != nil {
				panic(fmt.Sprint("failed to unmarshal from", url))
			}
			for _, breed := range data.Breeds {
				channel <- breed
			}
			url = data.NextPageUrl
		}
	}()
	return channel
}

func main() {
	defer func(startTime time.Time) { fmt.Println("done in", time.Since(startTime)) }(time.Now())
	breeds := GetBreeds()
	for breed := range breeds {
		fmt.Println(breed)
	}
}
