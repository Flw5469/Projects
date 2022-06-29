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
char *temp;
int success=0;
temp=(char *)malloc(sizeof(char)*10000);
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


for (int i=0;i<strlen(str1);i++){                       //put 1's tail

    strncpy(temp,&str1[i],strlen(str1)-i);
    temp[strlen(str1)-i]='\0';
    input(tailbucket,temp);
                                }

for (int i=0;i<strlen(str1);i++){                       //put 1's head

    strncpy(temp,&str1[0],strlen(str1)-i);
   temp[strlen(str1)-i]='\0';
    input(headbucket,temp);
                                }

for (int i=0;i<strlen(str1);i++){                       //put 1's mid
for (int j=1;j<(strlen(str1)-i+1);j++){
    strncpy(temp,&str1[i],j);
   temp[j]='\0';
    input(midbucket1,temp);
                                }}

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
temp2=(char *)malloc(sizeof(char)*10000);
char *temp3;
temp3=(char *)malloc(sizeof(char)*10000);

int i=0;
while ((i<strlen(str2))&&(success==0)){
    strncpy(temp,&str2[0],strlen(str2)-i);                  //2'head in 1'tail?                     CON1
   temp[strlen(str2)-i]='\0';
    if (search(tailbucket,temp)) {                          //temp2 is (1 cut itself), then +2



            strncpy(temp2,&str1[0],strlen(str1)-strlen(temp)-1);
            strcat(temp2,str2);

            success= 1;}
                                i++;}


i=0;
while ((i<strlen(str2))&&(success<=1)){                        //2'tail in 1'head?                        CON2

    strncpy(temp,&str2[i],strlen(str2)-i);
    temp[strlen(str2)-i]='\0';
    if (search(headbucket,temp)) {                          //temp 3 = 2 cut itself, then + 1

         strncpy(temp3,&str2[0],strlen(str2)-strlen(temp)-1);
            strcat(temp3,str1);






            if (success==1){
            success= 4;} else success=2;}
                                i++;};


if (success==4)        //compare temp2 and temp3, smaller one become 1, return .
{
    if (strlen(temp2)<strlen(temp3)) {success=1,strcpy(str1,temp2);} else {success=2,strcpy(str1,temp3);};
    free(temp);free(temp2);free(temp3);
 return success;
}

if (success==1)
{
    strcpy(str1,temp2);
    free(temp);free(temp2);free(temp3);
 return success;
}


if (success==2)
{
    strcpy(str1,str2);
    free(temp);free(temp2);free(temp3);
 return success;
}


free(temp);free(temp2);free(temp3);
return 0;
}



void main(){

FILE *fp;
char array[10000];
char array2[10000];
char array3[10000];
char ch;



fp=stdin;
int i=0;
while(EOF!=(ch=fgetc(fp)) && ch != '\n')
{

    array[i]=ch;

    i++;

}

fp=stdin;
i=0;
while(EOF!=(ch=fgetc(fp)) && ch != '\n')
{

    array2[i]=ch;

    i++;

}

fp=stdin;
i=0;
while(EOF!=(ch=fgetc(fp)) && ch != '\n')
{

    array3[i]=ch;

    i++;

}





char *temp;



if (compare1(array,array2))
{
if (compare1(array,array3))
printf("%d",strlen(array)); else printf("%d",strlen(array)+strlen(array3));

}
else {
temp=(char *)malloc(sizeof(char)*10000);
strcpy(temp,array);                             //noone in noone, 1=1+2,2=2+1

strcat(array,array2);
strcat(array2,temp);
free(temp);

if (compare1(array,array3)==0) {strcat(array,array3);};
if (compare1(array2,array3)==0) {strcat(array2,array3);};
if (strlen(array2)<strlen(array)) printf("%d",strlen(array2)); else printf("%d",strlen(array));
}
}
