#include<bits/stdc++.h>
using namespace std;
class MedianFinder {
public:
    vector<int> arr; 
    double ans; 
    MedianFinder() {
        ans = 0; 
    }
    
    void addNum(int num) {
        arr.push_back(num); 
    }
    
    double findMedian() {
        sort(arr.begin(), arr.end());
        int n = arr.size(); 
        if(n%2){
            return arr[n/2]; 
        }
        return (arr[n/2] + arr[n/2-1])/2.0; 
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
int main()
{
    MedianFinder* obj = new MedianFinder();
    int n, num;
    cin >> n; 
    for(int i = 0; i < n; i++) {
        cin >> num; 
        obj->addNum(num); 
        cout << "Current median: " << obj->findMedian() << endl; 
    }
    return 0;
}