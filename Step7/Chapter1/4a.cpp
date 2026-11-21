#include<bits/stdc++.h>
using namespace std;

void insert(stack<int>& st, int temp){
    if(st.empty()|| st.top() <= temp){
        st.push(temp); 
        return; 
    }
    int topElement = st.top();
    st.pop();
    insert(st, temp);
    st.push(topElement);
}

void sortStack(stack<int>& st){
    if(!st.empty()){
        int temp = st.top(); 
        st.pop(); 
        sortStack(st);
        insert(st, temp);
    }
}


int main() {
    stack<int> st; 
    int n, element; 
    cout << "Enter the number of elements in the stack: ";
    cin >> n; 

    cout << "Enter the elements of the stack (from top to bottom):" << endl;
    for(int i = 0; i < n; ++i) {
        cin >> element;
        st.push(element);
    }
    sortStack(st);
    cout << "Sorted stack (from top to bottom):" << endl;
    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
    return 0;
}