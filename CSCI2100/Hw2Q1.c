#include <stdio.h>
#include <stdlib.h>
struct cell{
int pos;
int left;
int right;
int max;
int min;
};


void swap(int num,struct cell array[],int n){
    //printf("swapping %d\n",num);
int temp=array[num].pos;//printf("pos is %d\n",temp);
int left=array[num].left;//printf("left is %d\n",left);
int right=array[num].right;//printf("right is %d\n",right);
int leftleft=array[array[num].left].left;//printf("leftleft is %d\n",leftleft);


array[num].pos=array[left].pos;
array[left].pos=temp;
//position swap done



if (leftleft!=-1) array[leftleft].right=num;                                     //*******************************************
if (right!=n) array[right].left=left;

array[left].left=num;
array[left].right=right;
array[num].left=leftleft;
array[num].right=left;
//link done


if (array[num].pos<array[num].min) array[num].min=array[num].pos;
if (array[num].pos>array[num].max) array[num].max=array[num].pos;
if (array[left].pos<array[left].min) array[left].min=array[left].pos;
if (array[left].pos>array[left].max) array[left].max=array[left].pos;}
/*for (int i=0;i<n;i++)
printf("after action pos %d min is %d max is %d left is %d right is %d\n",array[i].pos,array[i].min,array[i].max,array[i].left,array[i].right);
;*/

int main(){
int n,m,swapnum;
scanf("%d%d",&n,&m);

struct cell array[n];
for (int i=0;i<n;i++)
{
 array[i].pos=i;
 array[i].left=i-1;
 array[i].right=i+1;
 array[i].max=i;
 array[i].min=i;
}
//initialize done

for (int i=0;i<m;i++)
{
 scanf("%d",&swapnum);
 if ((swapnum>0)&&(swapnum<=n)) {if  ((array[swapnum-1].pos>0)&&(array[swapnum-1].pos<n)) swap(swapnum-1,array,n);} //*********************
}

//main process done, print result now
for (int i=0;i<n;i++)
{
 printf("%d %d\n",array[i].min+1,array[i].max+1);
}
return 0;
}
