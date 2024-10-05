#include <iostream>
#include <string>
using namespace std;

int search(const string& str, char elem)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == elem)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    string str;
    char elem;

    cout << "Enter the string: ";
    getline(cin, str);

    cout << "Enter the character to be searched: ";
    cin >> elem;

    cout << "The string is: " << str << endl;

    int result = search(str, elem);

    if (result == -1)
    {
        cout << "Character not found in the string." << endl;
    }
    else
    {
        cout << "The index of the searched character: " << result << endl;
    }

    return 0;
}
