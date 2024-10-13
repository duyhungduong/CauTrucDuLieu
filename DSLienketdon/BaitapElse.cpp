#include <stdio.h> 
#include <malloc.h> 
typedef int ElementType;
struct Node{
	ElementType Element;
	struct Node* Next;
};
typedef struct Node* List;
typedef struct Node* Position;

Position locate(ElementType x, List L){
	List p;
	p=L;
	int found=0;
	while ((p->Next != NULL)&&found==0) {
		if (p->Next->Element == x) found=1;
		else p=p->Next ;
	}
	return p;
}
void deleteList(Position P, List *pL ){
	Position T;
	if (P->Next != NULL) {
		T = P->Next;
		P->Next = T->Next;
		free(T);
	}
}
void append(int x, List *L){
	List p;
	p= (*L);
	List T = (struct Node*) malloc (sizeof(struct Node));
	T->Element = x;
	T->Next =NULL; 
	while (p->Next != NULL) {
		p=p->Next;
	}
	p->Next =T;
}
void addFirst(int x, List *pL){
	List p;
	p= (*pL);
	List T = (struct Node*) malloc (sizeof(struct Node));
	T->Element = x;
	T->Next = NULL;
	T->Next = p->Next ;
	p->Next = T;
}

void insertList(int x, Position p, List *pL){
	List T;
	T=(struct Node*)malloc(sizeof(struct Node));
	T->Element = x;
	T->Next = p->Next ;
	p->Next = T; 
}

void printOddNumbers(List L){
	List p;
	p=L;
	while (p->Next != NULL){
		if (p->Next->Element % 2 == 1 ) printf("%d ", p->Next->Element);
		p=p->Next;
	}
}
void copyEvenNumbers(List L1, List *pL2){
	List p;
	p=L1;
	(*pL2) = (struct Node*) malloc (sizeof(struct Node));
	(*pL2) -> Next = NULL;
	while (p->Next != NULL){
		if (p->Next->Element % 2 == 0 ){
			append(p->Next->Element, pL2 ); 
		}
		p=p->Next ;
	}
}
void makenullList(List *L){
	(*L) = (struct Node*) malloc (sizeof(struct Node));
	(*L) -> Next = NULL;
}
int member(int x, List L){
	int found =0;
	Position P =L  ;
	while ((P->Next != NULL) && found == 0){
		if ((P->Next->Element == x)) found=1;
		else P=P->Next ;
	}
	return found;
}

void normalize(List *pL){
	List p,q;
	p = (*pL);
	while (p->Next != NULL){
		q= p->Next;
		while (q->Next!=NULL){
			if (p->Next->Element == q->Next->Element ) 
			deleteList(q, pL);
			else q=q->Next ; 
		} 
		p=p->Next;
	}
}

List difference(List L1, List L2){
	List L,p;
	L = (struct Node*) malloc (sizeof(struct Node));
	L->Next = NULL;
	p=L1;
	while (p->Next != NULL ){
		if (member(p->Next->Element, L2)==0) append(p->Next->Element, &L);
		p=p->Next;
	}
	return L;
}
void removeAll(int x, List *pL){
	List p;
	p=(*pL);
	while (p->Next != NULL){
		Position q = locate(x, *pL) ;
		if ( q->Next == NULL ) p=p->Next ;
		else deleteList(q,pL); 
	}
}

List intersection(List L1, List L2){
	List L;
	makenullList(&L);
	while (L1->Next != NULL) {
		if (member(L1->Next->Element , L2)) append(L1->Next->Element, &L) ;
		L1= L1->Next ;
	} 
	return L;
}


int main () {
List L;
L=(struct Node*)malloc(sizeof(struct Node));	
L->Next=NULL;
Position p = L;
insertList(5,p,&L);
p=p->Next;
insertList(10,p,&L);
	
p=L;
while(p->Next!=NULL)
{
	printf("%d ",p->Next->Element);
	p=p->Next;
}
printf("\n");		
}
