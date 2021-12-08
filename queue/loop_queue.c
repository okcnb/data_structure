//循环队列,动态分配存储空间
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
typedef int ElemType;
typedef struct{
	ElemType *base;
	int front,rear;//头尾指针
}Queue;

Status init_queue(Queue* q_add){
	q_add->base = (ElemType*)malloc(sizeof(ElemType)*MAX_SIZE);
	if(!q_add->base)
		exit(OVERFLOW);
	q_add->front = q_add->rear = 0;
	return OK;
}

Status en_queue(Queue* q_add,ElemType e){
	//判满
	if((q_add->rear+1)%MAX_SIZE==q_add->front)
		return ERROR;
	q_add->base[q_add->rear] = e;
	q_add->rear = (q_add->rear+1)%MAX_SIZE;
	return OK;
}

Status de_queue(Queue* q_add,ElemType* e_add){
	//判空
	if(q_add->front == q_add->rear)
		return ERROR;
	*e_add = q_add->base[q_add->front];
	q_add->front = (q_add->front+1)%MAX_SIZE;;
	return OK;
}

Status destroy_queue(Queue* q_add){
	free(q_add->base);
	return OK;
}

Status print_queue(Queue* q_add){
	for(int i=q_add->front;i<q_add->rear;i++){
		printf("%d\t",q_add->base[i]);
	}
	printf("\n");
}

int main(){
	Queue q;
	ElemType e;
	init_queue(&q);
	en_queue(&q,3);
	en_queue(&q,4);
	en_queue(&q,5);
	de_queue(&q,&e);
	printf("de:%d\n",e);
	print_queue(&q);
	return 0;
}
