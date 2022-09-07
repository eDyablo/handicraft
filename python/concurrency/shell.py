#!/usr/bin/env python3

from asyncio.subprocess import PIPE
from contextlib import contextmanager
from datetime import datetime
from os import getpid
from threading import current_thread
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


async def list(path):
    command = f"ls -a {path}"
    process = await asyncio.create_subprocess_shell(command, stdout=PIPE, stderr=PIPE)
    return (await process.stdout.read()).decode("utf-8").split()


async def find(path, name):
    command = f"find {path} -name '{name}'"
    process = await asyncio.create_subprocess_shell(command, stdout=PIPE, stderr=PIPE)
    return (await process.stdout.read()).decode("utf-8").split()


async def main():
    print(await list("/"))
    # print(await find(".", "*.py"))


if __name__ == "__main__":
    asyncio.run(main())
