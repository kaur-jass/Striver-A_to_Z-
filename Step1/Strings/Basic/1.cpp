#include<iostream>
#include <cstring>
using namespace std;

int main()
{
    char str[] = {'a','b','c','\0'};
    cout << str << endl; // Character arrays names are constant pointers
    int arr[] = {1,2,3};
    cout << arr << endl;
    cout << strlen(str) << endl;
    return 0;
}