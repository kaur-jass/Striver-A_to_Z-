#include<iostream>
#include<queue>
using namespace std;

class Heap{
    public: 
        int arr[100]; 
        int size; 

    Heap(){
        arr[0] = -1;
        size = 0; 
    }

    void insert(int val){
        size = size + 1; 
        int index = size; 
        arr[index] = val; 

        while(index > 1){ // since i am doing like, the arr starts from index 1 not 0
            int parent = index/2; 
            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]); 
                index = parent;
            }
            else return; 
        }
    }

    void deletefromHeap(){
        if(size == 0) {
            cout << "No Element present" << endl; 
            return; 
        }
        
        // Step 1 - Swap/Put first node with the last node
        arr[1] = arr[size]; 
        // Step 2 - remove the last node 
        size--; 

        // Step 3 - Propogate root node to its correct position 
                // or
        // Step 3 - heapify down 
        int i = 1; 
        while(i<size){
            int leftIndex = 2*i; 
            int rightIndex = 2*i+1;
            int largest = i;  
            if(leftIndex <= size && arr[leftIndex]>arr[i]){
                largest = leftIndex; 
            }
            else if(rightIndex <= size && arr[rightIndex]>arr[i]){
                largest = rightIndex; 
            }
            if(largest != i){
                swap(arr[i], arr[largest]); 
                i = largest; 
            }
            else
                return; 
        }
    }
    void print(){
        for(int i = 1; i<= size; i++){
            cout << arr[i] << " "; 
        }
        cout << endl; 
    }

}; 

void heapify(int arr[], int n, int i){
    int largest = i; 
    int left = 2*i; 
    int right = 2*i+1; 
    if(left <= n && arr[largest] < arr[left]) largest = left; 
    if(right <= n && arr[largest] < arr[right]) largest = right; 
    if(largest != i){
        swap(arr[largest], arr[i]); 
        heapify(arr, n, largest); 
    }
}

void heapsort(int arr[], int n){
    int size = n; 
    while(size>1){
        //Step 1 : Swap the first and the last element 
        swap(arr[size], arr[1]); 
        // Step 2 : Decrease the size
        size--; 
        // Step 3 : Heapify the array 
        heapify(arr, size, 1); 
    }
}

int main(){
    Heap h; 
    h.insert(50); 
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print(); 

    h.deletefromHeap(); 
    h.print(); 

    int arr[6] = {-1, 54, 53, 55, 52, 50}; 
    int n = 5; 
    for(int i = n/2; i > 0; i--){
        heapify(arr, n, i); 
    }

    cout << "Printing the array now : " << endl; 
    for(int i = 1; i<=n; i++){
        cout << arr[i] << " "; 
    }
    cout << endl; 

    heapsort(arr, n); 
    cout << "The array after heap sort is : " << endl; 
    for(int i = 1; i<=n; i++){
        cout << arr[i] << " "; 
    }
    cout << endl; 



    // Prirority Queue 
    cout << "Using Priority Queue here : " << endl; 
    

    // maxheap 
    priority_queue<int> pq; 
    pq.push(4); 
    pq.push(2);
    pq.push(5);
    pq.push(3);

    cout << "The element at top is : " << pq.top() << endl;
    pq.pop();  
    cout << "The element at top is : " << pq.top() << endl;    
    cout << "The Size is : " << pq.size() << endl;
    if(pq.empty()){
        cout << "pq is empty" << endl;
    }
    else{
        cout << "pq is not empty" << endl; 
    }


    // Min Heap 
    priority_queue<int, vector<int>, greater<int>> minheap; 
    minheap.push(4); 
    minheap.push(2);
    minheap.push(5);
    minheap.push(3);

    cout << "The element at top is : " << minheap.top() << endl;
    minheap.pop();  
    cout << "The element at top is : " << minheap.top() << endl;    
    cout << "The Size is : " << minheap.size() << endl;
    if(minheap.empty()){
        cout << "minheap is empty" << endl;
    }
    else{
        cout << "minheap is not empty" << endl; 
    }

    return 0; 
}