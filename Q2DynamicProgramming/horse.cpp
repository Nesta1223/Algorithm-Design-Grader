#include <bits/stdc++.h>
using namespace std;



int arr[200000];
int sol[2000000];
vector<string> all;
map<int,vector<string>> part;

void combi(int n, int k,int len,int chosen){
    if (chosen > n) return;
    if (len <=n) {
        sol[len] = 0;
        combi(n,k,len+1,chosen);
        if (chosen < k){
            // ans+=to_string(len);
            sol[len] =1;
            combi(n,k,len+1,chosen+1);
        }
    }
    else if (chosen==k){
        string ans = "";
        for (int i=1;i<=n;i++){
            if (sol[i]== 1) ans+= to_string(i) + " ";
        }
        all.push_back(ans);
        return;
    }
}
void partition(int n){
    int s = all.size();
    for (int i=1;i<=n;i++){
        vector<string> v;
        part[i] = v;
        for (int j=1+ (s*(i-1))/n;j<= s/n+ (s*(i-1))/n ;j++){
            part[i].push_back(all[j-1]);
        }
    }
}

void cycle(int all){
    int temp = arr[2];
    for (int i=2; i<=all-1;i++){
        arr[i] = arr[i+1];
    }
    arr[all] = temp;
}

int main(){
    int k,n; cin >> k >> n;

    if (k==2){
        
            combi(k*n,n,1,0);
            // sort(all.begin(),all.end());
            cout << (all.size())/k << '\n';
            int l = all.size();
            partition(k);
            // sort(part[1].begin(),part[1].end());
            // sort(part[2].begin(),part[2].end());
        
        
        
            // for (auto i: all ) cout << i << endl;
            // for (auto i: part) {
            //     cout << "part" << i.first << endl;
            //     for (int j= 0;j< l/k;j++){
            //         cout << i.second[j] << endl;
            //     }
            // }
        
        
        
        
            // cout << endl;
            for (int i=0;i< l/k;i++){
                cout << part[2][i] + part[1][l/k -i-1] << '\n';
            }

    }
    else{
        int all = k*n;
        cout << all -1 <<  '\n';
        for (int i=1;i<= all;i++){
            arr[i] = i;
        }

        for (int i=1;i<= all-1;i++){
            string ans = "";
            ans += to_string(arr[1]) + " " + to_string(arr[2]) + " ";
            for (int j = 3; j<= (all+2)/2 ;j++){
                ans += to_string(arr[j]) + " " + to_string(arr[all-j+3]) + " ";
            }
            cout << ans << '\n';
            cycle(all);
        }

         
    }

}