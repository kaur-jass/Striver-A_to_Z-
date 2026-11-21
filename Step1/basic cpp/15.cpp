#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[5];  // Everything should be of similar datatype... like int, double, char ,
    cin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4];     // Arrays are stored always in contigous memory but can't say that where is the first element stored.....
    arr[3] += 10;
    arr [3] = 16;
    cout << arr[3];
    return 0;
}

