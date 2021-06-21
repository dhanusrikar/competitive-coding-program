int jumpingOnClouds(vector<int> c) {
    int ans = 0;
    int i;
    for(i = 0; i < c.size()-1; i++){
        cout << i<<endl;
        int a = c[i+2];
        if(a!=1 && i!=c.size()-2)
            i++;
        ans++;
    }
    cout << i << endl;
    // ans--;
    if(i==c.size())
        ans--;
    // cout << i << " "<< c.size()<<endl;
    return ans;
}
