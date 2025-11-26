public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
	ListNode dummyNode = new ListNode(0);

	// The tail pointer points to dummyNode (both dummyNode and tail are pointing to the same node that has value=0 and next=null)
	ListNode tail = dummyNode;

	int sum;
	int carry = 0;

	// It represents the rightmost digit for sum
	int digit;

	while (l1 != null || l2 != null || carry == 1) {
		// Reset sum and digit
		sum = 0;
		digit = 0;

		// Add the previous carry
		sum += carry;

		if (l1 != null) {
			sum += l1.val;
			l1 = l1.next;
		}

		if (l2 != null) {
			sum += l2.val;
			l2 = l2.next;
		}

		carry = sum / 10;
		digit = sum % 10;

		tail.next = new ListNode (digit);
		tail = tail.next;
	}

	return dummyNode.next;
}