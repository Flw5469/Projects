#include <stdio.h>

struct cellT{
int city;
int totalban;

};

int checkrelative(int a,int b,int** array,int n){


for (int i=0;i<n;i++){
        if ((array[a][i]==0)&&(array[b][i]==0)){
            return i;
        }
}
return -1;
}

void checktotalroad(int a,int** array,int n){

printf("%d\n",n-1);
for (int i=0;i<n;i++)
{   if ((array[a][i]==0)&&(a!=i)) printf("%d %d\n",a+1,i+1);
    if  (array[a][i]!=0)    printf("%d %d\n",i+1,checkrelative(a,i,array,n)+1);
}
}












int main(){
int n,m;
scanf("%d",&n);
scanf("%d",&m);
int **array=(int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
        array[i] = (int*)malloc(n * sizeof(int));

for (int i=0;i<n;i++){
    for (int j=0;j<n;j++){
        array[i][j]=0;
    }
}


struct cellT access[n];

for (int i=0;i<n;i++){
    access[i].city=i;
    access[i].totalban=0;
}

for (int i=0;i<m;i++){

 int a,b;
scanf("%d",&a);
scanf("%d",&b);
a--;b--;
array[a][b]=1;
array[b][a]=1;
access[a].totalban++;
access[b].totalban++;
}



for (int i=0;i<n;i++){

    for (int j=(i+1);j<n;j++){

     struct cellT temp;
     if (access[j].totalban<access[i].totalban)
        {
            temp=access[j];
            access[j]=access[i];
            access[i]=temp;
        }
    }
}


/*for (int i=0;i<n;i++){
    printf("%d %d\n",access[i].city,access[i].totalban);
}*/


//start finding station
int count=0;
int working;
int fail=1;
while ((count<n)&&(fail==1)){

    fail=0;
    working=access[count].city;
    //printf("doing too good with %d\n",working);
    //run for each city
    for (int j=0;j<n;j++){
     if (array[working][j]==1)
        {
            printf("city %d not accessable by %d\n",j,working);
            if (checkrelative(working,j,array,n)==-1) fail=1;}  //check all inaccessible, if no relative then this city fail


    }
    //printf("fail here is %d",fail);
count++;
}

if (fail==0)
checktotalroad(working,array,n);






return 0;}
