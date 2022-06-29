#include <stdio.h>
int main(){
int n,t;
scanf("%d",&n);
scanf("%d",&t);
int array[n];
for (int i=0;i<n-1;i++){
 int input;
 scanf("%d",&input);
array[i]=(input+i);
}




int choosing=0;
while ((choosing!=(t-1))&&(choosing!=(n-1))){
    choosing=array[choosing];
 //   printf("%d\n",array[choosing]);
}







if (choosing==(t-1)) printf("YES"); else printf("NO");

return 0;
}
