This question is quit straightforward. We need to add the digits stored in two linked lists from head to tail, carrying any overflow into the next node.

I was overlooked this question, the challenging part was to deal with the single linked list. Due to the limitation of the ListNode setup, the next node needed to be specified while creating a node. However, how do we know the next node while working on the current node with a single linked list, a recursive call could be a potential solution.

In addition, using a **dummy node + moving tail pointer** is a much simpler way to build a new linked list in problems like this.
