#include<bits/stdc++.h>
using namespace std;

void move_zeroes(int arr[], int n) {
      int cnt = 0;
      for(int i = 0; i<n; i++)
      {
        if(arr[i] == 0)  cnt++;
      }
      cout << cnt << endl;
      vector<int> temp;
      for(int i = 0; i<n;i++)
      {
        if(arr[i] != 0)
        {
            temp.push_back(arr[i]);
        }
      }
      for(int i = 0; i<cnt;i++)
      {
        temp.push_back(0);
      }
      for(int i = 0; i<n; i++)
      {
        cout << temp[i] << " ";
     }

}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    move_zeroes(arr,n);
    
    return 0;
}