#include<bits/stdc++.h>
using namespace std;
int largest(vector<int>& piles)
{
    int n = piles.size();
    int max = piles[0];
    for(int i = 0; i < n; i++)
    {
        if (max < piles[i])
        {
            max = piles[i];
        }
    }
    return max;
}

// int slargest(vector<int> &piles)
// {
//    int n= piles.size();
//    int largest = piles[0];
//    int slargets = INT_MIN; 
//    for(int i = 0; i<n; i++)
//    {
//          if (largest < piles[i])
//          {
//               slargets = largest; 
//               largest = piles[i];
//          }
//          else if(piles[i] < largest && piles[i] > slargets)
//          {
//               slargets = piles[i];
//          }
//    }
//    return slargets;
// }

// int totalpiles(vector<int> &piles,int h,int mid)
// {
//     int ans = -1;
//     int i = 1;
//     int k = 1;
//     if (ans == 0 || h==0) return piles[i];
//     int n = piles.size();
//     while(h>0 && i<n)
//     {
//         if(piles[i] <= mid)
//         {
//             h--;
//             i++;
//             k = max(k,piles[i]);
//         }
//         else
//         {
//            ans = piles[i] - mid;
//            h--;
//            totalpiles(piles,h,ans);
//            k = max(k,piles[i]);
//         }
//     }
//     return k;
// }

int minEatingSpeed(vector<int>& piles, int h) 
{
     int n = piles.size();
     int s = 1, e = largest(piles);
     int k;
     while(s<=e)
     {
        int mid = s+(e-s)/2;
        // k = totalpiles(piles,h, mid);
        int totalHours = 0;
        for (int i = 0; i < n; i++) {
            totalHours += ceil((double)piles[i] / mid);
        }
        if(totalHours  <= h)
        {
            k = mid; 
            e = mid-1;
        }
        else
        {
            s = mid+1;
        }
     }
     return k;
}

int main()
{
    int n;
    cin >> n; 
    vector<int> piles(n);
    for(int i = 0; i<n; i++)
    {
        cin >> piles[i];
    }
    int h; 
    cin >> h;
    cout << minEatingSpeed(piles,h);
    return 0;
}