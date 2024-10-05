#include <iostream>
using namespace std;

void quickSort(int a[], int low, int high) {
   if(low<high){
    int pivot=low;
    int i=low;
    int j=high;
        while (i < j) {
            while (a[i] <= a[pivot] && i < high) {
                i++;
            }
            while (a[j] > a[pivot]) {
                j--;
            }
            if (i < j) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
        int temp = a[pivot];
        a[pivot] = a[j];
        a[j] = temp;

        quickSort(a, low, j - 1);
        quickSort(a, j + 1, high);
    }
}

int main() {
    int n;
    cout << "Enter the Size of Array: ";
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter the " << i + 1 << " element in array: ";
        cin >> a[i];
    }

    quickSort(a, 0, n - 1);

    cout << "\nSorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}
