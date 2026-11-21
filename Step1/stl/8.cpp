#include<bits/stdc++.h>
using namespace std;

void explain_pq()
{
    priority_queue<int> pq;
    // greater one on the top 
    // by default it is max heap, so the largest element is on the top
    pq.push(5); // {5}
    pq.push(2); // {5,2}
    pq.push(8); // {8,5,2}
    pq.emplace(10); // {10,8,5,2}

    cout << pq.top(); // prints 10

    pq.pop(); // removes 10, now {8,5,2}

    cout << pq.top(); // prints 8

    // size swap empty functions are same as stack and queue


    // Minimum Heap 
    priority_queue<int, vector<int>, greater<int>> pq1; 
    pq.push(5); // {5}
    pq.push(2); // {2,5}
    pq.push(8); // {2,5,8}
    pq.emplace(10); // {2,5,8,10}

    cout << pq.top(); // prints 2
}

int main()
{
    explain_pq();
    return 0;
}
