#include<bits/stdc++.h>
using namespace std;
bool isfreq(int freq1[], int freq2[])
{
    for(int i = 0; i<26; i++)
    {
        if(freq1[i] != freq2[i]) return false;
    }
    return true;
}
bool checkInclusion(string s1, string s2) {
    int freq[26] = {0};
    for(int i = 0; i<s1.size(); i++)
    {
        freq[s1[i]-'a']++;
    }
    int windsize = s1.length(); 
    for(int i=0; i<s2.length(); i++)
    {
        int windidx = 0; 
        int idx = i;
        int windfreq[26] = {0};
        while(windidx < windsize && idx < s2.size())
        {
            windfreq[s2[idx]-'a']++;
            windidx++; idx++;
        }
        if(isfreq(freq,windfreq)) return true;
    }
    return false;
}
int main()
{
    string s1;
    getline(cin, s1);
    string s2;
    getline(cin, s2);
    cout << checkInclusion(s1,s2) << endl;
    return 0;
}
