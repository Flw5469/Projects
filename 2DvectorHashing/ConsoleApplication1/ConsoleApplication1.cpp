#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


//COOL HASHING USING VECTOR OF VECCTOR for repeated integer (but took long ;-;)


int hashing(unsigned long int new1, vector<vector<unsigned long int>>& table, unsigned long int a, unsigned long int* count) {
   // int totalslot = (a / 10000);
    int totalslot = 10000;
    if (totalslot == 0) totalslot++;
    long int slot = (new1 % (totalslot));
   // cout << "slot is " << slot << "value is " << new1 << endl;

    /*
    table.at(slot).push_back(new1);
    for (int j = 0; j < table.at(slot).size(); j++) {
        cout << table.at(slot).at(j) << endl;
        
    };
    */


    if (!(table.at(slot).empty()))
    {
        for (int j = 0; j < table.at(slot).size() ; j++) {
            //cout<< j <<endl;
            if (table.at(slot).at(j) == new1) { 
                                                       // cout << new1 << " not unique!" << endl; 
                                                        return 0; }
        };
    };
    (*count)++;
   // cout << "count is     " << *count << endl;
    table.at(slot).resize(table.at(slot).size() + 1);
    table.at(slot).push_back(new1);
   // cout << new1 << " is unique!" << endl;
    
    return 0;
}


int main() {
    long int modlu = pow(2, 31);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    unsigned long int a = 10, b = 1, c = 1, d = 1, new1 = 0, count = 0;
    cin >> a >> b >> c >> d;
    //int slotnum = (a / 10000);
    int slotnum = (10000);
    if (slotnum == 0) slotnum++;
    std::vector<std::vector<unsigned long int>> table(slotnum, std::vector<unsigned long int>(0));

    vector<std::vector<unsigned long int>>& tableref = table;

     for (int i = 0; i < a; i++) {
         if (i == 0) { b=b%(modlu); hashing(b, tableref, a, &count); new1 = b; }
         else {
             new1 = ((new1 * c + d) % (modlu));
                hashing(new1, tableref, a, &count); }
     };
    
   /*
    for (int i = 0; i < 10; i++) {
        cin >> b;
        hashing(b, tableref, a, &count);
    }
    */
    cout << count << endl;

    return 0;
}