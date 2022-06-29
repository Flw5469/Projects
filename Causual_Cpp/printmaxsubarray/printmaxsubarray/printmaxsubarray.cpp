#include <iostream>
#include <deque> 
using namespace std;




void printKMax(int arr[], int n, int k) {
    //Write your code here.

    int max = 0; 

    for (int i = 0; i < k; i++) {
        if (arr[i] > arr[max]) {
            max = i;
        }
     
    }
    cout << arr[max] << " ";
    for (int i = 1; i <= (n - k); i++) {
   //     cout << "doing from " << i << " to " << n - k << endl;
        if (arr[max] < arr[i+k-1]) max=i+k-1;
        if (max < i) {
                        max = i;
                        for (int j = i; j < i + k; j++) {
                        if (arr[j] > arr[max]) max = j;
                        }
                     }   

   cout << arr[max] << " ";
    }
    cout << endl;
}

int main() {

    int t;
    cin >> t;
    while (t > 0) {
        int n, k;
        cin >> n >> k;
        int i;
        int* arr=(int*)malloc(sizeof(int)*n);
        for (i = 0; i < n; i++)
            cin >> arr[i];
        printKMax(arr, n, k);
        free(arr);
        t--;
    }
    return 0;
}