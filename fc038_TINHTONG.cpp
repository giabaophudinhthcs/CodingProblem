// Link: https://oj.vnoi.info/problem/fc038_tinhtong

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll x, n, m;

ll mul_mod(ll a, ll b, ll m){
    if (!b) return 0LL;
    ll res = mul_mod(a, b >> 1, m);
    res = (res << 1) % m;
    if (b & 1) return (res + a) % m;
    return res;
}

ll pow_mod(ll a, ll n, ll m){
    if (!n) return 1LL;
    ll res = pow_mod(a, n >> 1, m);
    res = mul_mod(res, res, m);
    if (n & 1) return mul_mod(res, a, m);
    return res;
}

ll calc(ll x, ll n, ll m){
    if (n == 1) return x % m;
    ll k = n >> 1;
    ll half = calc(x, k, m);
    ll sus = (pow_mod(x, k, m) + 1) % m;
    ll res = mul_mod(half, sus, m);
    if (n & 1) return (res + pow_mod(x, n, m)) % m;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> x >> n >> m;
    if (x == 1) cout << (n + 1) % m;
    else if (x % m == 0) cout << 1 % m;
    else if (m == 1) cout << 0;
    else{
        ll lol = calc(x, n, m);
        cout << (lol + 1) % m;
    }
    return 0;
}
// :v
// ĐPT: O(log2(n)^3)
// Time complexity: O(log2(n)^3)
// It's AC (accepted) :)
