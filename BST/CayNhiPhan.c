#include <stdio.h>
#include <malloc.h>

struct Node {
	int Key;
	struct Node* Left, Right;
};
typedef struct Node* Tree;

void makenull(Tree *T){
	(*T)->Left=NULL;
	(*T)->Right=NULL;
}
void inOrder(Tree T){
	if (T!=NULL) {
		printf("%d ",T->Key);
		inOrder(T->Left);
		inOrder(T->Right);  
	}
}
Tree BSTSearch(Tree root,int k){
	if (root != NULL)
		return NULL;
	else if (k == root->Key)
		return root;
	else if (k < root->Key)
		return BSTSearch(root->Left, k);
	else return BSTSearch(root->Right, k);
}
Tree BSTSearch1(Tree root, k,Tree *pParent){
	(*pParent) = NULL;
	Tree p;
	p=root;
	while ( p != NULL){
		if(k==p->Key) 
			return p;
		else {
			(*pParent) = p;
			if (k<p->Key)  p=p->Left;
			else p=p->Right;
		}
	}
	return p;
}
Tree insertNode(Tree root,int k){
	if (root == NULL){
		root = (struct Node*)malloc(sizeof(struct Node));
		root->Key = k;
		root->Left = NULL;
		root->Right = NULL;
	}
	else if (k < root->Key)
		root->Left = insertNode(root->Left, k);
	else if (k > root->Key)
		root->Right = insertNode(root->Right, k);
	return root;
}
BSTDelete(root, k){
	p = BSTSearch(root, k, &parent)
	IF p is Not NULL:
		IF p->Left is Not NULL AND p->Right is Not NULL:
			q = p
			parent = p
			p = p->Right
			WHILE p->Left is not NULL:
				parent = p
				p = p->Left
				q->Key = p->Key
		subtree = p->Left;
		if (subtree == NULL)
			subtree = p->Right;
		if (parent == NULL) //Xóa nút g?c
			root = subTree;
		else if parent->Left==k
			parent->Left = subtree;
		else parent->Right = subTree;
		free(p);
	return root;
}





