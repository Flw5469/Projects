#include <stdio.h>
#include <stdlib.h>
struct cell{
int value;
int type;
int model;

};

int total0,total1;

void swap(struct cell array[],int first,int second){
int temp=array[first].value;
int temp2=array[first].type;
array[first].value=array[second].value;
array[first].type=array[second].type;
array[second].value=temp;
array[second].type=temp2;
}

void selectionsort(struct cell array[],int length){//store thing in array[].model
total0=0;total1=0;
for (int i=0;i<length;i++){
if (array[i].type==1) total1++; else total0++;//count

for (int j=i;j<length;j++){
if (array[j].model<array[i].model){int temp=array[j].model;array[j].model=array[i].model;array[i].model=temp;}//exchange
}
}
//for (int i=0;i<length;i++){printf("%d %d %d\n",array[i].model,total0,total1);}
};


int check(struct cell array[],int length){
for (int i=0;i<length;i++)
{
    if (array[i].value==array[i].model);
       else if ((total0<1)||(total1<1)) return 0;                                               //check swappable
            else
            {int j=i+1; while (array[j].value!=array[i].model){j++;}                         //find model's location
                if (array[j].type!=array[i].type) {swap(array,i,j);}                                  //opposite sign then swap
                else  { int k=i+1; while (array[k].type==array[i].type){k++;}                               //ssamae sign then find closest opposite sign for swap
                        swap(array,i,k);
                        swap (array,i,j);//next line is extra
                        swap(array,j,k);
                        }
            }
   // if (array[i].type==1) total1--; else total0--;
}
return 1;


};



int main(){
int totalcase,length;
scanf("%d",&totalcase);
int ansyesorno[totalcase];


for (int i=0;i<totalcase;i++){//loop for T times

scanf("%d",&length);
struct cell array[length];
for (int j=0;j<length;j++) {scanf("%d",&array[j].value);array[j].model=array[j].value;}
for (int j=0;j<length;j++) scanf("%d",&array[j].type);



selectionsort(array,length);
ansyesorno[i]=check(array,length);
}





for (int i=0;i<totalcase;i++) {if (ansyesorno[i]==1) printf("Yes\n"); else printf("No\n");}
return 0;}
