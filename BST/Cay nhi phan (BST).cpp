#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct Node{

      int Key;

      struct Node *Left, *Right;

};
typedef Node* Tree;

Tree initTree(){
	Tree T;
	T = NULL;
	return T;
}
int  isEmpty(Tree T){
	return T==NULL;
}

Tree insertNode(int X, Tree T ){
	if (T==NULL  ){
		T = (struct Node*) malloc (sizeof (struct Node));
		T->Key = X;
		T->Left = NULL;
		T->Right = NULL; 
	}
	else if (X < T->Key ){
		T->Left  = insertNode(X, T->Left);
	}
	else if (X > T->Key){
	
	T->Right = insertNode(X, T->Right); }
	return T;
}
void inOrder(Tree T){
    if (T!=NULL){

        inOrder(T->Left );

        printf("%d ",T->Key );

        inOrder(T->Right );
    }
}

void preOrder(Tree T){
    if (T!=NULL){

        printf("%d ",T->Key );

        preOrder(T->Left);
    
        preOrder(T->Right);
    }
}
void posOrder(Tree T){
    if (T!=NULL){

        posOrder(T->Left);

        posOrder(T->Right);

        printf("%d ",T->Key );
    }
}

Tree searchNode(int x, Tree T){

if (T == NULL){
return NULL;
}
else if (x == T->Key){
return T;}
else if (x < T->Key){
return searchNode(x , T->Left);}
else return searchNode(x , T->Right);
}

Tree getParent(int x, Tree T){
	Tree pParent, p;
	pParent = NULL;
	p=T;
	while (p!=NULL){
		if (x==p->Key) return pParent; 	
		else {
			pParent = p;
			if ( x<p->Key) p=p->Left;
			else p=p->Right;
		}
	}
return pParent;
}

Tree deleteNode(int  x, Tree T){
	Tree p,q,parent,subtree;
	parent = NULL;
	p=T;
	while (p!= NULL){
		if (x == p->Key ) break;
		else{
			parent = p;
			if (x < p->Key  ) p = p->Left ;
			else p=p->Right ;
		}
	}
if (p != NULL){
	if ((p->Left != NULL) && (p->Right != NULL)){
		q = p;
		parent = p;
		p = p->Right;
		while (p->Left != NULL){
			parent = p;
			p = p->Left;
		}
		q->Key = p->Key;
		}
	subtree = p->Left;
	if (subtree == NULL)
	subtree = p->Right;
	if (parent == NULL) // TH xoa nut root
	T = subtree;
	else if (parent->Left==p)
	parent->Left = subtree;
	else parent->Right = subtree;
	free (p);
}
return T;
}


Tree rightSibling(int x, Tree T){
	Tree conphai, p;
	conphai = NULL;
	p=T;
	while (p!=NULL){
		if (x==p->Key) return conphai->Right ; 
		else {
			conphai = p;
			if ( x<p->Key) p=p->Left;
			else p=p->Right;
		}
		
	}
	return conphai->Right ;
}

void printPath(int x, Tree T){
	Tree p;

	p=T;
	while (p!=NULL){
		printf("%d ", p->Key);
		if (x==p->Key) {
			printf("-> Tim thay"); break;
		}
		else {
			
			if ( x<p->Key) p=p->Left;
			else p=p->Right;
			
		}
		
	}
	if (p == NULL ) printf ("-> Khong thay");
}


int max(int v1, int v2){
	return ((v1 > v2) ? v1 : v2);
}
int getHeight(Tree T){
	if (T == NULL ) return -1;
	int height= 0 ;
	
	Tree Leftchild, Rightchild;
	if (T!= NULL) {
		Leftchild = T->Left ;
		Rightchild = T->Right ;
	}
	else {
		Leftchild = NULL;
		Rightchild = NULL ;
	}
	if (T!= NULL) {
		
		if (T->Left == NULL && T->Right == NULL ) height = 0 ;
		else
		{
			height = max (getHeight(Leftchild ), getHeight(Rightchild )  ) +1;
		}
	}
	return height;
}

int hNode(int x, Tree T){
	Tree p;
	p=T;
	if ( p == NULL ) return -1;

	if (p->Key == x) {
		if (p->Left == NULL && p->Right == NULL ) return 0;
		int l=0, r= 0;
		if (p->Left != NULL ) 
			l=hNode(p->Left->Key , p->Left ) ;
		if (p->Right != NULL) 
			r=hNode(p->Right->Key , p->Right );
		return (l>r ? l:r) +1 ; 
	}
	else if (p->Key > x){
		return hNode(x, p->Left ) ;	
	}
	else return hNode(x, p->Right ); 
	
}

int main (){
Tree T=NULL;
int x;

T=insertNode(5,T);
T=insertNode(2,T);
T=insertNode(10,T);
T=insertNode(-4,T);
T=insertNode(3,T);
T=insertNode(9,T);
T=insertNode(17,T); 
T=insertNode(13,T); 
T=insertNode(15,T);
//x = 27;
printf("Chieu cao %d la %d",x,hNode(x,T));
printf("\n Danh sach la:");
inOrder(T);
//deleteNode(x,T);
deleteNode(10,T);
printf("\n Danh sach la:");
inOrder(T);  


}

