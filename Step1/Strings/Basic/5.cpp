#include<iostream>
#include<cstring>
using namespace std; 

int main()
{
    char str[12];

    cout << "Enter Character array : ";
    cin.getline(str,100);
    for(char ch : str)
    {
        cout << ch << " ";
    }
    return 0;
}