from heapq import heappop, heappush


def maximum_shipped_items(containers, items, cargo_size):
    count = min(len(containers), len(items))
    pile = []
    for i in range(0, count):
        for container in range(0, containers[i]):
            heappush(pile, -items[i])
    amount = 0
    for load in range(0, min(cargo_size, len(pile))):
        amount -= heappop(pile)
    return amount
