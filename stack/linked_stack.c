//链栈的实现
#include<stdio.h>
#include<stdlib.h>
#define ERROR -1
#define OVERFLOW -2
#define OK 1
#define INIT_SIZE 100
#define CREMENT 10
typedef int Status;
typedef int ElemType;
typedef struct{
	ElemType* base;
	ElemType* top;
	int stack_size;//栈的当前容量
}Stack;

Status init_stack(Stack* s){//初始化栈
	s->top = s->base = (ElemType*)malloc(sizeof(ElemType)*INIT_SIZE);
	if(!s->base){
		exit(OVERFLOW);
	}
	s->stack_size = INIT_SIZE;
	return OK;
}	

Status push(Stack* s,ElemType e){//入栈
	if(s->top - s->base >= s->stack_size){
		s->base = (ElemType*)realloc(s->base,sizeof(ElemType)*(s->stack_size+CREMENT));
		if(!s->base){
			exit(OVERFLOW);
		}
		s->top = s->base+s->stack_size;
		s->stack_size += CREMENT;
	}
	*(s->top++) = e;
	return OK;
}


Status pop(Stack* s,ElemType* e){//出栈
	if(s->top == s->base){
		return ERROR;
	}
	*e = *(--s->top);
	return OK;
}

void print_stack(Stack* s){
	ElemType* tmp = s->base;
	while(tmp!=s->top){
		printf("%d\t",*tmp);
		tmp++;
	}
	printf("\n");
}

int main(){
	Stack s;
	ElemType e;
	init_stack(&s);
	push(&s,2);
	push(&s,3);
	push(&s,4);
	push(&s,5);
	pop(&s,&e);
	print_stack(&s);
	return 0;
}




