// neighbourgame.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
using namespace std;

class TABLE1 {
public:
    /*int table[64] = {0,2,2,2,1,1,1,0,
                   1,0,0,0,0,0,0,2,
                   1,0,0,0,0,0,0,2,
                   1,0,0,0,0,0,0,2,
                   2,0,0,0,0,0,0,1,
                    2,0,0,0,0,0,0,1,
                   2,0,0,0,0,0,0,1,
                    0,1,1,1,2,2,2,0 };*/
    int table[64] = { 0,2,2,2,1,1,1,0,
                   1,0,1,0,0,0,0,2,
                   1,1,0,0,0,0,0,2,
                   1,0,1,0,0,0,0,2,
                   2,0,0,0,0,0,0,1,
                    2,0,0,0,0,0,0,1,
                   2,0,0,0,0,0,0,1,
                    0,1,1,1,2,2,2,0 };
    int xlen, ylen, wnum = 12, bnum = 12;
public:


    TABLE1(int x, int y)
    {
        xlen = x;
        ylen = y;
        //for (int i = 0; i < 8; i++) {
        //    for (int j = 0; j < 8; j++) table[i * 8 + j] = 0;
        //}

    };

    void initalize() {
        int num = 0;
        for (int i = 0; i < ylen; i++) {
            for (int j = 0; j < xlen; j++) {
                if ((i == 0) && (j <= 3) && (j > 0)) table[num] = 2;
                if ((i == 0) && (j > 3) && (j < 7)) table[num] = 1;
                if ((i == 7) && (j <= 3) && (j > 0)) table[num] = 1;
                if ((i == 7) && (j > 3) && (j < 7)) table[num] = 2;

                if ((j == 0) && (i <= 3) && (i > 0)) table[num] = 1;
                if ((j == 0) && (i > 3) && (i < 7)) table[num] = 2;
                if ((j == 7) && (i <= 3) && (i > 0)) table[num] = 2;
                if ((j == 7) && (i > 3) && (i < 7)) table[num] = 1;
                num++;
            }
        }
    };


    void print() {
        int num = 0;
        cout << "  a b c d e f g h" << endl;
        for (int i = 0; i < ylen; i++) {
            cout << i << " ";
            for (int j = 0; j < xlen; j++) {
                if (table[num] == 0) cout << ". ";
                if (table[num] == 1) cout << "W ";
                if (table[num] == 2) cout << "B ";
                num++;
            }
            cout << endl;
        }
    };

    int neighbournum(int y,int x) {
        int num=0;
        if (x != 0) {
            if (table[y * 8 + x - 1] != 0) num++;
            if  (y != 0) if (table[(y-1) * 8 + x - 1] != 0) num++;
            if (y != 7) if (table[(y + 1) * 8 + x - 1] != 0) num++;
        }
        if (x != 7) {
            if (table[y * 8 + x + 1] != 0) num++;
            if (y != 0) if (table[(y - 1) * 8 + x + 1] != 0) num++;
            if (y != 7) if (table[(y + 1) * 8 + x + 1] != 0) num++;
        }
        if (y != 0) {
            if (table[(y-1) * 8 +x] != 0) num++;
        }
        if (y != 7) {
            if (table[(y + 1) * 8 +x] != 0) num++;
        }
        return num;
    };



    void clear(int y, int x, int temp) {
        if (table[y * 8 + x] != temp) return;
        table[y * 8 + x] = temp-2;
        if (x != 0) {
            if (table[y * 8 + x - 1] == temp) clear(y, x - 1, temp);
            if (y != 0) if (table[(y - 1) * 8 + x - 1] == temp) clear(y-1, x - 1, temp);
            if (y != 7) if (table[(y + 1) * 8 + x - 1] == temp) clear(y+1, x - 1, temp);
        }
        if (x != 7) {
            if (table[y * 8 + x + 1] == temp)  clear(y, x + 1, temp);
            if (y != 0) if (table[(y - 1) * 8 + x + 1] == temp) clear(y-1, x + 1, temp);
            if (y != 7) if (table[(y + 1) * 8 + x + 1] == temp) clear(y+1, x + 1, temp);
        }
        if (y != 0) {
            if (table[(y - 1) * 8 +x] == temp) clear(y-1, x , temp);
        }
        if (y != 7) {
            if (table[(y + 1) * 8 +x] == temp) clear(y+1, x , temp);
        }
    };

    int totalconnection(int y,int x,int colour) {
        if (table[y * 8 + x] != colour) { /*cout << "IT IS NOT " << colour << "!!!";*/ return 0; };
        int temp = colour + 2;
        table[y * 8 + x] = temp;
        int num = 1;
        if (x != 0) {
            if (table[y * 8 + x - 1] ==colour) num+=totalconnection(y,x-1,colour);
            if (y != 0) if (table[(y - 1) * 8 + x - 1] == colour) num += totalconnection(y-1, x - 1, colour);
            if (y != 7) if (table[(y + 1) * 8 + x - 1] == colour) num += totalconnection(y+1, x - 1, colour);
        }
        if (x != 7) {
            if (table[y * 8 + x + 1] == colour) num += totalconnection(y, x + 1, colour);
            if (y != 0) if (table[(y - 1) * 8 + x + 1] == colour) num += totalconnection(y-1, x + 1, colour);
            if (y != 7) if (table[(y + 1) * 8 + x + 1] == colour) num += totalconnection(y+1, x + 1, colour);
        }
        if (y != 0) {
            if (table[(y - 1) * 8 +x] == colour) num += totalconnection(y - 1, x , colour);
        }
        if (y != 7) {
            if (table[(y + 1) * 8 +x] == colour) num += totalconnection(y + 1, x, colour);
        }

        //cout << " done checking " << y <<" "<< x << "num is " << num << endl;
        return num;



    };

    int outsideonnection(int x, int y, int colour) {
        int tem = totalconnection(y, x, colour);
        int temp = colour + 2;
        clear(y, x, temp);
        return tem;

    };

    bool move(int player) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
      //  cout << "doing!";
        if (table[y1 * 8 + x1] != player) return false;
        if (table[y2 * 8 + x2] == player) return false;
        int num = neighbournum(y1, x1);
       // cout << "checked target, now check distance";
        
        if  (((x2-x1)!=num)&&((x1 - x2) != num)&&((x1-x2)!=0)) return false;
        if (((y2 - y1) != num) && ((y1 - y2) != num) && ((y1 - y2) != 0)) return false;
        if (((y1 - y2) == 0) && ((x1 - x2) == 0)) return false;


        if (table[y2 * 8 + x2] != 0) {
            if (player == 1)  bnum--;
            if (player == 2)  bnum--;
        }
        table[y2 * 8 + x2] = player;
        table[y1 * 8 + x1] = 0;

        return true;
    };


};
int main()
{
    int x = 8, y = 8;
    // cout << x << y;
    TABLE1 newtab(x,y);
    // newtab.initalize();

    /*while (1) {
        cout << "input x and y " << endl<<endl;
        cin >> x >> y;
        //cout << newtab.table[y*8+x] <<" next to " << newtab.neighbournum(x, y) << endl;
        cout << "total connect " << newtab.outsideonnection(x, y, 1) << endl;
        newtab.print();
    }*/
    int now = 1;
    int win = 0;
    while (win==0) {
        newtab.print();

        int check = 0, pass = 0;
        while ((check < 64)&&(pass==0))
        {
            if (newtab.neighbournum(check%8, check/8) !=0) pass = 1;
            check++;
        }
        if (pass == 0) {
            cout << "you have to pass! \n";
            break;
        }

        while (!newtab.move(now)) {
            cout << "failed!";
        }

        if (newtab.bnum == 0) { win = 1; break; }
        if (newtab.wnum == 0) { win = 2; break; }
        int count = 0;
        while ((count<64)&&(win==0))
        {
            if  (newtab.outsideonnection(count % 8, check / 8, 2) == newtab.bnum) win = 2;
            if  (newtab.outsideonnection(count % 8, check / 8, 1) == newtab.wnum) win = 1;
            count++;
        }
        if (win != 0) break;





        if (now == 1) now++; else now--;
    }
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
