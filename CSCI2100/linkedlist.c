#include <stdio.h>
#include <stdlib.h>
//define


typedef int eleT;

typedef struct cellT{
eleT element;
struct cellT *next;
} cellT;

struct CDT{
cellT *head;
cellT *tail;
};

typedef struct CDT *ADT;

//function
ADT createlist(){
ADT list;
list=(ADT)malloc(sizeof(struct CDT));
list->head=NULL;
list->tail=NULL;
return list;
}

void addlist(ADT list,eleT input){
cellT *new;
new =(cellT*)malloc(sizeof(cellT)); //remember give size!
new->next=NULL;
new->element=input;


if ((list->head)==NULL){
    list->head=new;}
    else {list->tail->next=new;

        };

/*list->head=new;*///test
printf("%d",list->head->element);
printf("so far so good\n");
list->tail=new;
printf("so far so good\n");
}

eleT removelist(ADT list){
if (list->head==NULL){return 999;}
if (list->head==list->tail){list->tail==NULL;}
eleT output=list->head->element;
list->head=list->head->next;
return output;
}

void listlist(ADT list){
cellT *now=list->head;
while (now!=NULL)

{printf("%d\n",now->element);printf("so far so good\n");
now=now->next;
}
}

int main(){
ADT reallist=createlist();
int a;
eleT b;
while (a!=-1){
scanf("%d",&a);

if (a==1){
    scanf("%d",&b);
    addlist(reallist,b);

}

if (a==2){
    printf("%d",removelist(reallist));

}


if (a==3){
    listlist(reallist);
}



}
printf("endlo");
return 0;
}
