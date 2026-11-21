#include<bits/stdc++.h>
using namespace std;

// Vectors 


void explain_vectors()
{
    vector<int> v;
    v.push_back(1);
    v.emplace_back(2);

    vector<pair<int, int>> vect;

    vect.push_back({1,3});
    vect.emplace_back(1, 2);

    vector<int> v(5,100);

    vector<int> v(5);

    vector<int> v1(5,20);
    vector<int> v2(v1);

    vector<int> :: iterator it = v.begin();
    it++;
    cout << *(it) << " ";

    it = it +2;
    cout << *(it) << " ";

    // vector<int>::iterator it = v.end();
    // vector<int>::iterator it = v.rend();
    // vector<int>::iterator it = v.rbegin();
     
    vector<int>::iterator it = v.end();                    // ✅ normal iterator
    vector<int>::reverse_iterator it = v.rend();           // ✅ reverse iterator
    vector<int>::reverse_iterator it = v.rbegin();         // ✅ reverse iterator

    cout<< v[0] << " " << v.at(0);
    cout << v.back() << " ";

    for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *(it) << " ";
    }

    for(auto it = v.begin(); it != v.end(); it++)
    {
        cout << *(it) << " ";
    }

    for(auto it : v)
    {
        cout << it << " ";
    }


    // {10,20,30,40,50}
    v.erase(v.begin()+1); // {10,30,40,50}

    // {10,20,12,23,35}
    v.erase(v.begin()+2, v.begin()+4);   // {10, 20, 35} [start,end)
     
    // Insert Function  
    vector<int>v(2,100); //{100,100}
    v.insert(v.begin(), 300); //{300,100,100}
    v.insert(v.begin()+1, 2, 10); //{300,10,10,100,100}

    vector<int> copy(2, 50); // {50,50}
    v.insert(v.begin()+1, copy.begin(), copy.end()); // {300,50,50,10,10,100,100}

    //{10,20}
    cout << v.size() << " ";

    //{10,20}
    v.pop_back(); // removes the last element

    //v1 -> {10,20}
    //v2 -> {30,40}
    v.swap(v2); // swaps the contents of v1 and v2  //v1 -> {30,40}, v2 -> {10,20}

    v.clear(); // clears the vector, size becomes 0

    cout << v.empty();
}

int main()
{
    explain_vectors();
    return 0;
}