#include <stdio.h>
#include <stdlib.h>


int opentest(char in){
    if ((in=='<')||(in=='[')||(in=='{')||(in=='('))
    return (1); else return 0;
}

int closetest(char in){
    if ((in=='>')||(in==']')||(in=='}')||(in==')'))
    return (1); else return 0;
}

int compare(char open, char close){
int diff=1;
if (((open=='(')&&(close==')'))||((open=='[')&&(close==']'))||((open=='<')&&(close=='>'))||((open=='{')&&(close=='}'))) diff=0;
return diff;
}

int main() {
    int a=0,count=0,impossible=0,numb=0;
    char b=0,ch=0;
    char *store=(char*)malloc(sizeof(char)*10);
    FILE *fp;
    fp=stdin;


    while(EOF!=(ch=fgetc(fp)) && ch != '\n'){
        if (opentest(ch)) {

            store[numb]=ch;

            numb++;
            store=realloc(store,sizeof(char)*(numb+10));

        }
        else if (closetest(ch)) {


            if (numb>0)
            {b=store[numb-1];
            numb--;
            store=realloc(store,sizeof(char)*(numb+10));
            count+=compare(b,ch);} else impossible=-1;




        } else impossible=-1;
    }

    if ((numb>0)||impossible==-1) printf("Impossible\n");
    else printf("%d",count);

}
