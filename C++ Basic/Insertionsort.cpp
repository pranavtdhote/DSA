#include <iostream>
using namespace std;

void insertionsort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int temp = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > temp) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp; 
    }
}

int main() {
    int n;
    cout << "Enter the Size of Array: ";
    cin >> n;
    int a[n];

    cout << "Enter the Elements In the array: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    insertionsort(a, n);

    cout << "\nSorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
   
    return 0;
}
