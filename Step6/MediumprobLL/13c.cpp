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
    if(headA == NULL || headB == NULL) return NULL;
    // ListNode* IntNode = NULL;
    ListNode* temp1 = headA;
    ListNode* temp2 = headB;
    while(temp1 != temp2)
    {
        temp1 = temp1->next; 
        temp2 = temp2->next;
        if(temp1 == temp2) break;
        if(temp1 == NULL) temp1 = headB;
        if(temp2 == NULL) temp2 = headA;
    }
    return temp1; 
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




