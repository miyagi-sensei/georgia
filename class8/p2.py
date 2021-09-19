from bisect import bisect_left

def solve(r, w):
    if r <= 1:
        return 0
    elif r <= 2:
        return w == '01'
    # find the largest i where fib[i] < r
    i = bisect_left(fib, r) - 1     # binary search instead of linear search
    last_digit = 1 - (i % 2)
    add = (last_digit == 0 and w == '00') or (last_digit == 1 and w == '10')
    return cnt[w][i] + solve(r - fib[i], w) + add


MAXFIB = 87     # fib(86) > 1e18
fib = [0] * MAXFIB
fib[1] = 1
fib[2] = 2
for i in range(3, MAXFIB):
    fib[i] = fib[i-1] + fib[i-2]
cnt = {'00': [0]*MAXFIB,
       '01': [0]*MAXFIB,
       '10': [0]*MAXFIB,
       '11': [0]*MAXFIB}
cnt['01'][2] = 1
for i in range(3, MAXFIB):
    for w in ['00', '01', '10']:
        cnt[w][i] = cnt[w][i-1] + cnt[w][i-2]
    if i % 2 == 0:
        cnt['00'][i] += 1
    else:
        cnt['10'][i] += 1

Q = int(input())
for _ in range(Q):
    line = input().split()
    l, r, w = int(line[0]), int(line[1]), line[2]
    print(solve(r, w) - solve(l, w))
