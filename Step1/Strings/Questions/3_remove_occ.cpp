#include<bits/stdc++.h>
using namespace std;
string removeOccurrences(string s, string part) {
    while(s.find(part) != string::npos)
    {
        size_t pos = s.find(part);     // These are using simple built in functions 
        s.erase(pos,part.length());
    }
    return s;
}


int main()
{
    string s;
    getline(cin, s);
    string part;
    getline(cin, part);
    cout << removeOccurrences(s,part) << endl;
    return 0;
}
