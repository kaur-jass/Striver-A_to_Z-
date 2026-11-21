#include<bits/stdc++.h>
using namespace std;
void explain_queue()
{
    queue<int> q;
    q.push(1); //{1}
    q.push(2); //{1,2}
    q.emplace(4); //{1,2,4}

    q.back() += 5; //{1,2,9}
    cout << q.back(); // prints 9

    // Q is {1,2,9}
    cout << q.front(); // prints 1

    q.pop(); // removes 1, Q is now {2,9}

    cout << q.front(); // prints 2

    // size swap empty same as stack 
}

int main()
{
    explain_queue();
    return 0;
}