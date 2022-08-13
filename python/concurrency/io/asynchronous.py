#!/usr/bin/env python3

import asyncio
import aiohttp
import time


async def download_page(url, session):
    async with session.get(url) as response:
        print(f"Read {response.content_length} from {url}")


async def download_all_pages(pages):
    async with aiohttp.ClientSession() as session:
        tasks = (asyncio.ensure_future(download_page(url, session)) for url in pages)
        await asyncio.gather(*tasks, return_exceptions=True)


def main():
    pages = [
        "https://www.jython.org",
        "http://olympus.realpython.org/dice",
    ] * 100
    start_time = time.time()
    asyncio.run(download_all_pages(pages))
    end_time = time.time()
    duration = end_time - start_time
    print(f"Downloaded {len(pages)} in {duration} seconds")


if __name__ == "__main__":
    main()
