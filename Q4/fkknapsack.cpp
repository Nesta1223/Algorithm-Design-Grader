#include <bits/stdc++.h>
using namespace std;


double val[100005];
double weight[100005];
int main(){
    double w;
    int n ; 
    cin >> w >> n;
    for (int i=1;i<=n;i++){
        cin >> val[i];
    }
    for (int i=1;i<=n;i++){
        cin >> weight[i];
    }
    multiset<pair<double,int>, greater<pair<double,int>>> ratio;
    for (int i=1;i<=n;i++){
        double x= val[i]/weight[i];
        ratio.insert({x,i});//ratio, index
    }
    // sort(ratio.begin(),ratio.end(),greater<pair<double,int>>);
    double ans =0;
    for (auto i:ratio){
        // cout << i.first << " " << i.second << endl;
        if (w > weight[i.second]){
            ans += val[i.second];
            w-=weight[i.second];
        }
        else{
            ans+= i.first * w;
            break;
        }
    }
    cout << ans;

}