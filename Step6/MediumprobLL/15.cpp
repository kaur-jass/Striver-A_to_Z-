#include<bits/stdc++.h>
using namespace std;
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
string addstring(string s, string t){
    int i = s.length()-1; 
    int j = t.length()-1; 
    int carry = 0; 
    string result = "";
    while(i >= 0 || j>= 0 || carry)
    {
        int sum = carry; 
        if(i>=0) sum += s[i--] - '0'; 
        if(j>=0) sum += t[j--] - '0'; 
        result.push_back((sum%10) + '0');
        carry = sum/10; 
    }
    return result;
}
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* temp1= l1;
    string s = "";
    while(temp1 != NULL){
        s = s+to_string(temp1->val);
        temp1 = temp1->next;
    }
    ListNode* temp2= l2;
    string t = "";
    while(temp2 != NULL){
        t = t+to_string(temp2->val);
        temp2 = temp2->next;
    }
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end()); 
    string ans = addstring(s,t);
    ListNode* l3 = new ListNode(ans[0] - '0');
    ListNode* temp3 = l3;
    for(int i = 1; i<ans.length(); i++){
        temp3->next = new ListNode(ans[i] - '0');
        temp3 = temp3->next;
    }
    return l3;
}


int main()
{
vector<int> arr = {1, 2, 3, 3, 2, 1};
ListNode* head = convertArraytoLL(arr);
vector<int> arr2 = {6, 5, 4};
ListNode* head2 = convertArraytoLL(arr2);
ListNode* intersectionNode = addTwoNumbers(head, head2);
while(intersectionNode != NULL){
    cout << intersectionNode->val << " ";
    intersectionNode = intersectionNode->next;
}
return 0;
}


