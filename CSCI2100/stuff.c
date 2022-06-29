#include <stdio.h>
#include <math.h>

int main(){
int numx=100,numy=100;
int x[numx][numy];

for (int i=0;i<numx;i++){
    for (int j=0;j<numy;j++){
        x[i][j]=0;
    }
}

x[0][0]=1;








/*for (double i=0;i<numx;i=i+0.01){



    for (double j=0;j<numy;j=j+0.01){
       // printf("%f %f %f\n",i,j,i*i);
        if ((int)())==100) {int ii=(int)i; int jj=(int)j; x[ii][jj]=1;}                                            //if ((int)((i-20)*(i-20)+(j-20)*(j-20))==100) {int ii=(int)i; int jj=(int)j; x[ii][jj]=1;}    // if ((int)j==(int)(i+5)) {int ii=(int)i; int jj=(int)j; x[ii][jj]=1;}
    }
}*/

double t=0;
double g=9.81/6;
int v=50;
double angle=(3.14159/4);
double c=cos(angle);
double s=sin(angle);
//printf("%f %f\n",c,s);


while (t<20){

t=t+0.001;
double iii=((v*cos(angle))*t);
double jjj=((v*sin(angle))*t-(0.5*g*t*t));
//printf("%f %f\n",iii,jjj);

int ii=(int)iii;
int jj=(int)jjj;
if ((ii<numx*10)&&(jj<numy*10)&&(ii>=0)&&(jj>=0))   x[ii/10][jj/10]=1;



}


for (int j=numy-1;j>0;j--){
    for (int i=0;i<numx;i++){
        if (x[i][j]==1) printf("@"); else printf(" ");
    }
    printf("\n");
}

}
