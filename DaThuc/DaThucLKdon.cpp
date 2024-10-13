#include <stdio.h>
#include <malloc.h>
typedef struct {
    double he_so;
    int bac;
} DonThuc;
struct Node{
    DonThuc e;
    struct Node* Next;
};
typedef struct Node* Position;
typedef Position DaThuc;
DaThuc khoitao(){
	DaThuc d;
	d = (struct Node*) malloc (sizeof(struct Node));
	
	d->Next = NULL;
	return d; 
}
void chenDonThuc(DonThuc s, DaThuc *pD){
	DaThuc d = (*pD);
	int i=0;
	while (d->Next != NULL) {
		DonThuc a = d->Next->e ;
		if (a.bac == s.bac)  {
			(*pD)->Next->e->he_so += s.he_so ;
			i=1;
			break;
		}
		d= d->Next ; 
	}
	if (i==0) {
		DaThuc p=(*pD) 
		while (p->Next != NULL) {
			DonThuc b= d->Next->e ;
			
		}
	}
}
