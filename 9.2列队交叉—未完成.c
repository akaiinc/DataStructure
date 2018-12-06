/*??将队列2穿插入到队列一*/
pNode *cross2(pNode* p1, pNode*p2) {
	dNode* tem1, *tem2;
	tem1 = p1->front;
	tem2 = p2->front;
	if (isEmpty(p1)) return p2;
	while ((tem1->next)&&(tem2->next)) {

		tem1 = tem1->next;
		tem2 = tem2->next;
	}
	return p1;
}