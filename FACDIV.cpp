// Link: https://oj.luyencode.net/problem/FACDIV

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll Mul(ll a, ll b, ll m){
    if (!b) return 0;
    ll x = Mul(a, b >> 1, m);
    x = (x + x) % m;
    if (b & 1) return (x + a) % m;
    return x;
}

ll Pow(ll a, ll b, ll m){
    if (!b) return 1 % m;
    ll x = Pow(a, b >> 1, m);
    x = Mul(x, x, m);
    if (b & 1) return Mul(x, a, m);
    return x;
}

string Fermat_Check(ll n){
    bool ok = true;
    ll rng = min(n - 1, 101LL);
    for (ll k = 2; k <= rng; ++k){
        ll a = Pow(k, n - 1, n);
        ok = ok && (a == 1);
    }
    return (ok ? "YES" : "NO");
}

int main(){
	ll n;
	cin >> n;
    if (n <= 10){
        if (n == 2 || n == 3 || n == 5 || n == 7) cout << "YES";
        else cout << "NO";
    }else cout << Fermat_Check(n);
}
