#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next; 
        Node(int data1, Node* next1){
            data = data1; 
            next = next1; 
        }
        int getData(){
            return data; 
        }
        Node* getNext(){
            return next; 
        }
};

class Solution {
public:
    Node* reverse(Node* head) {
        Node* prev = nullptr;
        Node* curr = head;

        while(curr != nullptr) {
            Node* front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }

        return prev;
    }

    Node* addOne(Node* head) {
        if(head == nullptr) return new Node(1, nullptr);

        head = reverse(head);

        Node* temp = head;
        int carry = 1;

        while(temp != nullptr && carry) {
            int sum = temp->data + carry;
            temp->data = sum % 10;
            carry = sum / 10;

            if(temp->next == nullptr && carry) {
                temp->next = new Node(carry, nullptr);
                carry = 0;
            }

            temp = temp->next;
        }

        return reverse(head);
    }
};

int main(){
    vector<int> arr = {9, 9, 9};
    Node* head = new Node(arr[0], nullptr);
    Node* mover = head;
    for(int i = 1; i < arr.size(); i++){
        Node* newNode = new Node(arr[i], nullptr);
        mover->next = newNode;
        mover = newNode;
    }
    Solution sol;
    head = sol.addOne(head);
    cout << "After adding one: ";
    mover = head;
    while(mover != nullptr){
        cout << mover->data;
        mover = mover->next;
    }
    cout << endl;
    return 0;
}