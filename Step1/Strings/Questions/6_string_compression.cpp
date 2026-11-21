#include<bits/stdc++.h> 
using namespace std; 
int compress(vector<char>& chars) {
    int idx = 0;
    for (int i = 0; i < chars.size(); i++)
    {
        char ch = chars[i];
        int count = 0;
        while(i<chars.size() && chars[i] == ch)
        {
            count++; i++;
        }
        if(count == 1) chars[idx++] = ch;
        else  // Count value is greater than 1
        {
            chars[idx++]  = ch; // Store the character
            // Store the count value as a string
            string countStr = to_string(count);
            for (int j = 0; j < countStr.size(); j++)   // Can be written as for(char dig:str) char[idx++] = dig;
            {
                chars[idx++] = countStr[j];
            }
        }
        i--;
    }
    chars.resize(idx);    // I just resize the value of character array upto the required array after modification 
    return idx;
}


int main()
{
    int n;
    cin >> n;
    vector<char> chars(n);
    for(int i = 0; i < n; i++)
    {
        cin >> chars[i];
    }
    cout << compress(chars) << endl;
    return 0;
}