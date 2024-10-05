#include <iostream>
using namespace std;

// Bubble Sort
void bubbleSort(int a[], int n) {
    int temp;
    for(int j = 0; j < n; j++) {
        for(int i = 0; i < n - 1; i++) {
            if(a[i] > a[i + 1]) {
                temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
            }
        }
    }
}

// Selection Sort
void selectionSort(int a[], int n) {
    int minIndex, temp;
    for(int i = 0; i < n - 1; i++) {
        minIndex = i;
        for(int j = i + 1; j < n; j++) {
            if(a[j] < a[minIndex]) {
                minIndex = j;
            }
        }
        if(minIndex != i) {
            temp = a[i];
            a[i] = a[minIndex];
            a[minIndex] = temp;
        }
    }
}

// Insertion Sort
void insertionSort(int a[], int n) {
    int key, j;
    for(int i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;
        while(j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}

// Quick Sort
void quickSort(int a[], int low, int high) {
    if(low < high) {
        int pivot = a[high];
        int i = low - 1;
        for(int j = low; j < high; j++) {
            if(a[j] < pivot) {
                i++;
                swap(a[i], a[j]);
            }
        }
        swap(a[i + 1], a[high]);
        int pi = i + 1;

        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}
// Merge Sort
void merge(int array[], int left, int mid, int right) { 
    int n1 = mid - left + 1; 
    int n2 = right - mid; 
    int *L = new int[n1]; 
    int *R = new int[n2]; 

    for (int i = 0; i < n1; i++) { 
        L[i] = array[left + i]; 
    } 
    for (int j = 0; j < n2; j++) { 
        R[j] = array[mid + 1 + j]; 
    } 

    int i = 0, j = 0, k = left; 
    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            array[k] = L[i]; 
            i++; 
        } else { 
            array[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
    while (i < n1) { 
        array[k] = L[i]; 
        i++; 
        k++; 
    } 
    while (j < n2) { 
        array[k] = R[j]; 
        j++; 
        k++; 
    } 

    delete[] L;  
    delete[] R;  
} 

void merge_sort(int array[], int left, int right) { 
    if (left < right) { 
        int mid = left + (right - left) / 2;  
        merge_sort(array,left, mid); 
        merge_sort(array, mid + 1, right); 
        merge(array, left, mid, right); 
    } 
} 

int main() {
    int n, choice;

    cout << "Enter the size of array: ";
    cin >> n;
    int a[n];

    cout << "Enter the array elements: ";
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << "Choose the sorting algorithm:\n";
    cout << "1. Bubble Sort\n";
    cout << "2. Selection Sort\n";
    cout << "3. Insertion Sort\n";
    cout << "4. Quick Sort\n";
    cout << "5. Merge Sort\n";
    cout << "Enter your choice (1-5): ";
    cin >> choice;

    switch(choice) {
        case 1:
            bubbleSort(a, n);
            break;
        case 2:
            selectionSort(a, n);
            break;
        case 3:
            insertionSort(a, n);
            break;
        case 4:
            quickSort(a, 0, n - 1);
            break;
        case 5:
            merge_sort(a, 0, n - 1);
            break;
        default:
            cout << "Invalid choice!" << endl;
            return 1;
    }

    cout << "\nSorted array is: ";
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
