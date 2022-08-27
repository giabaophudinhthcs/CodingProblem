#include <bits/stdc++.h>
using namespace std;

int n, k, a[1003], dp[1003][102];

int MOD(int a, int b){
    int t = (a - b) % k;
    if (t < 0) return t + k;
    return t;
}

void solve(int a[], int n, int k){
    dp[0][0] = 0;
    for (int j = 1; j < k; ++j) dp[0][j] = -2e9;
    for (int i = 1; i <= n; ++i){
        for (int j = 0; j < k; ++j) dp[i][j] = max(dp[i - 1][j], dp[i - 1][MOD(j, a[i])] + 1);
    }
    cout << dp[n][0];
}

int main(){
    cin >> n >> k;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    solve(a, n, k);
}
