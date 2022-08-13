#!/usr/bin/env python3

import requests
import time


def download_page(url, session):
    with session.get(url) as response:
        print(f"Read {len(response.content)} from {url}")


def download_all_pages(pages):
    with requests.Session() as session:
        for url in pages:
            download_page(url, session)


def main():
    pages = [
        "https://www.jython.org",
        "http://olympus.realpython.org/dice",
    ] * 100
    start_time = time.time()
    download_all_pages(pages)
    end_time = time.time()
    duration = end_time - start_time
    print(f"Downloaded {len(pages)} in {duration} seconds")


if __name__ == "__main__":
    main()
