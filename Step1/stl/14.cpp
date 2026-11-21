// Algorithms 


#include<bits/stdc++.h>
using namespace std;
bool comp(pair<int,int> p1, pair<int,int> p2)
{
    if(p1.second < p2.second) return true;
    if(p1.second > p2.second) return false;

    // they are same 

    if(p1.first > p2.first) return true;
    return false;

}

void extra()
{
    vector<int> v;
    int a,n;
    sort(a, a+n);
    sort(v.begin(),v.end());

    sort(a+2,a+4); // sort from index 2 to 4

    pair<int, int> a[] = {{1,2},{2,1},{4,1}};

    // sort it according to second element 
    // if second element is same, then sort 
    // it according to first element but in descending order

    sort(a,a+n,comp);

    //{{4,1},{2,1},{1,2}}


    int num = 7;
    int cnt = __builtin_popcount(num); // count number of 1's in binary representation of num

    long long num = 165786578687;
    long long cnt = __builtin_popcountll(num); // count number of 1's in binary representation of num

    string s = "123";
    sort (s.begin(),s.end()); // sort string in lexicographic order to get all the permutations of string s

    do{
        cout << s << endl;
    }while(next_permutation(s.begin(),s.end()));

    // int maxi = *max_element(a,a+n);

}

int main()
{
    extra();
    return 0;
}

