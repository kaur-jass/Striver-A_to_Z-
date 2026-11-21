#include<bits/stdc++.h>
using namespace std;

void move_zeroes(int arr[], int n) {
      int cnt = 0;
      for(int i = 0; i<n; i++)
      {
        if(arr[i] == 0)  cnt++;
      }
      while(cnt--)
      {
        for(int i = 0; i<n;i++)
        {
            if(arr[i] == 0) 
            {
              for(int j = i; j < n-1;j++)
              {
                arr[j] = arr[j+1];
              }            
            }
            arr[n-1]= 0;
            break;
        }
        
      }
      for(int i = 0; i<n; i++)
      {
        cout << arr[i] << " ";
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