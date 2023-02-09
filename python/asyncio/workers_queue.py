#!/usr/bin/env python3

import asyncio
import random


class Program:
    tasks_number = 10
    workers_number = 3

    def __init__(self):
        self._queue = asyncio.Queue()
        self._workers = set()

    async def main(self):
        self._prepare_tasks()
        await self._start_workers()
        await self._wait_all_tasks_completed()
        await self._stop_workers()

    def _prepare_tasks(self):
        for _ in range(self.tasks_number):
            sleep_time = random.uniform(0.05, 1.0)
            self._queue.put_nowait(sleep_time)

    async def _start_workers(self):
        # Stop currently running workers if any
        await self._stop_workers()
        self._workers = {asyncio.create_task(
            self._work()) for _ in range(self.workers_number)}
        # Each worker removes itself from the workers set when done
        for worker in self._workers:
            worker.add_done_callback(self._workers.discard)

    async def _wait_all_tasks_completed(self):
        await self._queue.join()

    async def _stop_workers(self):
        for worker in self._workers:
            worker.cancel()
        await asyncio.gather(*self._workers, return_exceptions=True)

    async def _work(self):
        while True:
            sleep_for = await self._queue.get()
            await asyncio.sleep(sleep_for)
            print(sleep_for)
            self._queue.task_done()


if __name__ == "__main__":
    asyncio.run(Program().main())
