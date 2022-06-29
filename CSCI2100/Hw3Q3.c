#include <stdio.h>

int highest=0;

typedef struct cellT{
int parent;
int level;
int *child;
int childcount;
} cellT;


void givetreelevel(cellT array[],int pos){

if (array[pos].childcount!=0)
{
    for (int i=0;i<array[pos].childcount;i++){

     array[array[pos].child[i]].level=array[pos].level+1;
     if (array[pos].level+1>highest) highest=array[pos].level+1;
     givetreelevel(array,array[pos].child[i]);




    }
}
}

int main(){
int n,m;
scanf("%d",&n);
cellT array[n];

for (int i=0;i<n;i++){
    array[i].level=0;
    array[i].childcount=0;}

for (int i=0;i<n;i++){

    scanf("%d",&m);
    array[i].parent=m;
    if (m!=-1){ array[m-1].childcount++;
                if (array[m-1].childcount==1) {array[m-1].child=(int*)malloc(sizeof(int));}
                array[m-1].child=(int*)realloc(array[m-1].child,(sizeof(int)*(array[m-1].childcount+1)));
                array[m-1].child[array[m-1].childcount-1]=i;
            }
}


//similiar to recursion hard can delete

for (int i=0;i<n;i++){

    if (array[i].parent==-1)
    {
        givetreelevel(array,i);
    }

}


/*testing print only
for (int i=0;i<n;i++){
printf("%d %d %d\n ",array[i].parent,array[i].level,array[i].childcount);
for (int j=0;j<array[i].childcount;j++)
{
    printf("child are %d\n",array[i].child[j]+1);

}
}
*/


printf("%d",highest+1);



return 0;
}

