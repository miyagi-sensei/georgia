# Class 20 - Data Structure Week 2
## Answer Key to Written Test
1. C
2. D
3. C
4. `Empty 4 8 Empty`

## Car Sorter - 01017
- Incoming cars in a specified sequence
- Need to sort them using 2 *monotonic queues*
```python
for each n in incoming_sequence:
    if n can be pushed into monotonic queue 1:
        choose 1
    else if n can be pushed into monotonic queue 2:
        choose 2
    else:
        print "NO" and terminate program
print "YES" if for loop finishes properly
```

## Rails - 20514
- Incoming railcars are in this order `[1, 2, 3, ..., N]`
- Get them to come out on the other side in a specified order using a *monotonic stack*
``` python
incoming = 1
for each seqB:
    for each n in seqB:
        while n >= incoming:
            push incoming to stack
            incoming++
        if n == "top of stack":
            pop the top from stack
        else:
            print "No" and go to next sequence
    if the for loop above finishes:
        print "Yes"
```
## Largest Histogram - 32462
```python
initialize empty stack of pairs
for i in 1...N:
    left = i
    while H[i] < stack.top().first:
        save the top of stack to (h, left) 
        pop the top of stack
        area = (i - left) * h
        max_area = max(max_area, area)
    push (H[i], left) into the stack
go through the residuals of the monotonic stack and consider all those rectangles too
print max_area        
```
[Illustration](https://youtu.be/MIY6c1Y8X1A)
