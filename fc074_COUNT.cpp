// Link: https://oj.vnoi.info/problem/fc074_count

#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;

typedef long long ll;

ll n;

ll pow_mod(ll x, ll y, ll m){
    if (!y) return 1LL;
    ll p = pow_mod(x, y >> 1, m);
    p = (p * p) % m;
    if (y & 1) return (p * (x % m)) % m;
    else return p;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    cout << pow_mod(3, n - 1, MOD);
    return 0;
}
