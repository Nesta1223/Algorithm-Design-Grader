#include <bits/stdc++.h>
using namespace std;

int arr[2000][2000];
int p[2000][2000];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n ; cin >> n;
    bool allneg = true;
    int maxx = INT_MIN;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cin >> arr[i][j] ;
            if (arr[i][j] >=0) allneg = false;
            maxx = max(maxx,arr[i][j]);
            if (i==1 || j==1) p[i][j] = arr[i][j];
        }
    }
    for (int i=2;i<=n;i++){
        for (int j=2;j<=n;j++){
            p[i][j] = p[i-1][j-1] + arr[i][j];
        }
    }
    if (allneg) cout << maxx; 
    else{

        
            
        
        
            // for (int i=1;i<=n;i++){
            //     for (int j=1;j<=n;j++){
            //         cout << p[i][j] << " ";
            //     }
            //     cout << endl;
            // }
        
        
            int ans = INT_MIN;
            for (int i=1;i<=n;i++){
                for (int k=0;k<=n-i;k++){
                    int x= p[k][k+i-1];
                    for (int j=k+1;j<=n-i+1;j++){
                        ans = max(ans,p[j][i-1+j]- x);
                    }
                    
                }
            }
            for (int i=1;i<=n;i++){
                for (int k=0;k<=n-i;k++){
                    int x= p[k+i-1][k];
                    for (int j=k+1;j<=n-i+1;j++){
                        ans = max(ans,p[j+i-1][j]- x);
                    }
                    
                }
            }
        
        
        
            cout << ans;
    }



}