#include<bits/stdc++.h>
using namespace std;
// smtg wrong with linear search 
int largest(vector<int>& weights)
{
    int maxx = 0; 
    for(int i = 0; i < weights.size(); i++)
    {
        maxx = max(maxx,weights[i]);
    }
    return maxx;
}

int books_pages(vector <int>& books,int m)
{
    int n = books.size(); 
    int total =  0; 
    int std = 1; 
    for(int i = 0; i<n; i++)
    {
        if(total+books[i] > m)
        {
            std++; 
            total = books[i];
        }
        else total += books[i];
    }
    return std;
    
}

int books_allocation(vector <int>& books,int m)
{
    int n = books.size();
    int s = largest(books);
    int sum = 0; 
    for(int i = 0; i <n; i++)
    {
        sum += books[i];
    }
    int e = sum;
    for(int i = s; i<= e; i++)
    {
        int cnt = books_pages(books,i);
        if(cnt == m)
        {
            return i;
        }
    } 
    return -1;
}
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i<n; i++)
    {
        cin >> nums[i];
    }
    int m; 
    cin >> m;
    int pages = books_allocation(nums, m);
    cout << pages << endl;
    return 0;
}
