# Class 32 - Graph Theory II
## Dijkstra
[Slidedeck 2019](https://assets.hkoi.org/training2019/g-ii.pdf)
At page 30, most of the graph are relatively unexplored. How does the algorithm know that 7 is finalized, that there won't be a shorter path through some other unfinalized node (imagine some hypothetical edges like below)?
<img src="https://i.imgur.com/aQTz13H.jpg" width="600">

- The contradiction would be that if those edges exist, then 7 would not be the next closest unfinalized vertex. 4 would be (with a distance of 10).
- It can be deduced that there cannot be a shorter path for the closest unfinalized node than the ones found so far.
- Therefore the closest unfinalized node has already been **finalized**.

## Exercises
- [01041 - Shortest Path](https://judge.hkoi.org/task/01041)
#### Extra Credit
- [T033 - Second Trip Discount](https://judge.hkoi.org/task/T033)
