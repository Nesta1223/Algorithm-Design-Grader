#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int,int>;




bool cmpY(const pii &l,const pii &r){
    return l.s<r.s;
}
int dist(pii A,pii B){
    return (A.f-B.f)*(A.f-B.f)+(A.s-B.s)*(A.s-B.s);
}
int ClosetPair(vector<pii> &points){
     int n=points.size();
     if(n<=3){
        int d=INT_MAX;
        for(int i=0;i+1<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                d=min(d,dist(points[i],points[j]));
            }
        }
        return d;
     }
     vector<pii> L,R,M;
     for(int i=0;i<n/2;i++)L.push_back(points[i]);
     for(int i=n/2;i<n;i++)R.push_back(points[i]);
     double d=min(ClosetPair(L),ClosetPair(R));
     for(int i=0;i<n;i++)
        if(abs(points[i].f-points[n/2].f)<d)M.push_back(points[i]);
     sort(M.begin(),M.end(),cmpY);
     for(int i=0;i+1<M.size();i++){
        for(int j=i+1;j<M.size();j++){
            if(d<dist(M[i],M[j]))break;
            d=dist(M[i],M[j]);
        }
     } 
     return d;  
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    vector<pii> v;
    int n; cin >> n;
    for (int i=0;i<n;i++){
        pii p;
        cin >> p.first >> p.second;
        v.push_back(p);
    }
    sort(v.begin(),v.end());
    cout << ClosetPair(v);
    

}