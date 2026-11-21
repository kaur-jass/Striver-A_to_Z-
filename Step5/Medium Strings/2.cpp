#include<bits/stdc++.h>
using namespace std;
int maxDepth(string s) {
    int depth = 0; 
    int maxi = 0; 
    for(int i = 0; i<s.length(); i++)
    {
        if(s[i] =='(')
        {
            depth++;
            maxi = max(depth,maxi);
        }
        else if(s[i] == ')') depth--;
        else continue;
    }
    return maxi; 
}

int main()
{
    string s; 
    getline(cin, s);
    cout << maxDepth(s) << endl;
    return 0;
}