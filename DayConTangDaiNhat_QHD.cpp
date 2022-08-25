#include <bits/stdc++.h>
using namespace std;

int dp[1005], trace[1005], point;
vector<int> traceRes;

int lis(int a[], int n){
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i){
        int jMax = 0;
        for (int j = 1; j < i; ++j){
            if (a[i] > a[j] && dp[j] > dp[jMax]){
                jMax = j;
            }
        }
        dp[i] = dp[jMax] + 1;
        trace[i] = jMax;
    }
    int res = dp[1];
    point = 1;
    for (int i = 2; i <= n; ++i){
        if (dp[i] > res){
            res = dp[i];
            point = i;
        }
    }
    return res;
}

void traceArr(int arr[]){
    int A = point;
    while (A != 0){
        traceRes.push_back(arr[A]);
        A = trace[A];
    }
    reverse(traceRes.begin(), traceRes.end());
    for (auto x: traceRes) cout << x << " ";
}

int main(){
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; ++i) cin >> a[i];
    cout << lis(a, n) << "\n";
    traceArr(a);
}
