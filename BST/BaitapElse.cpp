#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct Node{
      int Key;
      struct Node *Left, *Right;
};
typedef struct Node* Tree;
Tree initTree(){
	Tree T;
	T = (struct Node*) malloc (sizeof(struct Node));
	T = NULL;
	return T;
}
int isEmpty(Tree T){
	return T == NULL;
}

void insertNode(int x, Tree *T) {
	if ((*T)==NULL) {
		(*T) = (struct Node*) malloc (sizeof(struct Node));
		(*T)->Key =x;
		(*T)->Left = NULL;
		(*T)->Right = NULL;
}
else {
	if ((*T)->Key == x){
		return;
	}
	else {
		if (x < (*T) ->Key )
		insertNode(x, &((*T)->Left) );
	else 
		insertNode(x, &((*T)->Right) );
	}	
}
}

Tree getNext(int x, Tree T){
	Tree p,a ;
	p=T;
	a = NULL;
	if (p->Key == x ){
		p=p->Right ;
		while (p!=NULL) {
			a = p;
			p=p->Left ;
		}
		return a;
	}else{
		while (p!=NULL){
		if (x==p->Key){
			if (p->Right != NULL) return p->Right;
			else return NULL ;
		}
		else {
			if (x < p->Key ) p=p->Left ;
			else p=p->Right ;
		}
	}
	return p;
	}	
}
void printPath(int x, Tree T){
	Tree p;
	p=T;
	while (p!= NULL) {
		if (p->Key != x){
			printf("%d ", p->Key);
			if (x < p->Key ) p=p->Left ;
			else p=p->Right ;
		}else{
			printf("%d -> Tim thay", p->Key );
			return ; 
		}
	}
	printf("-> Khong thay");
}
void inOrder(Tree T){
    if (T!=NULL){

        inOrder(T->Left );

        printf("%d ",T->Key );

        inOrder(T->Right );
    }
}
Tree getPrevious(int x, Tree T){
	Tree p, a ,b, c;
	p=T;
	c = NULL;
	a = NULL;
	b=T;
	b=b->Right ;
	while (b!=NULL) {
		c = b;
		b=b->Left ;
	}
	if (c->Key == x) return T;
	if (p->Key == x ){
		p=p->Left ;
		while (p!=NULL) {
			a = p;
			p=p->Right ;
		}
		return a;
	}else{
		while (p!=NULL){
		if (x==p->Key){
			return p->Left ;
		}
		else {
			if (x < p->Key ) p=p->Left ;
			else p=p->Right ;
		}
	}
	return p;
	}	
}
int main () {
Tree T=NULL;
Tree p;
int x;

insertNode(27,&T);
insertNode(12,&T);
insertNode(40,&T);
insertNode(4,&T);
insertNode(20,&T);
insertNode(34,&T);
insertNode(30,&T); 
insertNode(50,&T); 
x=30;
inOrder(T);
printf("\n"); 
p = getPrevious(x,T);
if (p==NULL)
   printf("%d khong co nut dung truoc",x);
else printf("Nut dung truoc la %d",p->Key);
}
