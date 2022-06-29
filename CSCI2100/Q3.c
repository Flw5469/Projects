#include <stdio.h>
#include <stdlib.h>

typedef struct cellT {
char *value;
//void *value;
struct cellT *next;
} cellT;


int hash(char *temp){
    int code=0;
for (int i=0;i<strlen(temp);i++){
    code=code+temp[i];

}

printf("doing fine here! code is %s code is %d\n",temp,code%101);
return (code % 101);

}


int search(cellT *bucket[],char *temp)  //1 if success,0 if fail
{

    cellT *now;
    cellT *newcell;
    newcell=(cellT *)malloc(sizeof(cellT));
    now=bucket[hash(temp)];

    while (now->next!=NULL)
                                                            {
                                                                if (strcmp(now->next->value, temp) == 0) return 1;
                                                                now=now->next;
                                                                                                   //search until end or same
                                                            }




return 0;
}





void input(cellT *bucket[],char *temp){
    cellT *now;
    cellT *newcell;
    newcell=(cellT *)malloc(sizeof(cellT));

   /* if (bucket[hash(temp)]==NULL)                    //new blanket

    {

      bucket[hash(temp)]->value=(char *)malloc((strlen(temp) + 1) * sizeof(char));

     //strcpy(bucket[hash(temp)]->value, temp);
     strncpy(bucket[hash(temp)]->value, temp, strlen(temp));
     bucket[hash(temp)]->next=NULL;}*/



                                                        now=bucket[hash(temp)];

                                                        while ((now->next!=NULL)&&(strcmp(now->next->value, temp) != 0))
                                                            {
                                                                now=now->next;
                                                                                                   //search until end or same
                                                            }
                                                        if (now->next==NULL){                            //if end then open new cell

                                                                                newcell->value = (char *)malloc((strlen(temp) + 1) * sizeof(char));
                                                                                strcpy(newcell->value, temp);
                                                                                newcell->next=NULL;
                                                                                now->next=newcell;}
}




int compare1(char *str1,char *str2){
char *temp;
temp=(char *)malloc(sizeof(char));
cellT *headbucket[101];
cellT *tailbucket[101];
cellT *midbucket1[101];
cellT *midbucket2[101];


for (int i=0;i<101;i++){
    headbucket[i]=(cellT* )malloc(sizeof(cellT));
    headbucket[i]->next=NULL;
    tailbucket[i]=(cellT* )malloc(sizeof(cellT));
    tailbucket[i]->next=NULL;
    midbucket1[i]=(cellT* )malloc(sizeof(cellT));
    midbucket1[i]->next=NULL;
    midbucket2[i]=(cellT* )malloc(sizeof(cellT));
    midbucket2[i]->next=NULL;
}

printf("PUT TAIL\n\n\n");
for (int i=0;i<strlen(str1);i++){                       //put 1's tail

    strncpy(temp,&str1[i],strlen(str1)-i);
    temp[strlen(str1)-i]='\0';
    input(tailbucket,temp);
                                }
printf("PUT head\n\n\n");
for (int i=0;i<strlen(str1);i++){                       //put 1's head

    strncpy(temp,&str1[0],strlen(str1)-i);
   temp[strlen(str1)-i]='\0';
    input(headbucket,temp);
                                }
printf("PUT mid 1\n\n\n");
for (int i=0;i<strlen(str1);i++){                       //put 1's mid
for (int j=1;j<(strlen(str1)-i+1);j++){
    strncpy(temp,&str1[i],j);
   temp[j]='\0';
    input(midbucket1,temp);
                                }}

printf("PUT mid 2\n\n\n");
for (int i=0;i<strlen(str2);i++){                       //put 2's mid
for (int j=1;j<(strlen(str2)-i+1);j++){
    strncpy(temp,&str2[i],j);
   temp[j]='\0';
    input(midbucket2,temp);
                                }}


for (int i=0;i<101;i++)
{
   /*cellT *cp;
     cp=(cellT *)malloc(sizeof(cellT));*/

    if (tailbucket[i]->next!=NULL)
    {
         printf("final test of blanket %d is %s\n",i,tailbucket[i]->next->value);
       /* cp=tailbucket[i];
         while (cp->next!=NULL){
         cp=cp->next;
         printf(" %s ",cp->value);
         printf("\n");}*/

    }

}


                                         //2 in 1
 if (search(midbucket1,str2)) return 3;



                                      //1 in 2
 if (search(midbucket2,str1)) return 4;



return 0;
}



void main(){

char array[100]={'a', 'b', 'c', 'd', 'e', 'f', 'g','a', 'b', 'c', 'd', 'e', 'f', 'g'};
char array2[100]={'a', 'b', 'c',  'b', 'c', 'd', 'e', 'd', 'e', 'f', 'g','a','f', 'g'};


printf("\n\n\nAT LAST! %d\n\n\n",compare1(array,array2));







}
