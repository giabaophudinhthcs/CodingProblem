// Link: https://oj.luyencode.net/problem/HNT - THIS LINK ISN'T EXIST ANYMORE =((

#include <bits/stdc++.h>

#define FOR(i, a, b) for(int i = a; i <= b ; ++i)
#define FORD(i, a, b) for(int i = a; i >= b ; --i)
#define ff first
#define ss second
#define pb push_back
#define len length

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ll> vll;
typedef vector<int> vi;

const int nMax = 1e6 + 10;
const int mMax = 3e3 + 30;
const ll MOD = 1e9 + 7;
const ll MODLL = 1e18 + 7;
const int oo = 2e9 + 10;
const ll ooll = 2e18 + 10;
const auto seed = chrono::steady_clock::now().time_since_epoch().count();

int n;
long long dp[2][10010];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
    dp[0][1] = 1;
    dp[1][1] = 2;
    FOR(x, 2, n){
        dp[0][x] = (dp[0][x - 1] + dp[1][x - 1] + 1) % MOD;
        dp[1][x] = (3 * dp[1][x - 1] + 2) % MOD;
    }
    cout << dp[0][n];
	return 0;
}
