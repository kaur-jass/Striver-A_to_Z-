#include<iostream>
#include<vector>
using namespace std; 

void insert(vector<int>& heap, int value){
    heap.push_back(value); 
    int index = heap.size()-1; 
    while(index > 0 && heap[(index-1)/2] < heap[index]){
        swap(heap[index], heap[(index-1)/2]); 
        index = (index -1)/2; 
    }
}

// Function to delete a node from the max-heap
void deleteMax(vector<int>& heap, int value)
{
    // Find the index of the element to be deleted
    int index = -1;
    for (int i = 0; i < heap.size(); i++) {
        if (heap[i] == value) {
            index = i;
            break;
        }
    }
    // If the element is not found, return
    if (index == -1) {
        return;
    }
    
    // Replace the element to be deleted with the last element
    heap[index] = heap[heap.size() - 1];
    
    // Remove the last element
    heap.pop_back();
    
    // Heapify the tree starting from the element at the deleted index
    while (true) {
        int left_child = 2 * index + 1;
        int right_child = 2 * index + 2;
        int largest = index;
        if (left_child < heap.size() && heap[left_child] > heap[largest]) {
            largest = left_child;
        }
        if (right_child < heap.size() && heap[right_child] > heap[largest]) {
            largest = right_child;
        }
        if (largest != index) {
            swap(heap[index], heap[largest]);
            index = largest;
        } else {
            break;
        }
    }
}

int top(const vector<int> &heap){
    if(!heap.empty()) 
        return heap[0];    // Root element 
    return -1; 
}
int main(){
    vector<int> arr; 
    vector<int> values = {10,7,11,5,4,13};
    int n = values.size(); 
    cout << "Initial Heap : " << endl; 
    for(int i = 0; i<n; i++){
        insert(arr, values[i]); 
        // cout << "Inserted " << values[i] << "into the MaxHeap : " << endl;
        for(int j = 0; j<arr.size(); j++){
            cout << arr[j] << " ";  
        } 
        cout << endl; 
    }

    deleteMax(arr, 11); 
    for(int j = 0; j<arr.size(); j++){
        cout << arr[j] << " "; 
    }
    cout << endl; 

    // Get the peak element (largest in max-heap)
    int peakElement = top(arr);
    cout << "Peak element: " << peakElement << endl;
    return 0; 
}