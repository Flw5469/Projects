#include <stdio.h>
#include <stdlib.h>
int main(){

int total,max,last=0,count=0,times=0;



scanf("%d %d",&total,&max);
int *ticket;
ticket=malloc((sizeof(int)*total));
for (int i=0;i<total;i++)
    {scanf("%d",&ticket[i]);
    }




while (count<(total)){



    if (ticket[times]>0)
    {
         ticket[times]=ticket[times]-max;
         if (ticket[times]<=0) {count++;last=times;};
    }


    times++;
    if (times==total) {times=0;}


}
printf("%d",last+1);
}
