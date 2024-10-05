#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;

class Stack
{
    private:
    int top;
    int maxSize;
    char*arr;
    public:
    Stack(int size){
        maxSize=size;
        arr=new char[maxSize];
        top=-1;
    }
    ~Stack()
    {
        delete[]arr;
    }
    bool isEmpty()
    {
        return top==-1;
    }
    bool isFull()
    {
        return top==maxSize-1;
    }
    void push(char x){
        if(isFull()){
            cout<<"Stack Overflow\n";
            return;
        }
        arr[++top]=x;
    }
    char pop()
    {
        if(isEmpty()){
            cout<<"Stack Underflow\n";
            return '#';// Return invalid character for underflow
        }
        return arr[top--];
    }
    char peek(){
        if(isEmpty()){
            return'#';
        }
        return arr[top];
    }
};
// Function to return precedence of operators
int precedence(char op)
{
if (op == '+' || op == '-') return 1;
if (op == '*' || op == '/') return 2;
if (op == '^') return 3;
return 0;
}
// Function to convert infix expression to postfix
string infixToPostfix(string infix)
{
    Stack stack(100);
    string postfix;
    for(char ch:infix){
       if (isalnum(ch))
    {
        postfix += ch; // Append operand to postfix
    }
    else if (ch == '(')
    {
    stack.push(ch); // Push '(' to stack
    }
    else if (ch == ')')
    {
        while(stack.peek()!='('){
            postfix+=stack.pop();
        }
        stack.pop();
    }
    else
    {
// Operator: pop all operators of higher or equal precedence
    while (!stack.isEmpty() && precedence(ch) <= precedence(stack.peek()))
    {
        postfix += stack.pop();
    }
    stack.push(ch); // Push current operator to stack
    }
}
while (!stack.isEmpty())
{
    postfix += stack.pop(); // Pop remaining operators
}
    return postfix;
}
// Function to convert infix expression to prefix
string infixToPrefix(string infix)
{
    reverse(infix.begin(), infix.end()); // Reverse infix expression
    // Swap '(' and ')'
    for (int i = 0; i<infix.size(); i++)
    {
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
}
    string postfix = infixToPostfix(infix); // Get postfix of reversed expression
    reverse(postfix.begin(), postfix.end()); // Reverse to get prefix
    return postfix;
}

int main()
{
    int choice;
    string infix;
    do
    {
    cout << "\nMenu:\n";
    cout << "1. Convert Infix to Postfix\n";
    cout << "2. Convert Infix to Prefix\n";
    cout << "3. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice)
    {
        case 1:
        cout << "Enter a valid infix expression: ";
        cin >> infix;
        cout << "Postfix expression: " << infixToPostfix(infix) << endl;
        break;
        case 2:
        cout << "Enter a valid infix expression: ";
        cin >> infix;
        cout << "Prefix expression: " << infixToPrefix(infix) << endl;
        break;
        case 3:
        cout << "Exiting program.\n";
        break;
        default:
        cout << "Invalid choice! Please try again.\n";
        }
        } while (choice != 3);
        return 0;
    }
