public class ListNode {
	int val;
	ListNode next;

	ListNode() {
	}

	ListNode(int val) {
		this.val = val;
	}

	ListNode(int val, ListNode next) {
		this.val = val;
		this.next = next;
	}

	public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
		int sum = 0;
		int carry = 0;
		int digit = 0;

		// if carryAdded is false, the carry has not been added to the next node
		// if carryAdded is true, the carry has been added to the next node
		boolean carryAdded = false;

		int l1HeadVal;
		int l2HeadVal;

		if (l1 == null) {
			l1HeadVal = 0;
		} else {
			l1HeadVal = l1.val;
		}

		if (l2 == null) {
			l2HeadVal = 0;
		} else {
			l2HeadVal = l2.val;
		}

		sum = l1HeadVal + l2HeadVal;

		if (sum < 10) {
			// Carry for the next node
			carry = 0;
			digit = sum;
		} else if (sum >= 10) {
			carry = 1;

			if (sum == 10) {
				digit = 0;
			} else if (sum > 10) {
				digit = sum % 10;
			}
		}

		// Advance to the next node of l1 (tmpL1 is the next node of l1)
		ListNode tmpL1 = null;
		if (l1 != null) {
			if (l1.next != null) {
				tmpL1 = new ListNode(l1.next.val + carry, l1.next.next);
				carryAdded = true;
			} else {
				tmpL1 = null;
			}
		}

		// Advance to the next node of l2 (tmpL2 is the next node of l2)
		ListNode tmpL2 = null;
		if (l2 != null) {
			if (l2.next != null) {
				if (!carryAdded) {
					tmpL2 = new ListNode(l2.next.val + carry, l2.next.next);
					carryAdded = true;
				} else if (carryAdded) {
					tmpL2 = new ListNode(l2.next.val, l2.next.next);
				}
			} else {
				tmpL2 = null;
			}
		}

		ListNode currentNode = new ListNode(digit);
		ListNode nextNode;
		if (tmpL1 == null && tmpL2 == null && carry == 0) {
			nextNode = null;
		} else if (tmpL1 == null && tmpL2 == null && carry == 1) {
			ListNode carryNode = new ListNode(1);

			// We could use tmpL1 or tmpL2, just need to give 2 parameters for
			// addTowNumbers()
			nextNode = addTwoNumbers(carryNode, tmpL2);
		} else {
			nextNode = addTwoNumbers(tmpL1, tmpL2);
		}

		currentNode.next = nextNode;
		return currentNode;
	}
}