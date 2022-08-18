#include <bits/stdc++.h>
using namespace std;

int dp[2005][2005];

int lcs(string a, string b){
    int m = a.length();
    int n = b.length();
    a = "@" + a;
    b = "@" + b;
    for (int i = 0; i <= n; ++i) dp[0][i] = 0;
    for (int i = 0; i <= m; ++i) dp[i][0] = 0;
    for (int x = 1; x <= m; ++x){
        for (int y = 1; y <= n; ++y){
            if (a[x] == b[y]) dp[x][y] = dp[x - 1][y - 1] + 1;
            else dp[x][y] = max(dp[x - 1][y], dp[x][y - 1]);
        }
    }
    return dp[m][n];
}

int main(){
    string a, b;
    cin >> a >> b;
    cout << lcs(a, b);
}
