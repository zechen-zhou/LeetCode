# 0004. Median of Two Sorted Arrays

The run time requirement is $O(log (m+n))$.

This question is classified as *Hard*. But the idea is quite simple: to merge two arrays and find the median.

The challenging part is to deal with the edge cases. For example, double check the indexes of arrays before accessing the elements, just in case the indexes are out of bounds.

Since the run time is $O(m+n)$, then we can only access each element once.

Supposed we have two sorted arrays:
* $X=(x_1, x_2, ...,x_m)$
* $Y=(y_1, y_2, ...,y_n)$

A longer sorted array that is a combination of $X$ and $Y$, i.e. $Z=(z_1, z_2,..., z_k) = merge(X,Y)$ ,(k=m+n)

* Case 1: $x_m \ge y_n$ **Then** $z_k=x_m$

    and $(z_1, z_2,..., z_{k-1}) = merge((x_1, x_2, ...,x_{m-1}), (y_1, y_2, ...,y_n))$

* Case 2: $x_m < y_n$ **Then** $z_k=y_n$

    and $(z_1, z_2,..., z_{k-1}) = merge((x_1, x_2, ...,x_m), (y_1, y_2, ...,y_{n-1}))$