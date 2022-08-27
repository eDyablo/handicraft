package main

import (
	"encoding/json"
	"fmt"
	"io"
	"net/http"
	"time"
)

type DogAPI struct {
	baseURL       string
	breedsListURL string
}

func NewDogAPI(baseURL string) DogAPI {
	return DogAPI{
		baseURL,
		fmt.Sprint(baseURL, "breeds/list/"),
	}
}

func (api DogAPI) GetAllBreeds() chan string {
	channel := make(chan string)
	go func() {
		defer close(channel)
		type Breed struct {
			name      string
			subBreeds chan string
		}
		var breeds []Breed
		for breed := range api.GetBreeds() {
			breeds = append(breeds, Breed{breed, api.GetSubBreeds(breed)})
		}
		for _, breed := range breeds {
			for subBreed := range breed.subBreeds {
				if len(subBreed) > 0 {
					channel <- subBreed + " " + breed.name
				} else {
					channel <- breed.name
				}
			}
		}
	}()
	return channel
}

func (api DogAPI) GetBreeds() chan string {
	channel := make(chan string)
	go func() {
		defer close(channel)
		for _, name := range api.getList(api.breedsListURL) {
			channel <- name
		}
	}()
	return channel
}

func (api DogAPI) GetSubBreeds(breed string) chan string {
	subBreedsListURL := fmt.Sprintf("%sbreed/%s/list/", api.baseURL, breed)
	channel := make(chan string)
	go func() {
		defer close(channel)
		subBreeds := api.getList(subBreedsListURL)
		if len(subBreeds) == 0 {
			channel <- ""
		} else {
			for _, name := range subBreeds {
				channel <- name
			}
		}
	}()
	return channel
}

func (api DogAPI) getList(listURL string) []string {
	var data struct {
		Message []string
	}
	err := json.Unmarshal(GetContent(listURL), &data)
	if err != nil {
		panic(fmt.Sprint("failed to unmarshall from", api.breedsListURL))
	}
	return data.Message
}

func GetContent(URL string) []byte {
	response, err := http.Get(URL)
	if err != nil {
		panic(fmt.Sprint("failed to get from", URL))
	}
	if response.StatusCode != http.StatusOK {
		panic(fmt.Sprint("failed to get from", URL, response.Status))
	}
	defer response.Body.Close()
	content, err := io.ReadAll(response.Body)
	if err != nil {
		panic(fmt.Sprint("failed to read content from", URL))
	}
	return content
}

func main() {
	dogAPI := NewDogAPI("https://dog.ceo/api/")
	defer func(startTime time.Time) { fmt.Println("done in", time.Since(startTime)) }(time.Now())
	for breed := range dogAPI.GetAllBreeds() {
		fmt.Println(breed)
	}
}
