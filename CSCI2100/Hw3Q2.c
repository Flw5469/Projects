#include <stdio.h>
typedef struct cellT{

    int num;
    struct cellT* next;
    struct cellT* last;
} cellT;

void addcell(cellT *first,int b){

    cellT* newcell;
    newcell=(cellT*)malloc(sizeof(cellT));
    newcell->num=b;


    if (first->next==NULL){

        first->next=newcell;
        first->last=newcell;
        newcell->last=first;
        newcell->next=first;

    }
    else {

        first->last->next=newcell;
        newcell->last=first->last;
        newcell->next=first;
        first->last=newcell;
    }
};







int findcell(cellT *first,int b){//output position, put to front.

cellT *newcell;
newcell=first->next;
int k=1;
while (newcell->num!=b)
{
    newcell=newcell->next;
    k++;
}

//swapping here



newcell->last->next=newcell->next;
newcell->next->last=newcell->last;

first->next->last=newcell;
newcell->next=first->next;
newcell->last=first;
first->next=newcell;

return k;
};



int main(){
struct cellT *first;
first=(cellT*)malloc(sizeof(cellT));
first->num=0;
first->next=NULL;
first->last=NULL;


int m,n,b;
scanf("%d%d",&m,&n);
int input[n];
for (int i=0;i<m;i++){
    scanf("%d",&b);
    addcell(first,b);
}

for (int i=0;i<n;i++){
    int j=0;
    scanf("%d",&b);
     j=findcell(first,b);

    printf("%d ",j);

}





}
