//十字链表存储稀疏矩阵
#include<stdio.h>
#include<stdlib.h>
#define OK 1 
#define OVERFLOW -2
typedef int Status;
typedef int ElemType;
typedef struct Node{
	ElemType e;
	int r,c;//分别代表行和列下标
	struct Node* right;
	struct Node* down;
}Node,*Nodeptr;
typedef struct{
	Nodeptr* rhead,*chead;//两个Nodeptr数组的下标
	int r_nums,c_nums,e_nums;//行数，列数，非零元个数
}Matrix;

Status create_matrix(Matrix* m_add){
	int r_nums,c_nums,e_nums;
	Nodeptr tmp;
	scanf("%d %d %d",&r_nums,&c_nums,&e_nums);
	m_add->r_nums = r_nums;
	m_add->c_nums = c_nums;
	m_add->e_nums = e_nums;
	if(!(m_add->rhead = (Nodeptr*)calloc(c_nums+1,sizeof(Nodeptr))))
	    exit(OVERFLOW);
	if(!(m_add->chead = (Nodeptr*)calloc(c_nums+1,sizeof(Nodeptr))))
	    exit(OVERFLOW);
	//将这些结点的值都初始化
	for(int i=0;i<e_nums;i++){
		Nodeptr new_node = (Nodeptr)malloc(sizeof(Node));
		if(!new_node)
		    exit(OVERFLOW);
		scanf("%d %d %d",&new_node->r,&new_node->c,&new_node->e);
		//为新结点寻找插入位置
		if(m_add->rhead[new_node->c] == NULL || m_add->rhead[new_node->c]->r > new_node->r){
			new_node->down = m_add->rhead[new_node->c];
			m_add->rhead[new_node->c] = new_node;
		}
		else{
			for(tmp = m_add->rhead[new_node->c]; tmp->down&&tmp->down->r < new_node->r;tmp=tmp->down );
			new_node->down = tmp->down;
			tmp->down = new_node;
		}
		if(m_add->chead[new_node->r] == NULL || m_add->chead[new_node->r]->c>new_node->c){
			new_node->right = m_add->chead[new_node->r];
			m_add->chead[new_node->r] = new_node;
		}
		else{
			for(tmp = m_add->chead[new_node->r];tmp->right&& tmp->right->c < new_node->c;tmp=tmp->right);
			new_node->right = tmp->right;
			tmp->right = new_node;
		}
	}
	return OK;
}

//按行打印矩阵，每个元素用（行下标，列下标，元素值）三元组来表示
void print_matrix_byrows(Matrix* m_add){
	Nodeptr tmp;
	for(int i = 1;i<=m_add->r_nums;i++){
		for(tmp = m_add->chead[i];tmp!=NULL;tmp = tmp->right){
			printf("(%d,%d):%d\t",tmp->r,tmp->c,tmp->e);
		}
		printf("\n");
	}
}

int main(){
	Matrix m;
	create_matrix(&m);
	print_matrix_byrows(&m);
	return 0;
}
