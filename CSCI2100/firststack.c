// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>


typedef char eleT;
struct CDT{
    eleT *element;
    int count;
};

typedef struct CDT *ADT;

ADT createstack(){
    ADT stack;
    stack=(ADT)malloc(sizeof(struct CDT));
    stack->element=(eleT*)malloc(stack->count*sizeof(eleT));
    stack->count=0;
    return stack;
}

void push(ADT stack, eleT inputelement){
    stack->element=realloc(stack->element,(stack->count+1)*sizeof(eleT));
    stack->element[stack->count]=inputelement;
    stack->count++;
    exit;
}

eleT pop(ADT stack){
    if (stack->count!=0){
    stack->element=realloc(stack->element,(stack->count)*(sizeof(eleT)+10));
    eleT output;
    output=stack->element[(stack->count)-1];
    stack->element[(stack->count)-1]='0';
    stack->count--;
    return output;
    }
    else return '0';

}

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
    int a,count,impossible;
    char b,ch;
    FILE *fp;
    ADT realstack=createstack();

    fp=stdin;


    while(EOF!=(ch=fgetc(fp)) && ch != '\n'){
        if (opentest(ch)) {push(realstack,ch);}
        if (closetest(ch)) {b=pop(realstack);count+=compare(b,ch);};
        if ((b=='0') ||(realstack->count<0)) impossible=-1;
    }

    if ((realstack->count>0)||impossible==-1) printf("Impossible");
    else printf("%d",count);


    fclose(fp);
    return 0;}

