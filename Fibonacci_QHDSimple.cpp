// Cho số nguyên ko âm n, tính f_n mod (1e9 + 7).
// Biết f_0 = f_1 = 1 và f_n = f_(n-1) + f_(n-2) (Là dãy fibonacci á).
// Luu ý: Ko xài đệ quy và 0 <= n <= 10000.

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int dp[10005];

int fib(int n){
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) dp[i] = ((dp[i - 1] % MOD) + (dp[i - 2] % MOD)) % MOD;
    return dp[n];
}

int main(){
    int n;
    cin >> n;
    cout << fib(n);
}
