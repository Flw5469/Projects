#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


void check(int* currentinput,int* count,vector <int> Vec) {
    int j = 0;
    while ((Vec.at(j) != NULL) && (Vec.at(j) != *currentinput)) j++;
    if (Vec.at(j) != *currentinput) { (*count)++; Vec.at(j) = *currentinput;}
}











int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int a=10, b, c, d, count=0,lastinput=0,currentinput=0;

    cin >> a >> b >> c >> d;
    vector <int> Vec(a);
    currentinput = b % (2 ^ 32);
    check(&currentinput, &count, Vec);
    lastinput = currentinput;
    for (int i = 1; i < a; i++) {
       currentinput = (lastinput * c + d) % (2 ^ 32);
       check(&currentinput, &count, Vec);
       lastinput = currentinput;
    }
    cout << count;

    return 0;
}
