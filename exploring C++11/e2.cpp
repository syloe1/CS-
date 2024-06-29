//返回倒数第k个节点
int kthToLast(ListNode* head, int k) {

	ListNode* pa = head;
	ListNode* pb = nullptr;
	for (unsigned int i = 0; i < k; i++) {
		pa = pa->next;
	}
	pb = head;
	while (pa != nullptr) {
		pa = pa->next;
		pb = pb->next;
	}
	return pb->val;
}
