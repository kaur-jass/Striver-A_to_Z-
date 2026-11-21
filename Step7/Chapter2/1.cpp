#include<bits/stdc++.h>
using namespace std;


vector<string> generate(int n, const string &curr, vector<string> &result){
    //BAse Case
    if(curr.length() == n)
    {
        result.push_back(curr);
        return result;
    }

    generate(n, curr + '0', result);
    if(curr.empty() || curr.back() != '1'){
        generate(n, curr + '1', result);
    }
    return result;
}

int main()
{
    int n; 
    cout<<"Enter the value of n : ";
    cin>>n; 
    vector<string> result; 
    string curr = ""; 
    generate(n, curr, result);
    cout<<"The binary strings are : "<<endl;
    for(auto str : result){
        cout<< str << endl; 
    }
    return 0;
}