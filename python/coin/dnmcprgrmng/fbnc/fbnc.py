def fibo(n, memo=None):
    if memo is None:
        memo = {}
    if n in memo:
        return memo[n]
    if n == 1 or n == 2:
        return 1
    memo[n] = fibo(n-1, memo) + fibo(n-2, memo)
    return memo[n]
