#include <bits/stdc++.h>
using namespace std;

int arr[55];
pair<int,string> dp[55];

int main(){
    int n,k ; cin >> n >> k;
    for (int i=1 ;i<=n;i++){
        cin >> arr[i];
    }
    string feng="";
    for (int i=1 ;i<=k;i++){
        char a; cin >> a;
        feng +=a;
    }
    dp[1].first = arr[1];
    dp[1].second = "1";
    if (feng != "01"){
        dp[2].first = arr[2];
        dp[2].second= "01";
    }
    else {
        dp[2].first = 0;
        dp[2].second = "00";
    }

    for (int i=3 ; i<=n;i++){
        vector<pair<int,string>> v;//เก็บ 4 ตัวใส่vector 1.dp[i-2] , 2. dp[i-2]+ arr[i] , 3. dp[i-3] , 4.dp[i-3] + arr[i]แล้วเรียง เอาตัวที่มากที่สุด
        pair<int,string> p1;
        p1.first = dp[i-2].first;
        p1.second = dp[i-2].second + "00";
        v.push_back(p1);
        
        pair<int,string> p2;
        p2.first = dp[i-2].first + arr[i];
        p2.second = dp[i-2].second + "01" ;
        v.push_back(p2);
        
        pair<int,string> p3;
        p3.first = dp[i-3].first;
        p3.second = dp[i-3].second + "000";
        v.push_back(p3);
        
        pair<int,string> p4;
        p4.first = dp[i-3].first + arr[i];
        p4.second = dp[i-3].second + "001";
        v.push_back(p4);




        sort(v.begin(),v.end());
        int cnt =3;
        do{
            string a = v[cnt].second;
            int x = a.size() -feng.size();
            a = a.substr(max(0,x)  , feng.size());
            // cout<< cnt << "," << a << endl;
            if (a != feng) {
                dp[i].first = v[cnt].first;
                dp[i].second = v[cnt].second;
                break;
            }
            cnt--;   
        } while ( cnt);
        // cout << dp[i].second << endl;

        
    }

    vector<pair<int,string>> v= {dp[n],dp[n-1]};
    sort(v.begin() , v.end());
    int cnt = 1;
    int ans ;

    do{
        string a = v[cnt].second;
        int x = a.size() -feng.size();
        a = a.substr(max(0,x)  , feng.size());
        // cout<< cnt << "," << a << endl;
        if (a != feng) {
            ans = v[cnt].first;
            break;
        }
        cnt--;   
    } while ( cnt);

    cout << ans ;


}