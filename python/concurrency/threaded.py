#!/usr/bin/env python3

import concurrent.futures
import requests
import threading
import time

thread_local = threading.local()


def get_session():
    if not hasattr(thread_local, "session"):
        thread_local.session = requests.Session()
    return thread_local.session


def download_page(url):
    session = get_session()
    with session.get(url) as response:
        print(f"Read {len(response.content)} from {url}")


def download_all_pages(pages):
    with concurrent.futures.ThreadPoolExecutor(max_workers=5) as executor:
        executor.map(download_page, pages)


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
