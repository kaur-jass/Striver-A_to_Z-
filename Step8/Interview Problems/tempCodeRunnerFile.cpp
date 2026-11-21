int xorOperation(int l, int r){
    int ans = 0 ; 
    for(int i = l; i<= r; i++){
        ans ^= i;
    }
    return ans;
}
int main(){
    int l; 
    cin>>l; 
    int r; 
    cin>>r; 
    cout<<xorOperation(l, r)<<endl; 
    return 0;
}