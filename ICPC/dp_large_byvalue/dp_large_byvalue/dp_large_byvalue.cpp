// dp-test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
using namespace std;
#define infin 500000

int main()
{
    int w[7]{ 4,2,3,1,4,5,6 };
    int v[7]{ 1,2,3,4,5,6,7 };

    int max1 = 10;
    int dp[7 * 11] = { 0 };
   // int check[7][11]{ 0 };

    for (int i = 0; i < 7; i++) {
        for (int j = 1; j < 11; j++) {
            dp[i + 7 * j] = infin;
        }
    }

    for (int j = 1; j <= 10; j++) {
        if (v[0] > j) dp[j * 7] = w[0];
    }

    for (int j = 1; j <= 10; j++) {
        for (int i = 0; i < 6; i++) {
            /*if (j >= w[i]) {
                dp[i + 1 + j * 7] = max(dp[i + j * 7], dp[i + (j - w[i]) * 7] + v[i]);
            }
            else dp[i + 1 + j * 7] = dp[i + j * 7];
            */
           /*if (j - v[i]>0) dp[i + 1 + j * 7] = infin;
           else {*/ int temp = j - v[i]; temp = max(temp, 0); dp[i + 1 + j * 7] = min(dp[i + j * 7], dp[i + (temp) * 7] + w[i]); /*}*/

            cout << i << " " << j << " ";
            cout << dp[i + j * 7+1] << endl;
            cout << "v[i] is " << v[i] << endl;
        }
    }

    for (int j = 1; j <= 10; j++) {
        for (int i = 0; i < 7; i++) {
            cout << dp[i + j * 7] << " ";
        }
        cout << endl;
    }

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
