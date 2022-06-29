#include <stdio.h>
struct cell{

int childcount;
int parentpos;
int isroot;


};

int main(){
int input=0;
int input2=0;
int no=0;
scanf("%d",&input);
struct cell array[input+1];

for (int i=0;i<input+1;i++){
array[i].childcount=0;
array[i].parentpos=0;
array[i].isroot=0;
}

for (int i=2;i<input+1;i++){
   scanf("%d",&input2);
    array[i].parentpos=input2;
    if (array[input2].isroot==0){
        //printf("leaf become root!");
      array[input2].isroot++;
      array[array[input2].parentpos].childcount--;
    }

    array[input2].childcount++;

}


//for (int i=0;i<input+1;i++){
// printf("i is , %d %d %d",array[i].childcount,array[i].parentpos,array[i].isroot);
//}


for (int i=1;i<input+1;i++){
if (array[i].isroot==1)
{
    if (array[i].childcount<3) {no=1;};
}
}

if (no) printf("No"); else printf("Yes");






return 0;}
