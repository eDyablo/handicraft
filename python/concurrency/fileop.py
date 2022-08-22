#!/usr/bin/env python3

from contextlib import contextmanager
from datetime import datetime
from os import getpid
from threading import current_thread
import aiofiles
import asyncio
import logging


@contextmanager
def scope_logger(name):
    logger = logging.getLogger(f"{getpid()}:{current_thread().name}:{name}")
    try:
        logger.info("started")
        start_time = datetime.now()
        yield logger
    finally:
        logger.info(f"completed in {(datetime.now() - start_time).seconds} seconds")


async def write_numbers(range, name):
    with scope_logger(f"write_numbers({range!r}, {name})"):
        async with aiofiles.open(name, mode="tw") as file:
            await file.write("\n".join(map(str, range)))


async def make_directory(path):
    with scope_logger(f"make_directory({path})"):
        command = f"mkdir -p {path}"
        process = await asyncio.create_subprocess_shell(command)
        await process.wait()


async def main():
    output_dir = "fileop_output"
    await make_directory(output_dir)
    numbers_per_file = 10_000
    files_count = 1_000
    tasks = [
        write_numbers(
            range(i * numbers_per_file, (i + 1) * numbers_per_file),
            f"{output_dir}/{i:0{len(str(files_count-1))}}",
        )
        for i in range(files_count)
    ]
    await asyncio.gather(*tasks)


if __name__ == "__main__":
    logging.basicConfig(level=logging.INFO)
    with scope_logger("main()"):
        asyncio.run(main())
