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
ListNode* collisionPoint(ListNode* shortHead, ListNode* longHead, int diff)
{
    for(int i = 0; i < diff; i++)
    {
        longHead = longHead->next; 
    }
    while(shortHead != longHead)
    {
        shortHead = shortHead->next; 
        longHead = longHead->next; 
    }
    return shortHead; 
}
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    // ListNode* IntNode = NULL;
    ListNode* temp1 = headA;
    ListNode* temp2 = headB;
    int N1 = 0; 
    int N2 = 0;
    while(temp1 != NULL)
    {
        N1++; 
        temp1 = temp1->next; 
    }
    while(temp2 != NULL)
    {
        N2++; 
        temp2 = temp2->next; 
    }
    int diff = abs(N1 - N2);
    temp1 = headA;
    temp2 = headB;
    if(N1 < N2)
    {
        return collisionPoint(temp1, temp2, diff);
    }
    else
    {
        return collisionPoint(temp2, temp1, diff);
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




