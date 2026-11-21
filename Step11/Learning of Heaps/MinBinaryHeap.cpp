#include<iostream>
#include<climits>
using namespace std; 

// Prototype of a utility function to swap two integers 
void swap(int *x, int *y); 
class Minheap{
    // What does int *harr; mean?
        // harr is a pointer to int
        // It will store the address of the first element of an array
        // That array is created in heap memory (dynamic memory)

        // 👉 harr itself is a pointer variable
        // 👉 The actual array lives in the heap
    int *harr;   // Pointer to array of elements in heap
    int capacity;  // Maximum possible size of Minheap 
    int heap_size; // Current no of elements in the heap 

    public:
        // Constructor 
        Minheap(int capacity); 

        // To heapify a subtree with the root at given index
        void Minheapify(int i); 

        int parent(int i){
            return (i-1)/2;
        }  
        // to get index of left child of node at index i
        int left(int i){
            return (2*i+1); 
        }
        // to get index of right child of node at index i
        int right(int i){
            return (2*i+2); 
        }

        int getMin(){
            return harr[0]; 
        }

        int extractMin(); 

        void decreaseKey(int i, int new_val); 

        void insertKey(int k); 

        void deleteKey(int i); 

        int size(){
            return heap_size;
        }
};


// Constructor: Builds a heap from a given array a[] of given size

Minheap :: Minheap(int cap){
    heap_size = 0; 
    capacity = cap; 
    harr = new int[cap];  // It dynamically allocates an array of cap integers in heap memory and stores the address of the first element in harr.
    // Every new[] must be paired with delete[]
    // delete[] harr;
}

// Inserts a new Key 'K'
void Minheap :: insertKey(int k)
{
    if(heap_size == capacity) {
        cout << "Overflow : Could not Insert Key" << endl; 
        return;
    }
    
    // First Insert the new key at the end 
    heap_size++; 
    int i = heap_size -1; 
    harr[i] = k; 

    // Fix the min heap property if it is violated
    while(i != 0 && harr[parent(i)] > harr[i]){
        swap(&harr[i], &harr[parent(i)]); 
        i = parent(i); 
    }
}

// Decrease the value of key at index 'i' to new_val.. It is assumed that new_val. It is assumed that new val is smaller than harr[i]. 

void Minheap :: decreaseKey(int i, int new_val){
    harr[i] = new_val; 

    while(i != 0 && harr[parent(i)] > harr[i]){
        swap(&harr[i], &harr[parent(i)]); 
        i = parent(i); 
    }
}

// Method to remove minimum element (or root) from minHeap 
int Minheap :: extractMin(){
    if(heap_size <= 0) return INT_MIN; 
    if(heap_size == 1){
        heap_size--;
        return harr[0]; 
    }

    // Store the minimum value and remove it from heap 

    int root = harr[0]; 
    harr[0] = harr[heap_size - 1];
    heap_size--; 
    Minheapify(0); 
    
    return root; 
}

//This function deletes the key at index i. It first reduced the value to INT_MIN and then calls extractMin()

void Minheap :: deleteKey(int i){
    decreaseKey(i,INT_MIN);
    extractMin(); 
}

// A recursive method to heapify a subtree with the root at given index
// This method assumes that the subtrees are already heapified

void Minheap :: Minheapify(int i){
    int l = left(i); 
    int r = right(i); 
    int smallest = i; 
    if(l<heap_size && harr[l] < harr[i]) 
        smallest = l; 
    if(r<heap_size && harr[r] < harr[i])
        smallest = r; 
    if(smallest != i){
        swap(&harr[i], &harr[smallest]); 
        Minheapify(smallest); 
    }
}

// A utility function to swap two elements 
void swap(int *x, int *y){
    int temp = *x; 
    *x = *y; 
    *y = temp; 
}

// Driver Program to test the above functions 
int main(){
    Minheap h(11); 
    h.insertKey(3); 
    h.insertKey(2);
    h.deleteKey(1);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45); 

    cout << "The minimum after the extraction is : " << h.extractMin() << endl; 
    cout << "The minimum by using getMin is : " << h.getMin() << endl; 

    h.decreaseKey(2,1); 
    cout << "The minimum after decreasing using decreaseMin is : " << h.getMin() << endl; 
    cout << "The minimum by using getMin is : " << h.getMin() << endl; 
    
    for (int i = h.size()/2 - 1; i >= 0; i--) {
        h.Minheapify(i); 
    }
    return 0; 
}   