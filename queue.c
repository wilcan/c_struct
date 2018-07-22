#include <stdio.h>
#include <malloc.h>

typedef struct Node{
	char data;
	struct Node *pNext;
}NODE PNODE;


typedef struct Queue{
	struct Node *PTop;
	struct Node *PTail;
}QUEUE, *PQUEUE;



struct Node *create_queue() {
	PNODE p = (PNODE) malloc(sizeof(NODE));
	if (p == NULL) {
		return NULL;
	}

	p->pNext = NULL;
	struct Queue * q = (PQUEUE) malloc(sizeof(struct Queue));
	if (q == NULL) {
		return NULL;
	}
	q->PTop = p;
	q->PTop = q->PTail;
	return q;
}
//patch

//入队列，在尾部插入
bool push_queue(struct Queue *q, char data) {
	PNODE p = (PNODE) malloc(sizeof(NODE));
	if (p == NULL) {
		return false;
	}
	p->data = data;
	p->pNext = NULL;

	PNODE last_p = q->PTail;
	last_p->pNext = p;
	q->PTail = p;
	return true;
}

// 出队列，在头部取出
int pop_queue(PQUEUE q, char *val) {
	PNODE p = q->PTop;
	*val = p->data;
	q->PTop = p->pNext;
	free(p);
	p = NULL;
	return true;
}