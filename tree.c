#include <stdio.h>
#include <malloc.h>

typedef struct binary_tree {
	char data;
	struct binary_tree *lchild;
	struct binary_tree *rchild;
}TREE, *PTREE;

// 这里传入指针是因为要递归调用函数，函数里面要改变传入的数据，所以要传地址  PTREE *tree === struct binary_tree ** tree == TREE ** tree
void insert(PTREE *tree, char data) {
	PTREE temp = (PTREE) malloc(sizeof(TREE));
	if (temp == NULL) {
		return;
	}
	// 这个树为空，则要建立树
	if (!tree) {
		tree->data = data;
		tree->lchild = tree->rchild = NULL;
		tree = temp;
		return ;
	}

	// 大于节点的数据放在右边
	if (data > tree->data) {
		insert(&tree->rchild, data);
	} else if (data < tree->data) {
		insert(&tree->lchild, data);
	}

}

int main(void) {
	return 0;
}



#include <stdio.h>
//arr = {1,2,3,4,5}
void xier_sort(int arr[], int &gap, int count) {
	static int is_return = 1;
	if (gap == -1) {
		gap = count / 2;
	}
	else {
		gap /= 2;
	}
	if (is_return == 0) {
		return;
	}
	if (gap == 0 && is_return == 1) {
		gap = 1;
		is_return = 0;
	}
	int i;
	int temp;
	for (i = 0; i < count && (i + gap < count); i++) {
		if (arr[i] > arr[i + gap]) {
			temp = arr[i];
			arr[i] = arr[i + gap];
			arr[i + gap] = temp;
		}
	}
	xier_sort(arr, gap, count);
}

int main(void) {

	//int arr[] = { 99,10,5,6,7,3,55,34,77,31,23 ,13};
	int arr[] = { 1,5,6,3,99,45,64,22,34,45,56,2 };
	int count = sizeof(arr) / sizeof(arr[1]);
	int a = -1;
	int b;
	xier_sort(arr, a, count);
	int i = 0;
	for (; i < count; i++) {
		printf("%d\n", arr[i]);
		
	}
	scanf_s("%d", &b);

	return 0;
}
main() {
	
}
