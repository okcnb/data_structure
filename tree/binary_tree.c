#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct Node{
	ElemType data;
	struct Node* lchild,*rchild;
}Node;

//先序递归建立二叉树
Node* pre_create_tree(){
	char ch;
	Node* new_node;
	scanf("%c",&ch);
	getchar();
	if(ch == '#')return NULL;
	new_node = (Node*)malloc(sizeof(Node));
	new_node->data = ch;
	new_node->lchild = pre_create_tree();
	new_node->rchild = pre_create_tree();
	return new_node;
}

//先序遍历打印二叉树
void pre_print_tree(Node* node){
	if(node==NULL)return;
	printf("%c\t",node->data);
	pre_print_tree(node->lchild);
	pre_print_tree(node->rchild);
}

//中序遍历打印二叉树
void in_print_tree(Node* node){
	if(node==NULL)return;
	in_print_tree(node->lchild);//先递出去，递到最后，在归来的时候打印
	printf("%c\t",node->data);
	in_print_tree(node->rchild);
}

//后序遍历打印二叉树
void post_print_tree(Node* node){
	if(node==NULL)return;
	post_print_tree(node->lchild);
	post_print_tree(node->rchild);
	printf("%c\t",node->data);
}


int main(){
	Node* root = pre_create_tree();
	post_print_tree(root);
	return 0;
}
