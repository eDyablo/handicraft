def count_travel_ways(width, height, memo={}):
    key = f'{width},{height}'
    if key in memo:
        return memo[key]
    if width == 0 or height == 0:
        return 0
    if width == 1 or height == 1:
        return 1
    memo[key] = count_travel_ways(
        width-1, height, memo) + count_travel_ways(width, height-1, memo)
    return memo[key]
