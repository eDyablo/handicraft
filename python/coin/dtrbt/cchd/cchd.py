def cached(func):
    cache = {}

    def wrapper(*args):
        key = hash(args)
        if key not in cache:
            cache[key] = func(*args)
        return cache[key]
    return wrapper
