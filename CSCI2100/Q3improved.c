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
printf("Comparing %s and %s\n",str1,str2);
char *temp;
int success=0;
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


                                         //2 in 1                                       CON3
 if (search(midbucket1,str2)) {







    return 3;}



                                      //1 in 2                                              CON4
 if (search(midbucket2,str1)) {
strcpy(str1,str2);
  return 4;
 }


char *temp2;
temp2=(char *)malloc(sizeof(char));

int i=0;
while ((i<strlen(str2))&&(success==0)){
    strncpy(temp,&str2[0],strlen(str2)-i);                  //2'head in 1'tail?                     CON1
   temp[strlen(str2)-i]='\0';
printf("\n\ntemp in condition 1 is %s, %dst time running C1\n\n",temp,i+1);
    if (search(tailbucket,temp)) {                          //temp2 is (1 cut itself), then +2


                printf("saerch uin 1 found!");

            strncpy(temp2,&str1[0],strlen(str1)-strlen(temp)-1);
            strcat(temp2,str2);

            success= 1;}
                                i++;}


i=0;
while ((i<strlen(str2))&&(success<=1)){                        //2'tail in 1'head?                        CON2

    strncpy(temp,&str2[i],strlen(str2)-i);
    temp[strlen(str2)-i]='\0';
printf("\n\ntemp in condition 2 is %s, %dst time running C2\n\n",temp,i+1);
    if (search(headbucket,temp)) {                          //2 cut itself, then + 1

                printf("saerch uin 2 found!");
          str2[strlen(str2)-strlen(temp)]='\0';
         strcat(str2,str1);







            if (success==1){
            success= 4;} else success=2;}
                                i++;};


if (success==4)        //compare temp2 and 2, smaller one become 1, return .
{
    if (strlen(temp2)<strlen(str2)) {success=1,strcpy(str1,temp2);} else {success=2,strcpy(str1,str2);};
 return success;
}

if (success==1)
{
    strcpy(str1,temp2);
 return success;
}


if (success==2)
{
    strcpy(str1,str2);
 return success;
}



return 0;
}



void main(){

char array[100]={'a', 'b', 'c', 'd', 'e', 'f', 'g','a', 'b', 'c', 'd', 'e', 'f', 'g'};
char array2[100]={ 'b', 'c', 'd', 'e', 'f', 'g','a', 'b', 'c', 'd', 'e', 'f', 'g'};
char array3[100]={'q', 'g','a','b'};
char *temp;
temp=(char *)malloc(sizeof(char));


if (compare1(array,array2))
{
if (compare1(array,array3))
printf("1 to 2 have , product and 3 have ,Length is %d",strlen(array)); else printf("1 to 2 have , product and 3 no, Length is %d",strlen(array)+strlen(array3));
printf("array 1 2 3 are %s %s %s",array,array2,array3);
}
else {
strcpy(temp,array);                             //noone in noone, 1=1+2,2=2+1
strcat(array,array2);
strcat(array2,temp);

if (compare1(array,array3)==0) strcpy(array,array3);
if (compare1(array2,array3)==0) strcpy(array2,array3);
if (strlen(array2)<strlen(array)) printf("array2! %d",strlen(array2)); else printf("array1! %d",strlen(array));
}
}
