This is the first problem I solved on LeetCode.

This question is similar to a matching problem, finding two numbers, $a$ and $b$, such that $a + b = target$. A brute force approach is to check all possible pairs of numbers, which takes $O(n^2$) time.

As we need to iterate through all the numbers, the main challenge is deciding what to track during the traversal. Once we determine that, we can come up with a more efficient solution.

Because the problem is essentially about matching pairs, a hash table **(Insertion and Search will be $O(1)$ time)** could be used. Let the keys be all possible numbers, and the values be their corresponding indexes. Initially, each number can be considered as $a$, and then $b = target - a$, if $b$ exists in the hash table, the solution consists of the indices of $a$ and $b$.

Example: `nums = [3, 4, 7, 5], target = 9`
| Key     | Value |
|---------|-----|
| 3  | 0  |
| 4  | 1  |
| 7  | 2  |
| 5  | 3  |

1. $a=3$, then $b=target-a=6$, since there's no key equal to 6, we move on to the next key.
2. $a=4$, then $b=target-a=5$, since the last key in the hash table is 5, the solution is the corresponding values 0 and 3.