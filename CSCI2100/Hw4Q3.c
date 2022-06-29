#include <stdio.h>

typedef struct cellT{
int target;
int cost;
} cellT;



typedef struct listT{
cellT cell;
struct listT* next;
} listT;



typedef struct resultT{
int cost;
int previous;
} resultT;


void addcell(listT* list[],int target,int cost,int listnum){
/////////////////////////////////
if (list[listnum]==NULL){
    list[listnum]=(listT*)malloc(sizeof(listT));
    list[listnum]->cell.target=target;
    list[listnum]->cell.cost=cost;
    list[listnum]->next=NULL;

                                    //if (list!=NULL) printf("done!\n");

    return 0;
}

listT* newlist=list[listnum];//go through list
while (newlist->next!=NULL)
{
    //printf("going \n");
    newlist=newlist->next;
}
newlist->next=(listT*)malloc(sizeof(listT));

cellT newcell;
newcell.target=target;
newcell.cost=cost;

newlist->next->cell=newcell;
newlist->next->next=NULL;

};

cellT readcurrentlist(listT* list[],int listnum)
{

//if (list==NULL) exit(0);//excluded this condition in code
cellT newcell=list[listnum]->cell;
list[listnum]=list[listnum]->next;
return newcell;
}

cellT readcurrentnonarraylist(listT** list)
{

//if (list==NULL) exit(0);//excluded this condition in code
cellT newcell=(*list)->cell;
*list=(*list)->next;
return newcell;
}

int insert(int target,int cost,listT** list)
{/////////////////////////////////////problem:in node0, both 2 insert think the 'nextlist' ptr is NULL
if (*list==NULL){
   // printf("insert in new list\n");
    (*list)=(listT*)malloc(sizeof(listT));
    (*list)->cell.target=target;
    (*list)->cell.cost=cost;
    (*list)->next=NULL;
    return 0;
}

//printf("insert in not new list\n");

listT* newlist=(*list);//go through list
while ((newlist->next!=NULL)&&(newlist->next->cell.cost<=cost))
{newlist=newlist->next;
//printf("stuck here!");
}
//no greater, put at last
if (newlist->next==NULL)
{
    newlist->next=(listT*)malloc(sizeof(listT));

    cellT newcell;
    newcell.target=target;
    newcell.cost=cost;

    newlist->next->cell=newcell;
    newlist->next->next=NULL;
    return 0;
}
//face greater value, put in front
listT* newlist2;
newlist2=(listT*)malloc(sizeof(listT));
newlist2->cell.cost=cost;
newlist2->cell.target=target;
newlist2->next=newlist->next;
newlist->next=newlist2;
}



void recursion(listT* node[],resultT result[],int currentnode,int marked[],listT* list){

cellT currentcell;
while(node[currentnode]!=NULL){
                                                // read whole list////////////////
//printf("read adj from node!\n");
currentcell=readcurrentlist(node,currentnode);//take first cellT from nodelist,            1.repeat update result array 2. save to 'nextlist' for next access

if ((result[currentnode].cost+currentcell.cost)<result[currentcell.target].cost)
{
    result[currentcell.target].cost=(result[currentnode].cost+currentcell.cost);
    result[currentcell.target].previous=currentnode;
}

if (marked[currentcell.target]==0){
//printf("inserting node's unmarked adj %d into list\n",currentcell.target);
insert(currentcell.target,currentcell.cost,&list);//insert into 'nextlist' with order if not visited
marked[currentcell.target]=1;


//debugging
listT* newlist;
newlist=list;
while (newlist!=NULL)
{
   // printf("\n debug list contain %d %d \n",newlist->cell.target,newlist->cell.cost);
    newlist=newlist->next;
}




}
}
marked[currentnode]=1;

//printf("done with node %d!\n\n",currentnode);

if (list!=NULL)
{
//printf("list is not empty! use new node!\n");
currentcell=readcurrentnonarraylist(&list);//read and delete from 'nextlist'//havent make when 'nextlist' is empty
//printf("original node is %d\n",currentnode);
currentnode=currentcell.target;
//printf("new node is %d\n",currentnode);


recursion(node,result,currentnode,marked,list);//go other node according to 'nextlist'
}

}



int main(){

int n,m;
scanf("%d",&n);
scanf("%d",&m);


listT* node[n];//a2
int marked[n];//a1
listT* list;//b
resultT result[n];//c

//initalize
for (int i=0;i<n;i++){
    marked[i]=0;
    result[i].cost=10000001;
    result[i].previous=-1;
}
result[0].cost=0;

for (int i=0;i<n;i++){
node[i]=NULL;
}
list=NULL;






for (int i=0;i<m;i++){
    int a,b,c;
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    a--;b--;
    addcell(node,a,c,b);//pass by reference!
    addcell(node,b,c,a);

   // if (node[a]!=NULL)  printf("%d good!\n",a);
    //if (node[b]!=NULL)  printf("%d good!\n",b);
}





recursion(node,result,0,marked,list);

//printf("after recur\n");
if ((result[n-1].cost==10000001)||(result[n-1].previous==-1))  printf("-1");
else {

        int* stack=(int*)malloc(sizeof(int));
        int amount=0;
        int output=(n-1);
        while (output!=-1){

            stack=(int*)realloc(stack,sizeof(int)*(amount+10));
            stack[amount]=output;
            output=result[output].previous;
            amount++;
        }
        //printf("ok here");
        for (int i=amount-1;i>=0;i--){printf("%d ",stack[i]+1);}


}
return 0;
}
