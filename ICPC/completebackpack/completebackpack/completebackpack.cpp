// completebackpack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
    int w[7] = { 55,2,1,4,5,69,63 };
    int v[7] = { 7,6,5,4,3,2,1000 };
    int dp[7][69]{ 0 };

    for (int j = 1; j < 69; j++) {
        dp[0][j] = (j / w[0]) * v[0];

    }



    for (int j = 1; j < 69; j++) {
        for (int i = 0; i < 6; i++) {
        
            //cout << "now is " << i << " " << j << "before take is " << dp[i + 1][j - w[i + 1]]+v[i+1] << " now is " << dp[i][j]  << endl;

            if (j >= w[i+1]) { dp[i + 1][j] = max(dp[i][j], dp[i + 1][j - w[i + 1]] + v[i + 1]); cout << "take"<<endl; }
            else { dp[i + 1][j] = dp[i][j]; cout << "hold"<<endl; }
        
        }
    }
    for (int j = 1; j < 69; j++) {
        for (int i = 0; i < 7; i++) {
            cout << dp[i][j] << " ";
        }
        cout << " "<<j<<endl;
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
