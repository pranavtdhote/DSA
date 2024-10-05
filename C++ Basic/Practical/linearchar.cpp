#include <iostream>
using namespace std;

int search(char a[], int n, char elem)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == elem)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int n;
    char elem;

    cout << "Enter the size of Array: ";
    cin >> n;

    char a[n];

    cout << "Enter the elements in the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << "Enter the character to be searched: ";
    cin >> elem;

    cout << "The array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    int result = search(a, n, elem);

    if (result == -1)
    {
        cout << "\nCharacter not found in the array.";
    }
    else
    {
        cout << "\nThe index of searched character: " << result;
    }

    return 0;
}
