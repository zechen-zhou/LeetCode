# 0003. Longest Substring Without Repeating Characters

This question is asking for the **length** of the longest substring **without duplicating characters**.

## Method 1
We might need a variable to keep track of the longest length. To check duplicates, a key-value mapping is an efficient way. For example, using a hash table (**Insertion and Search will be $O(1)$ time**). Last but not least, we need to think about how to compute the length of substring in each iteration.

### Example: `cabb`

1. The first iteration:

```
c  a  b  b  d
^        ^
Start    End
```

| Key     | Value |
|---------|-----|
| c  | 0  |
| a  | 1  |
| b  | 2  |
| b  | 3  |
| d  | 4  |

From the table above, `Start` points to $c$ and `End` points to $b$. The longest substring without repeating characters is `cab`, the length is `End - Start = 3-0 = 3` *(duplicates found during this iteration)*.

2. The second iteration

```
c  a  b  b  d
   ^     ^
 Start   End
```

| Key     | Value |
|---------|-----|
| a  | 1  |
| b  | 2  |
| b  | 3  |
| d  | 4  |

From the table above, `Start` points to $a$ and `End` points to $b$. The longest substring without repeating characters is `ab`, the length is `End - Start = 3-1 = 2` *(duplicates found during this iteration)*.

3. The third iteration

```
c  a  b  b  d
      ^  ^
   Start End
```

| Key     | Value |
|---------|-----|
| b  | 2  |
| b  | 3  |
| d  | 4  |

From the table above, `Start` points to the first $b$ and `End` points to the second $b$. The longest substring without repeating characters is `b`, the length is `End - Start = 3-2 = 1` *(duplicates found during this iteration)*.

4. The fourth iteration

```
c  a  b  b  d
         ^  ^
      Start End
```

| Key     | Value |
|---------|-----|
| b  | 3  |
| d  | 4  |

From the table above, `Start` points to $b$ and `End` points to $d$. The longest substring without repeating characters is `bd`, the length is `End - Start + 1 = 4-3+1 = 2` *(no duplicates found during this iteration)*.

```java
Algorithm lengthOfLongestSubstring(s)
1. if s.length() = 0 then
2.    return 0
3. else if s.length() = 1 then
4.    return 1
5. end if
6. for i = 0 to s.length do
7.    for j = i to s.length do
8.       if hashMap.containsKey(s.charAt(j)) then
9.          currentLen = j - i
10.         if currentLen > maxLen then
11.            maxLen = currentLen
12.         end if
13.         break
14.      else
15.         if j = s.length()-1 then
16.            currentLen = j - i + 1
17.            if currentLen > maxLen then
18.               maxLen = currentLen
19.            end if
20.         else
21.            hashMap.put(s.charAt(j), j)
22.         end if
23.      end if
24.   end for
25.   hashMap.clear()
26. end for
27. return maxLen
```
Running time: $O(n^2)$

## Method 2

We could also solve this problem using dynamic programming.

Define the following:
* $S = ``cabb"$
* $len[i] =$ length of the longest substring without repeating characters ending at index i
* $last[S[i]] =$ the index where character S[i] appeared last time ($last[]$ could be implemented as a hash table, the key is the character and the value is the corresponding index appeared last time)
* $maxlen[i] =$ the longest (maximum) length we have found from index `0` to `i`
* $start =$ the start index of current no-repeating substring

Recurrence:

$$
start =
\begin{cases}
0, & \text{initial value} \\
last[S[i]] + 1, & \text{if } last[S[i]] \ge start \\
start, & \text{otherwise}
\end{cases}
$$

$$
len[i] =
\begin{cases}
0, & \text{if the string is empty} \\
1, & \text{if } i = 0 \\
1 + len[i-1], & \text{if } i \ge 1 \text{ and } S[i] \text { hasn't appeared in current substring} \\
i-start+1, & \text{otherwise}
\end{cases}
$$

$$
maxlen[i] =
\begin{cases}
0, & \text{if the string is empty} \\
len[0], & \text{if } i = 0 \\
\max(maxlen[i-1], len[i]), & \text{if } i \ge 1
\end{cases}
$$