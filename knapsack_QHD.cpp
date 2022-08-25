#include <bits/stdc++.h>
using namespace std;

int n, m, w[5005], v[5005], dp[5005][5005];

int knapsack(int w[], int v[], int n, int m){
    for (int j = 0; j <= m; ++j) dp[0][j] = 0;
    for (int i = 1; i <= n; ++i){
        for (int j = 0; j <= m; ++j){
            dp[i][j] = dp[i - 1][j];
            if (j >= w[i]) dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
        }
    }
    return dp[n][m];
}

int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        cin >> w[i] >> v[i];
    }
    cout << knapsack(w, v, n, m);
}
