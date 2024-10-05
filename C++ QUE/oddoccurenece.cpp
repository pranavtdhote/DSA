#include <iostream>
using namespace std;

int oddOccurrence(int a[], int n) {
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (a[i] == a[j]) {
                count++;
            }
        }
        // This check must be outside the inner loop
        if (count % 2 != 0) {
            return count;
        }
    }
    return -1;
}

int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    int a[n];
    cout << "Enter the elements in the array: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int result = oddOccurrence(a, n);
    if (result != -1) {
        cout << "The number that occurs an odd number of times is: " << result << endl;
    } else {
        cout << "No element occurs an odd number of times." << endl;
    }

    return 0;
}
