#include<bits/stdc++.h>
using namespace std;


int qs (vector<int> &nums, int low, int high)
{
    int pivot = nums[low];
    int i = low;
    int j = high;
    while(i < j)
    {
        while(nums[i] <= pivot && i <= high-1) i++;
        while(nums[j] > pivot && j >= low+1) j--;
        if(i <j) swap(nums[i],nums[j]);
    }
    swap(nums[low], nums[j]);
    return j;
}
void quick_sort(vector<int> &nums, int low, int high)
{
    if(low < high)
    {
        int pindex = qs(nums, low, high);
        quick_sort(nums, low, pindex - 1);
        quick_sort(nums, pindex + 1, high);
    }
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
    quick_sort(nums, 0, n-1);
    cout << "The sorted array after the merge sort is : ";
    for(int i = 0; i<n; i++)
    {
        cout << nums[i] << " ";
    }
    return 0;
}



