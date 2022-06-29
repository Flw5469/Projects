// eatingsnake.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <ctime>
#include<windows.h>
#include < stdlib.h >
using namespace std;
int rnum=0,snakenum=0;
/* USELESS!
void set_cursor(int x = 0, int y = 0)
{
    HANDLE handle;
    COORD coordinates;
    handle = GetStdHandle(STD_OUTPUT_HANDLE);
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(handle, coordinates);
}
class snake {

public:
    snake* next;
    int pointingdir; //1up 2down 3left 4 right
    int xloc;
    int yloc;

    snake(int xlen,int ylen) {
        xloc = xlen / 2;
        yloc = ylen / 2;
        int pointingdir=1;
    }

    void addsnake(snake* originalsnakeptr) {
        pointingdir = originalsnakeptr->pointingdir;
        switch (originalsnakeptr->pointingdir){
        case 1: {xloc = originalsnakeptr->xloc;
            yloc = originalsnakeptr->yloc-1;
        }
        case 2: {xloc = originalsnakeptr->xloc;
            yloc = originalsnakeptr->yloc+1;
        }
        case 3: {xloc = originalsnakeptr->xloc+1;
            yloc = originalsnakeptr->yloc ;
        }
        case 4: {xloc = originalsnakeptr->xloc-1;
            yloc = originalsnakeptr->yloc;
        }
        }
    }
};
*/
//up -x down +x left -1 right +1
struct snake {
    int head;
    int tail;
};

void print(snake* snakeptr, int x, int y, int loc) {
    system("CLS");
    for (int j = 0; j < x+2; j++) cout << "x";
    cout << endl;
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            if (j == 0) cout << "x";
            if (i*x+j==loc) {
                switch (snakeptr[i*x+j].head) {
                case -1: cout << "<"; break;
                case 1: cout << ">"; break;
                }
                if (snakeptr[i * x + j].head==x)    cout << "v";
                if (snakeptr[i * x + j].head == (-x))    cout << "^";
            }
            else {
                if ((snakeptr[i * x + j].head == x) || (snakeptr[i * x + j].head == (-x))) cout << "|";

                if ((snakeptr[i * x + j].head == 1) || (snakeptr[i * x + j].head == (-1))) cout << "-";
            }

            if (snakeptr[i * x + j].head == 5) cout << "o";
            else if ((snakeptr[i * x + j].head == 0)) cout << " ";
            if ((snakeptr[i * x + j].head / 6969 != 0)) cout << ".";
            if (j == x-1) cout << "x";
        }
        cout << endl;
    }
    for (int j = 0; j < x+2; j++) cout << "x";

}

void generate(snake* snakeptr, int x, int y) {
    if (rnum != 0) return;
    int r = rand() % (x * y);
    while (snakeptr[r].head != 0)
        int r = rand() % (x * y);
    snakeptr[r].head = 5;
    rnum++;
}

void initalize(snake* snakeptr,int x,int y,int* loc) {
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            snakeptr[i * x + j].head = 0;
            snakeptr[i * x + j].tail = 0;
        }
    }

    *loc = (y / 2) * x + x / 2;
    snakeptr[(y / 2) * x + x/2].head = x;
    snakeptr[(y / 2) * x + x/2].tail = 0;
    generate(snakeptr, x, y);
}

void addsnake(snake* snakeptr,int loc) {
    if (snakeptr[loc].tail == 0) {

        snakeptr[loc].tail = snakeptr[loc].head * (-1);
        snakeptr[loc + snakeptr[loc].tail].head = (snakeptr[loc].head);
        snakenum++;
    }
    else {
        loc += snakeptr[loc].tail;
        addsnake(snakeptr, loc);
    }
   
}


/*void move(snake* snakeptr, int x, int y, int* loc) {
    //crash
    int old = *loc;
    *loc += snakeptr[*loc].head;
    //if (snakeptr[*loc].head==5) addsnake(snakeptr, old);

    if ((snakeptr[*loc].head / 6969) != 0) {  cout << "follow direction on " << *loc <<" direction is " << snakeptr[*loc].head/6969 <<endl;
                                            snakeptr[*loc].head /= 6969; } //next came=>follow?
    else { snakeptr[*loc].head = snakeptr[old].head; cout << "dump old head of direction "<< snakeptr[old].head <<endl; }



    snakeptr[*loc].tail = snakeptr[old].head;
    cout << "tail is " << snakeptr[old].tail << endl;
    if (snakeptr[old].tail != 0)
    {
        snakeptr[old].head *= 6969;
        cout << "have tail, set direction on " << old<<" value is "<< snakeptr[old].head/6969 << endl;
    }
    else snakeptr[old].head = 0;

    
    snakeptr[old].tail = 0;
    int temp = old + snakeptr[*loc].tail;
    cout << "moved " << old << endl;
    cout <<"next one to do is " << temp << endl;
    if (snakeptr[*loc].tail != 0) {
        move(snakeptr, x, y, &temp);
    }
}
*/


int move(snake* snakeptr, int x, int y, int* loc,int head) {
   
    int old = *loc;
    if (snakeptr[old].head == 0) return 0;
    *loc = *loc + snakeptr[*loc].head;


    if ((snakeptr[*loc].head != 0) && (snakeptr[*loc].head != 5)&&(old==head)) return -1;

    if (((old%x==(x-1))&&(snakeptr[old].head == 1))|| (((old % x == 0)) && (snakeptr[old].head == -1))|| ((old / x == (y - 1)) && (snakeptr[old].head == x))|| ((old / x == (0)) && (snakeptr[old].head == -x)))     return -1;

    if (snakeptr[*loc].head == 5) {
        addsnake(snakeptr, *loc);
        generate(snakeptr, x, y);
    }


    if ((snakeptr[*loc].head == 0)|| (snakeptr[*loc].head == 5)) {
        snakeptr[*loc].tail = -snakeptr[old].head;
        snakeptr[*loc].head = snakeptr[old].head;
    }


    if (snakeptr[old].tail == 0) {
        //cout << "end of list!";
        snakeptr[old].head = 0;
        snakeptr[*loc].tail = 0;
    }
    else {
        int temp = old + snakeptr[old].tail;
       // cout << "moving with" << snakeptr[old].tail << endl;
        move(snakeptr, x, y, &temp,head);
        
    }

   
};


















int main()
{
    srand(time(NULL));
    int x=50, y=20,loc=0;
   // cin >> x >> y;
    snake* snakeptr=(snake*)malloc(sizeof(snake)*x*y);
    clock_t a,b=0;
    a = clock();
    initalize(snakeptr, x, y, &loc);
    addsnake(snakeptr, loc);
    addsnake(snakeptr, loc);
    addsnake(snakeptr, loc);
    addsnake(snakeptr, loc);
    addsnake(snakeptr, loc);
    addsnake(snakeptr, loc);
    int lose = 0;
    while (lose == 0) {
        a = clock();
        if (GetAsyncKeyState('W') )
        {
            snakeptr[loc].head = (-x);
        }
        if (GetAsyncKeyState('A') )
        {
            snakeptr[loc].head = -1;
        }
        if (GetAsyncKeyState('S'))
        {
            snakeptr[loc].head = x;
        }
        if (GetAsyncKeyState('D'))
        {
            snakeptr[loc].head = 1;
        }

        while (((a-b) > 500)&&(lose==0)) {
            //cout << a<<" "<<b;
            b = a;
           
             
            if (move(snakeptr, x, y, &loc, loc) == -1) { lose = 1; }
           print(snakeptr, x, y, loc);
           cout << "length is " << snakenum;

        }
    }
     
    system("CLS");
    cout << "YOU LOSE HAHA";


  


}

// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的提示: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案
