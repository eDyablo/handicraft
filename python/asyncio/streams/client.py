#!/usr/bin/env python3

import asyncio


async def main():
    reader, writer = await asyncio.open_connection("localhost", 9090)
    session_id = (await reader.readline()).decode().rstrip()
    print(session_id)
    writer.write("hello\n".encode())
    print(await reader.readline())


if __name__ == "__main__":
    asyncio.run(main())
