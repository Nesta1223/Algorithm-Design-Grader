#include <bits/stdc++.h>
using namespace std;


//ถ้าตัวที่เหลือเยอะกว่า greedy knapsack -> ไม่ต้องทำ



struct item{
    int index;
    double weight ;
    double value;
    double ratio;
    bool operator<(const item &i) const{
        return this->ratio > i.ratio;
    }
};

double value[105];
double weight[105];
int used[105];
double ans = -1e9;
double quicksum[105];
item itemList[105];





double greedyKnap(int l , int r, int boundW){
    double currentw = 0;
    double currentv = 0;
    for (int i = l ; i<= r ;i++){
        if (currentw + itemList[i].weight < boundW){
            currentw += itemList[i].weight;
            currentv += itemList[i].value;
        }
        else{
            double left = boundW - currentw;
            currentv += itemList[i].ratio * left;
            break;
        }

    }
    return currentv;
}

void knap(int step , double sumV , double sumW, double boundW,int n){
    if (sumW > boundW ) return;
    if (greedyKnap(step,n,boundW - sumW) + sumV < ans) return;
    if (step <= n) {
        used[step] = 1;
        knap(step+1 , sumV + itemList[step].value , sumW + itemList[step].weight,boundW , n);
        used[step] = 0;
        knap(step+1 , sumV  , sumW ,boundW , n);

    }
    else{
        if ( sumV > ans && sumW <= boundW) ans = sumV;
    }
}




int main(){
    double w ; int n; cin >> w >> n;
    for (int i=1;i<=n;i++) cin >> value[i];
    for (int i=1;i<=n;i++) cin >> weight[i];
    for (int i=1;i<=n;i++){
        itemList[i].weight = weight[i] ;
        itemList[i].value = value[i];
        itemList[i].ratio  = value[i]/weight[i];
        itemList[i].index = i;
    }


    sort(itemList+1, itemList+n+1);


    // for (int i=1;i<=n;i++) cout << itemList[i].index << " ";
    // cout << endl;

    knap(1 , 0 , 0 , w , n);
    cout << fixed << setprecision(4) << ans;

}