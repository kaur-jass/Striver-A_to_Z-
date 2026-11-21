#include<bits/stdc++.h>
using namespace std;
string reverse_words(string s)
{
    string ans;
    reverse(s.begin(),s.end());
    for(int i = 0; i<s.size(); i++)
    {
        string word = "";
        while(s[i] != ' ' && i<s.size()) // If we are comparing a character we need to gotta go with the single quotes as c++ complier asign single quotes to character values 
        {
            word += s[i];
            i++;     // Next time i will point to the index where the next word starts.... like 4 in the strung "The Pen".....
        }
        reverse(word.begin(),word.end());
        if(word.length()>0)
        {
            ans += " " + word;
        }
    }
    return ans.substr(1);     // Need to return ans with the first character removed that is space cause we need one one space in two particular words....
}

int main()
{
    string s; 
    getline(cin,s);
    cout << reverse_words(s) << endl;
    return 0;

}