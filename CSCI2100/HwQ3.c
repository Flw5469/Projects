#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct cell{
char *value;
int pos;
};
/*
void selectionsort(struct cell array[],int length){
    //printf("ok since now,first input is %s\n",array[0].value);

for (int i=0;i<length;i++)
{
    for (int j=i;j<length;j++)
    {
       // printf("comparing %d and %d, length is %d\n",array[i].value,array[j].value,length);
        if (strcmp(array[j].value,array[i].value)<0)
        {
           //printf("sorting it! doing %d and %d\n",i,j);
            char *temp=array[j].value;
            int temp2=array[j].pos;
            array[j].value=array[i].value;
            array[j].pos=array[i].pos;
            array[i].value=temp;
            array[i].pos=temp2;

        }

    }


}
}
*/
void Merge(struct cell *array, struct cell *arr1, int n1, struct cell *arr2, int n2) {
int p1 = 0, p2 = 0, p = 0;
while (p1 < n1 && p2 < n2) {
if (strcmp(arr1[p1].value,arr2[p2].value)<=0)
array[p++] = arr1[p1++];
else
array[p++] = arr2[p2++];
}
while (p1 < n1)
array[p++] = arr1[p1++];
while (p2 < n2)
array[p++] = arr2[p2++];
}

void Divide(struct cell *array, struct cell *arr1, int n1, struct cell *arr2, int n2) {
int i;
for (i = 0; i < n1; i++)
arr1[i] = array[i];
for (i = 0; i < n2; i++)
arr2[i] = array[i + n1];
}

void MergeSort(struct cell *array,int length) {
int n1, n2;
struct cell *arr1, *arr2;
if (length > 1) {
n1 = length / 2;
n2 = length - n1;
arr1 = (struct cell *)malloc(n1 * sizeof(struct cell));
arr2 = (struct cell *)malloc(n2 * sizeof(struct cell));
Divide(array, arr1, n1, arr2, n2);
MergeSort(arr1, n1);
MergeSort(arr2, n2);
Merge(array, arr1, n1, arr2, n2);
free(arr1);
free(arr2);
}
}





void countvalue(struct cell array[],int length,int num){
char *str;
str=(char *)malloc(sizeof(char)*length+1);
scanf("%s",str);
//printf("the string received is %s\n",str);
for (int i=0;i<length;i++){
    if ((i%2)!=0) array[num].value[i]=155-str[i]; else array[num].value[i]=str[i];
}
};

int main(){
int totalinput,length;
scanf("%d%d\n",&totalinput,&length);
struct cell array[totalinput];

for (int i=0;i<totalinput;i++)
{
    array[i].value=(char*)malloc(sizeof(char)*length+1);
    countvalue(array,length,i);
    array[i].pos=i;
    //printf("the value calculated is %d\n",array[i].value);
}


//perform selection sort
MergeSort(array,totalinput);

//print result
for (int i=0;i<totalinput;i++)
{
    printf("%d ",array[i].pos+1);
}



return 0;}
