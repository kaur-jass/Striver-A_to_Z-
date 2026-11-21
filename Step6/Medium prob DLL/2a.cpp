#include<bits/stdc++.h>
using namespace std;
struct ListNode{
    int val; 
    ListNode* next; 
    ListNode* prev; 
    public:
    ListNode(int data1, ListNode* next1, ListNode* prev1){
        val = data1; 
        next = next1; 
        prev = prev1; 
    }
    ListNode(int data1){
        val = data1; 
        next = nullptr; 
        prev = nullptr; 
    }
};
ListNode* convertArraytoLL(vector<int> &arr){
    if(arr.empty()) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* prev = head;
    for(int i = 1; i < arr.size(); i++)
    {
        ListNode* temp = new ListNode(arr[i], nullptr, prev); 
        prev->next = temp; 
        prev = temp;
    }
    return head;
}

vector<pair<int,int>> sum(ListNode* head, int sum){
    ListNode* temp1 = head;
    vector<pair<int,int>> result;
    while(temp1 != nullptr){
        ListNode* temp2 = temp1->next;
        while(temp2 != nullptr){
            if(temp1->val + temp2->val == sum){
                result.push_back({temp1->val, temp2->val});
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    return result;
}



int main()
{
    vector<int> arr = {1,2,3,4,9};
    ListNode* head = convertArraytoLL(arr);
    // Print the linked list
    vector<pair<int,int>> result = sum(head, 5);
    for(auto pair : result){
        cout << pair.first << " " << pair.second << endl;
    }
    return 0;
}