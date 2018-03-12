#include <stdio.h>
#include <malloc.h>

typedef int elementype;
typedef struct Node {
	elementype data;
	struct Node *pNext;
}NODE, *PNODE;

// 定义一个栈,栈的指针是指向链表的，栈可以理解为一种特殊的链表
typedef struct stack {
	PNODE pTop; //栈顶指针
	PNODE pBottom; //栈底指针
}STACK, *PSTACK;

//创建一个空栈
void Create_stack(PSTACK S) {
	S->pBottom = (PNODE) malloc(sizeof(struct Node));
	if (S->pBottom == NULL) {
		printf("Memory allocation failure");  
		return -1;
	}

	S->pTop = s->pBottom;
	S->pTop->data = 0;
	S->pTop->pNext = NULL; //防止出现野指针
}

//入栈
void Push_Stack(STACK S, int val) {
	PNODE p = (PNODE) malloc(sizeof(NODE));
	if (p == NULL) {
		printf("Memory allocation failure");  
		return -1;
	}
	p->data = val;
	p->pNext = S->pTop; // 新加的元素的放在链表头，所以他的下一个就是以前的头节点
	S->pTop = p; //当前栈顶指向p，所以p的下一个节点就是栈的第二个元素
}

// 出栈
bool Pop_Stack(STACK S, int *val) {
	if (S == NULL) {
		return false;
	}
	PNODE p = S->pTop;
	if (p == NULL) {
		return 0;
	}

	*val = p->data;
	S->pTop = p->pNext;
	// 要记得释放内存，指针为空，防止出现野指针，养成习惯
	free(p);
	p = NULL;
	return true;
}