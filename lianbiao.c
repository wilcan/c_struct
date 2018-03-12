#include <stdio.h>
#include <malloc.h>

typedef struct Node {
	int data;
	struct Node *pNext; // 链表下一个元素也是结构体，pNext是指向下一个元素的Node的地址
}NODE, *PNODE;

/**
 * 创建一个单向链表，返回链表的头指针
 * int len  链表元素的个数
 */
PNODE Create_List(int len) {
	int i;
	int val;
	PNODE pHead = (PNODE) malloc(sizeof(NODE));
	if (pHead == NULL) {
		printf("Memory allocation failure");
		return -1;
	}

	PNODE pTail = pHead; 
	pHead->pNext = NULL;// 应该是等价于 pTail->pNext = NULL;
	for (i = len; i > 0; i--) {
		PNODE p = (PNODE) malloc(sizeof(NODE));
		if (p == NULL) {
			printf("Memory allocation failure");
			return -1;
		}

		/*
			int val;
			scanf("%d", &val);
			p->data = val;
		*/
		p->data = 0;

		// 让当前元素的pnext指向p
		pTail->pNext = p;
		p->pNext = NULL;
		pTail = p;
	}

	return pHead;
}


/**
 *  指定位置插入数据
 *  int pos 第几位插入数据 
 *  int val 插入的数据 
 */
bool Insert_list(PNODE pHead, int pos, int val) {
	int i = 0;
	PNODE p = pHead;
	while ((p != NULL) && (i < pos - 1)) {
		p = p->pNext;
		i++;
	}

	if (p == NULL || i > pos - 1) {
		return false;
	} 

	PNODE q = (PNODE) malloc(sizeof(NODE));
	q->data = val;
	q->pNext = p->pNext;
	p->pNext = q;
	return 1;
}

/**
 * 删除指定位置的元素
 */
bool Delete_list(PNODE pHead, int pos) {
	int i = 0;
	PNODE p = pHead;
	while ((p != NULL) && (i < pos - 1)) {
		p = p->pNext;
		i++;
	}

	if (p == NULL || i > pos - 1) {
		return false;
	} 

	PNODE q = p->pNext;
	p->pNext = q->pNext;
	free(q);
	q = NULL;  // 必须设置为空，否则就是野指针，指针指向的数据找不到了
}


int Lenth_list(PNODE pHead) {
	int i = 0;
	PNODE p = pHead->pNext;
	while (p != NULL) {
		i++;
		p = p->pNext;
	}

	return i;
}