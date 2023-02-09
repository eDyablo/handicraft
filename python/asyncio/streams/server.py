#!/usr/bin/env python3

import asyncio
import string
from random import choices


def generate_session_id():
    return "".join(choices(string.ascii_uppercase + string.digits, k=6))


async def handler(reader, writer):
    session_id = generate_session_id()
    print(f"{session_id:>2}: connected")
    writer.write(f"{session_id}\n".encode())
    while (line := await reader.readline()):
        print(f"{session_id:>2}: {line}")
        writer.write(line)
    print(f"{session_id:>2}: disconnected")


async def main():
    server = await asyncio.start_server(handler, "127.0.0.1", 9090)
    await server.serve_forever()


if __name__ == "__main__":
    asyncio.run(main())
