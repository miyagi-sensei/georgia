# Class 10
## Boolean Logic
> If it doesn’t rain this weekend *and* I finished my homework, my mother will take me to the new Ocean Park Water World.

What does this sentence mean? How does the operator *and* work?

> If I miss classes too often *or* I get into a physical fight, I will be expelled from school.”

What does that sentence mean? How does the operator or work?


- In the boolean world, a statement is either *true* or *false*. (Real life, however, is a lot more complicated with shades of gray everywhere) 
- Boolean values are either `true` or `false`.

### Truth table for *AND*
|A|B|A && B|
|---|---|---|
|F|F|F|
|F|T|F|
|T|F|F|
|T|T|T|

### Truth table for *OR*
|A|B|A \|\| B|
|---|---|---|
|F|F|F|
|F|T|T|
|T|F|T|
|T|T|T|

There are also *XOR* and *NAND*. Can you google them and try to come up with the truth table for *XOR*?

## Logical Equivalence
`A && B` is logically equivalent to `!((!A) || (!B))`, or NOT ((NOT A) OR (NOT B))
|A|B|!A|!B|(!A) \|\| (!B)|!((!A) \|\| (!B))|
|---|---|---|---|---|---|
|F|F|T|T|T|F|
|F|T|T|F|T|F|
|T|F|F|T|T|F|
|T|T|F|F|F|T|


### Conditional Statements
> A conditional is a logical compound statement in which a statement p, called the *antecedent*, implies a statement q, called the *consequent*.<br>
> It’s written as p —> q
- Your teacher tells you “If you steal a computer from school, you will be expelled”. That statement is a conditional. 
- “If you steal a computer from school” is an *antecedent* (p). 
- “you will be expelled” is the *consequent* (q). 
- If you didn’t steal a computer from school but you were expelled, is your teacher wrong? In what case could you say your teacher was wrong? 

### Truth table for the conditional statements
|p|q|p -> q|
|---|---|---|
|F|F|T|
|F|T|T|
|T|F|F|
|T|T|T|

### Contrapositive is equivalent to the Conditional Statement
For any conditional p —> q, there are 3 related statements:
- the converse (q —> p)
- the inverse (~p —> ~q)
- the contrapositive (~q —> ~p)

Examples:
- Conditional: If someone lives on the 22/F, there is an elevator in his building.
- Converse: If there is an elevator in someone’s building, he lives on the 22/F.
- Inverse: If someone does not live on the 22/F, there is no elevator in his building.
- Contrapositive: If there is no elevator in someone’s building, he does not live on the 22/F.

Which of the above are sensible and logical? Which of the above are logically equivalent?
Examine their truth tables.

### Logical Equivalence
> Two statements are logically equivalent if their truth tables are identical.

### Truth table for the contrapositive
|p|q|~q|~p|~q -> ~p|
|---|---|---|---|---|
|F|F|T|T|T|
|F|T|F|T|T|
|T|F|T|F|F|
|T|T|F|F|T|

### Negation
Negation of a statement can be tricky, especially when there are *qualifiers* in it.
The following pairs of statements are negation of each other
- “*All* A are B” vs. “*At least one* A is not B”
- “*No* A are B” vs. “*At least one* A is B”

How do you test a program for *CORRECTNESS*?
You disprove its *correctness* if you can find *at least one* wrong answer case. Because a *correct* program needs to print correct answers for *all* inputs.

### Negation of a Conditional
To reject a conditional p —> q, we can prove that its negation is true.
The negation of p —> q is logically equivalent to p AND ~q.

"If you get the vaccine, you will not get COVID."
- p is "if you get the vaccine"
- q is "you will not get COVID"
- if you can find 1 person who got the vaccine and also caught COVID, you have proven this conditional false
- that was the negation of p -> q, which is logically equivalent to p `and` ~q

---

## Exericses
### 8
Which of the following pairs of statements are logically equivalent?<br>

1. If it is raining then the ground is wet.<br>
    If the ground is not wet then it isn’t raining.<br>
2. If it is raining then the ground is wet.<br>
    The ground is wet or it is not raining.<br>

A.  1 only<br>
B.  2 only<br>
C.  1 and 2<br>
D.  None of them 

<br>

____________

### 9
If Charlie gets full marks in the final exam, he feels happy; if Charlie feels happy and it is raining outside, he plays computer games at home. Charlie is not playing computer games at home. Which of the followings must be true?

A. Charlie does not get full marks in the final exam<br>
B. Charlie does not feel happy<br>
C. It is not raining outside<br>
D. None of the above

<br>

____________

### 10
Alice, Bob and Charlie are invited to a party. However, they still haven’t decided whether they will go to the party or not. If Alice goes then Bob will also go; if Alice and Bob both go, then Charlie will not go. Which of the following is/are possible situations?

i.    Only Alice and Bob go<br>
ii.   Only Alice and Charlie go<br>
iii.  Only Bob and Charlie go<br>

A. i only<br>
B. ii only<br>
C. i and iii only<br>
D. ii and iii only

<br>

____________

### 11
Suppose this statement is true: “If I eat this giant cookie, then I will feel sick.” Which of the following statements must also be true?

A. If I feel sick, then I ate that giant cookie.<br>
B. If I don’t eat this giant cookie, then I won’t feel sick.<br>
C. If I don’t feel sick, then I didn’t eat that giant cookie.

<br>

________________________________________________________________________________

### 12
“Somebody brought a flashlight.” Write the negation of this statement.

<br>

________________________________________________________________________________

### 13
“There are no prime numbers that are even.” Write the negation of this statement.

<br>

________________________________________________________________________________

### 14
“All Chinese children learn English in school.” Write the negation of this statement.

<br>

_______________________

### 15
Truth table for *NOR*
|operand 1|operand 2|result|
|---|---|---|
|F|F|T|
|F|T|F|
|T|F|F|
|T|T|F|

Which of the following expressions is equivalent to `((not A) and B)`?

A. `A nor (B nor B)`<br>
B. `(A nor A) nor B`<br>
C. `(A nor B) nor B`<br>
D. `(A nor B) nor (B nor B)`

<br>

_______________________

### 16
Suppose `x` is a boolean variable. Evaluate the following expression in C/C++.<br>
`(x && (!x)) == false`

<br>

_______________________

### 17
Given that there is only one correct answer for this question, which one is the correct answer?

A. Neither B nor C is the correct answer<br>
B. Netiher C nor D is the correct answer<br>
C. Trust me, this is the correct answer<br>
D. Neither A nor B is the correct answer

<br>

_______________________

### 18
Which of the following pair(s) of boolean expressions are logically equivalent?

1. `x || (!x && y)`<br>
    `(x && !y) || y`
2. `(x || !y) ^ (!x || y)`<br>
    `(x && !y) || (!x && y)`

A. 1 only<br>
B. 2 only<br>
C. 1 and 2<br>
D. None of them

<br>

_______________________

# Combinatorics
Watch the first 9 videos this [playlist](https://www.youtube.com/playlist?list=PLmdFyQYShrjfPLdHQxuNWvh2ct666Na3z) (up to "Selection")
Or the following 9 videos:
1. [Counting](https://youtu.be/0NAASclUm4k)
2. [Forming Numbers 1](https://youtu.be/XPPYYM6WCuE)
3. [Forming Numbers 2](https://youtu.be/W4eeXU_T53o)
4. [Forming Numbers 2](https://youtu.be/HwT32y5MQyo)
5. [Forming Numbers 2](https://youtu.be/2C4CVM5rgxQ)
6. [Arranging People](https://youtu.be/tBQhcP9Zr2E)
7. [Arranging Letters 1](https://youtu.be/htkFH0Fhk-M)
8. [Arranging Letters 2](https://youtu.be/jMx3SqBYuX0)
9. [Selection](https://youtu.be/h6xioUHONj0)

---

# Extra reading on logic (optional)
http://www.opentextbookstore.com/mathinsociety/2.5/Logic.pdf
