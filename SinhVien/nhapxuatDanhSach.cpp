#include <stdio.h>
#include <malloc.h>
typedef struct {
    char MSSV[10];
    char ten[50];
    float R1,R2,R3;
}SinhVien;
struct Node{
    SinhVien Element;
    struct Node* Next;
};
typedef struct Node* DanhSach;
int append(SinhVien s, DanhSach *pL){
	DanhSach P= (*pL);
	DanhSach T;
//	DanhSach T = locate(s.ID , *pL);
	if (T->Next  == NULL){
		DanhSach I = (struct Node*) malloc (sizeof(struct Node));
		I->Element = s;
		I->Next =NULL;
		if (P==NULL) {
			*pL = I;
			return 1;
		}
		else{
			while (P->Next != NULL) {
				P=P->Next ;
			}
			P->Next = I;
			return 1;
		}
	}
	return 0;	
}
void nhap(DanhSach *L){
	(*L) = (struct Node*) malloc (sizeof (struct Node));
	(*L) -> Next = NULL;
	int i,n=1;
	scanf("%d", &i);
	while (i!=n){
		SinhVien s;
		fgets(s.MSSV, 10 , stdin); 
		fgets(s.ten, 50, stdin);
		scanf("%f%f%f", &s.R1 , &s.R2 , &s.R3 );
		append(s,L);
		i++;
	}
}

void xuat(DanhSach L){
	DanhSach p=L;
	while(p->Next!=NULL)
	{						
		printf("%10s - %50s - %.3f - %.3f - %.3f\n",p->Next->Element.MSSV, 
				p->Next->Element.ten, p->Next->Element.R1, p->Next->Element.R2,
				p->Next->Element.R3);					
		
		p=p->Next;
	}
}
int main () {
	DanhSach L;
	nhap(&L);
	xuat(L);
}
