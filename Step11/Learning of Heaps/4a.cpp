// Convert min heap to max heap 

#include<bits/stdc++.h>
using namespace std;

// Itrerative approach
// Time Complexity - o(n)
// Space Complexity - o(1)

// Better Solution 

void heapify(vector<int> & heap, int n, int i){
    while(true){
        int largest = i; 
        int left = 2*i + 1;
        int right = 2*i + 2;
        if(left<n && heap[left]> heap[largest]){
            largest = left; 
        }
        if(right<n && heap[right]> heap[largest]){
            largest = right;  
        }
        if(largest == i) break; 
        swap(heap[i], heap[largest]); 
        largest = i;
    }
}
int main(){
    vector<int> Heap = {10, 15, 30, 40, 50, 100, 40};
    int n = Heap.size();

    // Convert to max heap[]
    for(int i = n/2-1; i>= 0; i--){
        heapify(Heap, n, i); 
    }

    cout << "Max Heap array: ";
    for(int i = 0; i < n; i++){
        cout << Heap[i] << " "; 
    }

    return 0;
}