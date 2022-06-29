#include <stdio.h>

int main(){
int t;
scanf("%d",&t);
for (int i=0;i<t;i++)
{



    int n,firstin=-1;
    scanf("%d",&n);
    int array[n];
    for (int j=0;j<n;j++)
    {
       scanf("%d",&array[j]);
       if ((array[j]==1)&&(firstin==-1)) firstin=j;
    }
    if (array[n-1]==0) for (int k=0;k<n+1;k++) printf("%d ",k+1);

    if (array[n-1]==1)  {if (firstin==0) {printf("%d ",n+1);for (int k=0;k<n;k++) printf("%d ",k+1);}

                         if (firstin!=0)  {for (int k=0;k<firstin;k++) printf("%d ",k+1);printf("%d ",n+1);for (int k=firstin;k<n;k++) printf("%d ",k+1);}


                        }
    printf("\n");

}












return 0;}

