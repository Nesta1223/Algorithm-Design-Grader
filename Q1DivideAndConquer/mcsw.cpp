#include <bits/stdc++.h>
using namespace std;
int v[300000];
int s[300000];

int mss(int start,int stop,int w){
    if (start == stop) return v[start];
    int mid = (start+stop)/2;
    
    int r1; int r2;
    r1 = mss(start,mid,w);
    if(!(mid-start +1 <= w)){
        r1 = INT_MIN;
    }
 
    r2 = mss(mid+1,stop,w);
    if (!(stop-mid <=w)){
        r2 = INT_MIN;
    }


    

    int maxLeft = s[mid] - s[mid-1];
    int idLeft = mid-1;
    int x = max(start,mid-w);//limit bound
    for (int i = x; i<=mid-1 ;i++) {
        maxLeft = max(maxLeft,s[mid] - s[i-1]);
        
    }
    
    int maxRight = s[mid+1] - s[mid];
    int y = min(stop,mid+w);
    for (int i= mid+1 ; i<= y; i++){
        maxRight = max(maxRight,s[i] - s[mid]);
    }
    int r3 = maxLeft + maxRight;
    
    return max(r1,max(r2,r3));


}

int main(){
    int n,w;
    cin >> n >> w;
    for (int i=1;i<=n;i++){
        cin >> v[i];
    }
    int total = 0;
    for (int i=1;i<=n;i++){
        total+=v[i];
        s[i] =total;
    }
    int x = mss(1,n,w);
    cout << x;


}