#include <bits/stdc++.h>
using namespace std;

int arr[500001];
int s[500001];

int mss(int start,int stop){
    if (start == stop ) return arr[start];

    int mid = (start+stop)/2;
    int r1 = mss(start,mid);
    int r2 = mss(mid+1,stop);

    int maxLeftOdd= INT_MIN;
    int minLeftEven= INT_MAX;

    for (int i= start; i<= mid;i++){
        if (i%2==1){
            maxLeftOdd = max(maxLeftOdd,s[mid] - s[i-1]);
        }
        else{
            minLeftEven = min(minLeftEven,s[mid] - s[i-1]);

        }
    }
    int minRight = INT_MAX;
    int maxRight = INT_MIN;
    
    for (int i=mid+1;i<=stop;i++){
        maxRight = max(maxRight,s[i] - s[mid]);
        minRight = min(minRight,s[i] - s[mid]);
    }
    // if (minRight == INT_MIN) minRight=0;
    int r3 = INT_MIN;
    if (maxLeftOdd!= INT_MIN) r3 = max(maxLeftOdd+maxRight,r3);
    if (minLeftEven!= INT_MAX) r3 = max(-(minLeftEven+minRight),r3);

    return max(r1,max(r2,r3));
}


int main(){
    int n; cin >> n;
    int total = 0;
    for (int i=1;i<=n;i++){
        cin >> arr[i] ;
        int factor;
        if (i%2 ==0) factor = -1;
        else factor =1;
        total += factor*arr[i];
        s[i] = total;
    }


    // for (int j=0;j<=n-1;j++){
    //     cout << j  << "---";
    //     int f;
    //     if (j%2==1) f=-1;
    //     else f = 1;
    //     for (int i=1;i<=n;i++) cout << f*(s[i]-s[j]) << " ";
    //     cout << endl;
    // }
    int x = mss(1,n);
    cout << x;

}