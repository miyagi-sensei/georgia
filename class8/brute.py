def fword(n):
    if n == 1:
        return '0'
    elif n == 2:
        return '01'
    return fword(n-1) + fword(n-2)

Q = int(input())
F = fword(30)
for _ in range(Q):
    line = input().split()
    l, r, w = int(line[0]), int(line[1]), line[2]
    count = 0
    for i in range(l-1, r-1):
        if F[i:i+2] == w:
            count += 1
    print(count)

