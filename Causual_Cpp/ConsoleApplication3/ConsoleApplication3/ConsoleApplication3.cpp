#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct newpair {
    int iloc;
    int jloc;

};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int a, b, c, d;
    struct newpair temp;

    cin >> a >> b;

    vector <vector<int>> table(a);
    vector <struct newpair>  output;
    for (int i = 0; i < a; i++)
    {
        cin >> c;
        for (int j = 0; j < c; j++)
        {
            cin >> d;
            table.at(i).push_back(d);

        }

    }

    for (int i = 0; i < b; i++)
    {
        cin >> c;
        cin >> d;
        temp.iloc = c;
        temp.jloc = d;
        output.push_back(temp);
    }

    for (int i = 0; i < b; i++)
    {

        temp = output.at(i);
        cout << table.at(temp.iloc).at(temp.jloc)<<endl;

    }
    return 0;
}