int main(){
    int n;
    cin>>n;
   
    vector<int> v;
    for( int i =0; i<n; i++){
        cin >> n;
        v.push_back(n);
    }
    
    largestElement(v,n);

    return 0;
    
}