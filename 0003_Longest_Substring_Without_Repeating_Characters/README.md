# 0003. Longest Substring Without Repeating Characters

This question is asking for the **length** of the longest substring **without duplicating characters**.

We might need a variable to keep track of the longest length. To check duplicates, a key-value mapping is an efficient way. For example, using a hash table (**Insertion and Search will be $O(1)$ time**). Last but not least, we need to think about how to compute the length of substring in each iteration.

Example: `cabb`

1. The first iteration:

```
c  a  b  b
^        ^
Start    End
```

| Key     | Value |
|---------|-----|
| c  | 0  |
| a  | 1  |
| b  | 2  |
| b  | 3  |

From the table above, `Start` points to $c$ and `End` points to $b$. The longest substring without repeating characters is `cab`, the length is `End - Start = 3-0 = 3`.

2. The second iteration

```
c  a  b  b
   ^     ^
 Start   End
```

| Key     | Value |
|---------|-----|
| a  | 0  |
| b  | 1  |
| b  | 2  |

From the table above, `Start` points to $a$ and `End` points to $b$. The longest substring without repeating characters is `ab`, the length is `End - Start = 2-0 = 2`.

3. The third iteration

```
c  a  b  b
      ^  ^
   Start End
```

| Key     | Value |
|---------|-----|
| b  | 0  |
| b  | 1  |

From the table above, `Start` points to the first $b$ and `End` points to the second $b$. The longest substring without repeating characters is `b`, the length is `End - Start = 1-0 = 1`.

4. The fourth iteration

```
c  a  b  b
         ^
        Start (End)
```

| Key     | Value |
|---------|-----|
| b  | 0  |

From the table above, both `Start` and `End` point to $b$. The longest substring without repeating characters is `b`, the length is 1 (special case).