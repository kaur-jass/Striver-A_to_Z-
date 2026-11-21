#include<bits/stdc++.h>
using namespace std;

void explain_list()
{
    list<int> ls;
    ls.push_back(2); // {2}
    ls.emplace_back(4); // {2, 4}

    ls.push_front(5);  // {5,2,4}

    ls.emplace_front(6); // {6,5,2,4}

    //rest functions are same as vectors 
    // begin, end, rbegin, rend, size, swap, empty,insert, clear, front, back, at, push_back, pop_back, push_front, pop_front, insert, erase  

}

int main()
{
    explain_list();
    return 0;
}