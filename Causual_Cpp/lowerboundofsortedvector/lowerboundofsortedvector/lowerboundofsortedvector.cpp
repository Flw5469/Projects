#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int a, b, c, d = 0, upper = 0, lower = 0, mid=0;
    cin >> a;
    vector <int> value(a);

    for (int i = 0; i < a; i++) {
        cin >> b;
        value.at(i) = b;
    }
    cin >> b;
    vector <int> index(b);
    for (int i = 0; i < b; i++) {
        cin >> c;
        index.at(i) = c;
        cout << index.at(i) << endl;
    }

    for (int i = 0; i < b; i++) {

        c = index.at(i);//get index location
       // cout << "index location is " << index.at(i) << endl;
        upper = a;
        lower = 0;
        do {
            mid = (upper + lower) / 2;
            if (value.at (mid) > c) upper = mid;
            else if (value.at(mid) < c) lower = mid;
            //cout << "mid is " << mid<<"c is " << c << endl;
        } while ((value.at(mid) != c) && ((upper - lower) > 1));

        if (value.at(mid) < c) mid++;

            while ((mid!=0)&&((value.at(mid-1) == value.at(mid)))) mid--;

        if (value.at(mid) == c) cout << "Yes " ;
        else cout << "No " ;
        cout << mid+1;
        if (i != b - 1) cout << endl;
    }





    return 0;
}
