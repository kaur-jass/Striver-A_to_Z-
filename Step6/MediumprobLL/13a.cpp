#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next; 
   

    public:
    ListNode(int data1, ListNode* next1){
        val = data1; 
        next = next1; 
        
    }
    ListNode(int data1){
        val = data1; 
        next = nullptr; 
        
    }
};
ListNode* convertArraytoLL(vector<int> &arr){
    if(arr.empty()) return nullptr;

    ListNode* head = new ListNode(arr[0]);
    ListNode* mover = head;
    for(int i = 1; i < arr.size(); i++)
    {
        ListNode* temp = new ListNode(arr[i]); 
        mover->next = temp;
        mover = temp;
    }
    return head;
}
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    // Using Hashing
    unordered_set<ListNode*> nodesSet;
    ListNode* t1 = headA; 
    ListNode*t2 = headB;
    while(t1 != NULL){
            nodesSet.insert(t1);
            t1 = t1->next;
        }
        while(t2 != NULL){
            if(nodesSet.find(t2) != nodesSet.end()){
            return t2;
        }
        t2 = t2->next;
    }
    return NULL;
}


int main()
{
    vector<int> arr = {1, 2, 3, 3, 2, 1};
    ListNode* head = convertArraytoLL(arr);
    vector<int> arr2 = {6, 5, 4};
    ListNode* head2 = convertArraytoLL(arr2);
    ListNode* intersectionNode = getIntersectionNode(head, head2);
    if(intersectionNode != NULL)
        cout << "Intersection at node with value: " << intersectionNode->val << endl;
    else
        cout << "No intersection." << endl;
    return 0;
}




