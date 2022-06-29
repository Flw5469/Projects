// dp-exactlyK.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
	int w[10]{ 1,1,2,3,4 };//,5,6,7,89,12 };
	int total = 9;
	int imax = 5;
	int dp[5][9]{ 0 };

	for (int i = 0; i < imax; i++) {
		dp[i][0] = 1;
	}
	for (int j = 1; j < total; j++) {
		for (int i = 0; i < imax-1; i++) {

			if ((j >= w[i]) && (dp[i][j - w[i]] == 1)) dp[i + 1][j] = 1;
			else dp[i + 1][j] = dp[i][j];

		}
	}
	for (int j = 0; j < total; j++) {
		for (int i = 0; i < imax; i++) {
			cout << dp[i][j] << " ";
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