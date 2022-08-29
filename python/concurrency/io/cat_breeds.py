#!/usr/bin/env python3

import asyncio
import aiohttp
import time

base_url = "https://catfact.ninja"


async def get_json(url):
    async with aiohttp.ClientSession() as session:
        async with session.get(url) as response:
            if response.status != 200:
                raise aiohttp.ClientError(response.status)
            return await response.json()


async def get_breeds():
    task = asyncio.create_task(get_json(f"{base_url}/breeds"))
    while task:
        json = await task
        url = json["next_page_url"]
        task = asyncio.create_task(get_json(url)) if url else None
        for breed in json["data"]:
            yield breed["breed"]

async def main():
    async for breed in get_breeds():
        print(breed)


if __name__ == "__main__":
    start_time = time.time()
    asyncio.run(main())
    print(f"done in {time.time() - start_time:.3f} seconds")
