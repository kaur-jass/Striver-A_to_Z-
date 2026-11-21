#include<bits/stdc++.h>
using namespace std;

void explain_stack()
{
    stack<int> st;
    st.push(1); // {1}
    st.push(2); //{2,1}
    st.push(3); //{3,2,1}
    st.push(3); //{3,3,2,1}
    st.emplace(5); //{5,3,3,2,1}

    cout << st.top(); // prints 5 "** st[2] is invalid **"
    
    st.pop(); // st looks like {3,3,2,1}

    cout << st.top(); // prints 3

    cout << st.size(); // prints 4

    cout << st.empty(); // prints 0 (false)

    stack<int> st1, st2;
    st1.swap(st2); // swaps the contents of st1 and st2
}

int main()
{
    explain_stack();
    return 0;
}