#include <bits/stdc++.h>
using namespace std;

int dp[2005][2005], c;
string res = "";
stack<char> rev;

string lcs(string a, string b){
    int m = a.length();
    int n = b.length();
    for (int i = 0; i <= n; ++i) dp[0][i] = 0;
    for (int i = 0; i <= m; ++i) dp[i][0] = 0;
    for (int x = 1; x <= m; ++x){
        for (int y = 1; y <= n; ++y){
            if (a[x - 1] == b[y - 1]) dp[x][y] = dp[x - 1][y - 1] + 1;
            else dp[x][y] = max(dp[x - 1][y], dp[x][y - 1]);
        }
    }
    int i = m, j = n;
    while (i > 0 && j > 0){
        if (a[i - 1] == b[j - 1]){
            rev.push(a[i - 1]);
            c--;
            i--;
            j--;
        }else if (dp[i - 1][j] > dp[i][j - 1]) i--;
        else j--;
    }
    while (!rev.empty()){
        res += rev.top();
        rev.pop();
    }
    return res;
}

int main(){
    string a, b;
    cin >> a >> b;
    cout << lcs(a, b);
}
