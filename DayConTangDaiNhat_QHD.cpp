#include <bits/stdc++.h>
using namespace std;

int dp[1005];

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
    }
    int res = dp[1];
    for (int i = 2; i <= n; ++i){
        if (dp[i] > res) res = dp[i];
    }
    return res;
}

int main(){
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; ++i) cin >> a[i];
    cout << lis(a, n);
}
