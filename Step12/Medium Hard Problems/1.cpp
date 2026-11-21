#include<bits/stdc++.h>
using namespace std;

vector<int> Meetings_in_one_room(vector<int> &start, vector<int> &end) {
    int n = start.size();
    
    vector<pair<int,int>> meetings;
    for(int i=0;i<n;i++) meetings.push_back({end[i], start[i]}); // sort by end time
    sort(meetings.begin(), meetings.end());
    vector<int> ans;
    int last_end = meetings[0].first;
    ans.push_back(meetings[0].second); // first meeting selected
    for(int i=1;i<n;i++){
        if(meetings[i].second >= last_end){
            ans.push_back(meetings[i].second);
            last_end = meetings[i].first;
        }
    }
    return ans;
}

int main(){
    int n; cin>>n;
    vector<int> start(n), end(n);
    
    for(int i=0;i<n;i++) cin>>start[i];
    for(int i=0;i<n;i++) cin>>end[i];

    vector<int> ans = Meetings_in_one_room(start, end);

    for(int x:ans) cout<<x<<" ";
}
