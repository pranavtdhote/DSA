#include <iostream>
using namespace std;

float tax_calculator(float salary)
{
  float tax=salary*0.15;
  return tax;
}

int main()
{
  float salary=0.0,tax=0.0;
  cout<<"Enter Your salary:";
  cin>>salary;
  tax=tax_calculator(salary);
  cout<<"You Have To pay tax:"<<tax<<endl;
  return 0;
}