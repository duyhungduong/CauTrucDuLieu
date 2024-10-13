#include <stdio.h>
#include <ctype.h>
#include <malloc.h>
struct Node{
   char KyTu;
   struct Node* Next;
};
typedef struct Node* Cau;
void hienthi(Cau d){
    Cau p;
    p=d;
    while (p->Next!=NULL){
        printf("%c", p->Next->KyTu);
        p=p->Next;
    }
    printf("\n");
}
void chuan(Cau *pd){
	Cau d = (*pd) ;
	int i=0;
	while (d->Next != NULL ) {
		if (i==0 && d->KyTu != ' ' ){
			if (d->Next->KyTu >= 'a' && d->Next->KyTu <= 'z')
				d->Next->KyTu -=32;
		}else if ((i > 0 && d->Next->KyTu == ' '  )){
			d=d->Next ;
			if (d->Next->KyTu >= 'a' && d->Next->KyTu <= 'z')
				{
					d->Next->KyTu -=32;
				}
		}
		else{
			if (d->Next->KyTu >='A' && d->Next->KyTu <= 'Z')
				d->Next->KyTu += 32;
		}
		i++;
		d=d->Next;
	}
}

int sotu(Cau d){
	int i=0;
	Cau p=d;
	if (p->Next!= NULL && p->Next->KyTu != ' ') {
		i++;
	}
	while (p->Next!=NULL){
		if ((p->Next->KyTu == ' ') && (p->Next->Next->KyTu != ' ')) i++;	
		p=p->Next;
	}
	return i;
}



int main () {
		//	Chuyen doi In hoa tung tu dau tien trong cau (Cau 10)
//	struct Node* t;
//
//Cau d = (struct Node*)malloc(sizeof(struct Node));
//d->Next=NULL;
//
//t = (struct Node*)malloc(sizeof(struct Node));
//t->KyTu='O';
//t->Next=d->Next;
//d->Next=t;
//
//t = (struct Node*)malloc(sizeof(struct Node));
//t->KyTu='d';
//t->Next=d->Next;
//d->Next=t;
//
//t = (struct Node*)malloc(sizeof(struct Node));
//t->KyTu=' ';
//t->Next=d->Next;
//d->Next=t;
//
//t = (struct Node*)malloc(sizeof(struct Node));
//t->KyTu='I';
//t->Next=d->Next;
//d->Next=t;
//
//chuan(&d);
//hienthi(d);

struct Node* t;

Cau d = (struct Node*)malloc(sizeof(struct Node));
d->Next=NULL;

t = (struct Node*)malloc(sizeof(struct Node));
t->KyTu='O';
t->Next=d->Next;
d->Next=t;

t = (struct Node*)malloc(sizeof(struct Node));
t->KyTu='d';
t->Next=d->Next;
d->Next=t;

t = (struct Node*)malloc(sizeof(struct Node));
t->KyTu=' ';
t->Next=d->Next;
d->Next=t;

t = (struct Node*)malloc(sizeof(struct Node));
t->KyTu='I';
t->Next=d->Next;
d->Next=t;

t = (struct Node*)malloc(sizeof(struct Node));
t->KyTu=' ';
t->Next=d->Next;
d->Next=t;

t = (struct Node*)malloc(sizeof(struct Node));
t->KyTu='I';
t->Next=d->Next;
d->Next=t;

hienthi(d); 
printf("%d", sotu(d));
}
