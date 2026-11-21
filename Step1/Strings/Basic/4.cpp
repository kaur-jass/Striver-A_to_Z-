#include<iostream>
#include<cstring>
using namespace std; 

int main()
{
    char str[100];

    cout << "Enter Character array : ";
    cin.getline(str,100,'$');

    cout << "Output : " << str << endl;
    return 0;
}