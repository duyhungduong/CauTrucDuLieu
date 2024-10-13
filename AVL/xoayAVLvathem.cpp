#include <stdio.h>
#include <malloc.h>	
typedef int KeyType;
struct Node{
	KeyType Key;
	struct Node* Left;
	struct Node* Right;
	int height;
};
typedef struct Node* Tree;
void makenull(Tree *pRoot){
	(*pRoot) = NULL;
}
Tree BSTInsert(Tree root,KeyType k){

	if (root == NULL){
		root = (struct Node*) malloc (sizeof(struct Node));
		root->Key = k;
		root->Left = NULL;
		root->Right = NULL;
	}
	else if (k < root->Key){
			root->Left = BSTInsert(root->Left, k);
	}
	else if (k > root->Key){
		root->Right = BSTInsert(root->Right, k);
	}
	return root;
}
Tree leftRotate(Tree node){
	Tree temp;
	temp = node->Right;
	node->Right = temp->Left;
	temp->Left = node;
	calculateHeight(node);
	calculateHeight(temp);
	return temp;
}
Tree rightRotate(Tree node){
	Tree temp;
	temp = node->Left;
	node->Left = temp->Right;
	temp->Right = node;
	calculateHeight(node);
	calculateHeight(temp);
	return temp;
}
Tree leftrightRotate(Tree node){
	node->Left = leftrightRotate(node->Left);
	return rightRotate(node);  
}
Tree rightleftRotate(Tree node){
	node->Right = leftrightRotate(node->Right);
	return leftRotate(node);  
}
Tree insertNode(Tree node,KeyType k){
	BSTInsert(node, k);
	calculateHeight(node);
	int balance;
	balance = getBalance(node);
	if (balance>1){
		if (k<node->Left->Key) return rightRotate(node);
		else return leftrightRotate(node);
	}
	if (balance < -1){
		if (k>node->Right->Key) return leftRotate(node);
		else return rightleftRotate(node);
	}
	return node;
}
