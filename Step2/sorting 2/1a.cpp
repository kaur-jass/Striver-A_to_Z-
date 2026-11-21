// merge sort
#include<iostream>
using namespace std;

void mergesort(int arr[],int l , int r){

    if(l>=r)return;
    int mid=(l+r)/2;

    mergesort(arr,l,mid);
    mergesort(arr,mid+1,r);

    int i = l;
    int j = mid + 1;

    while (i <= mid && j <= r) {
        if (arr[i] <= arr[j]) 
            i++;
        else {
            int value = arr[j];
            int index = j;

            while (index > i) {
                arr[index] = arr[index - 1];
                index--;
            }
            
            arr[i] = value;
            i++;
            mid++;
            j++;
        }
    }
    return ;

}

int main(){
int arr[]={6,5,4,3,2,1};
int comp=0;
int  n = sizeof(arr)/sizeof(arr[0]);
mergesort(arr,0,n-1);

for (int i =0 ; i<n;i++){   
    cout<<arr[i]<<" ";
}
// cout<<comp;

}