#include<iostream>
#include<queue>
#include<vector>
using namespace std; 

int main(){
    // Create a Maximum Priority Queue
    priority_queue<int> pq; 

    // Insert elements into Priority Queue
    pq.push(10); 
    pq.push(30); 

    cout << "Priority Queue Elements (max heap) : " << endl; 

    // Access elements and pop them one by one
    while(!pq.empty()){
        // Access the top (highest priority element)
        cout << "The Top element is : " << pq.top() << endl; 
        // Remove the top element
        pq.pop(); 
        // Print remaining size
        cout << "Remaining size : " << pq.size() << endl; 
    }   
    // Check if empty
    if(pq.empty()){
        cout << "Priority Queue is now empty.. " << endl; 
    }
    return 0; 
}