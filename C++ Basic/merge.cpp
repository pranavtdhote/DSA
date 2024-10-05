#include <iostream>
using namespace std;

void print_array(int array[], int size);  

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

void print_array(int array[], int size) { 
    for (int i = 0; i < size; i++) { 
        cout << array[i] << " "; 
    } 
    cout << endl;
} 

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int *numbers = new int[n];
    
    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> numbers[i];
    } 

    cout << "Unsorted array: "; 
    print_array(numbers, n); 

    merge_sort(numbers, 0, n - 1);  

    cout << "Array sorted by Merge Sort: "; 
    print_array(numbers, n);

    delete[] numbers;
    return 0;
}
