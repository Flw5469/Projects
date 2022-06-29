#include <stdio.h>

int main(){
int red,black;
while(1){
printf("Enter your number, red:");
scanf("%d",&red);
for (int i=0;i<100;i++) printf("\n");
printf("Enter your number, black:");
scanf("%d",&black);
for (int i=0;i<100;i++) printf("\n");

if ((red==0)&&(black==10)) printf("red win!\n");
else {

   if  ((black==0)&&(red==10)) printf("black win!\n");

else {
if ((red==black)||(red==9)||(black==9)||(black==10)||(red==10)) printf("BOOM!\n");
else {if (red>black) printf("red win!\n");
  else printf("black win!\n");}

}

}





}







}
