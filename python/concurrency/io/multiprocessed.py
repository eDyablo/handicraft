#!/usr/bin/env python3

import requests
import multiprocessing
import time

session = None


def init_global_session():
    global session
    if not session:
        session = requests.Session()


def download_page(url):
    global session
    with session.get(url) as response:
        process_name = multiprocessing.current_process().name
        print(f"{process_name:20}Read {len(response.content)} from {url}")


def download_all_pages(pages):
    with multiprocessing.Pool(initializer=init_global_session) as pool:
        pool.map(download_page, pages)


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
