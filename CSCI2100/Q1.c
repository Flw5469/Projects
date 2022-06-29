#include<stdio.h>


int main()
{
  char str[100];
  int last,count=0;
  int i=0;
  gets(str);
  printf("%s\n",str);


  //if (closetest(0,str)||opentest(strlen(str)-1,str)) {printf("NO!");}


  while (i<strlen(str)) {

    if (opentest(i,str)) last=i;
    if (closetest(i,str)) {count+=compare(i,last,str);i=-1;}
    i++;
    printf("\ntest ans is %d",count);
  }

printf("\nfinal ans is %d",count);

  return count;
}
