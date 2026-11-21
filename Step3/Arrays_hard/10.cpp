#include<bits/stdc++.h>
using namespace std;
// // Taking too much time complexity so thats why this one is a brute forec soln 
int numberOfPermutations(vector<int> &requirements)
{
    int n = requirements.size();
    int inv = 0; 
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1 ; j < n; j++)
        {
            if(requirements[i] > requirements[j]) inv++;
        }
    }
    return inv;
}
int main()
{
    int n; 
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << numberOfPermutations(v) << " ";
    return 0;
}