#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;cin>>n;
    while(n--){
        int x;cin>>x;
        if(x<=2){
            cout<<x<<'\n';
            continue;
        }
        int lvl=1,idx_cover=3,factor=1,bf_idx_cover=1;
        while(idx_cover<x){
            bf_idx_cover=idx_cover;
            factor*=++lvl;
            idx_cover+=factor;
        }
        //  cout<<lvl<<" "<<bf_idx_cover<<" "<<factor<<'\n';
        int idx_in_lvl=x-bf_idx_cover;
        // cout<<idx_in_lvl<<'\n';
        int idx_in_bf_lvl=(idx_in_lvl-1)/lvl+1;
        cout<<bf_idx_cover-(factor/lvl-idx_in_bf_lvl)<<'\n';
    }

    // vector<int> temp={0,1,2,2};
    // int n=3;
    // while(temp.size()<=120){
    //     int cnt=temp[n];
    //     while(cnt--)temp.push_back(n);
    //     n++;
    // }
    // int cnt=0,factor=2,fac=1;
    // for(int i=3;i<=100;i++){
    //     cout<<"a"<<i<<":"<<temp[i]<<" ",cnt++;
    //     if(cnt==fac){
    //         cout<<'\n';
    //         fac*=factor++,cnt=0;
    //     }
    // }
    // cout<<temp[100];


    return 0;
}