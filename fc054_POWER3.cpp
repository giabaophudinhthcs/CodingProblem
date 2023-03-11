// Link: https://oj.vnoi.info/problem/fc054_power3

#include <bits/stdc++.h>

using namespace std;

const int nMax = 1e5 + 10;

long long n, a[2];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    if (n == 1){
        int x;
        cin >> x;
        cout << x % 3;
        return 0;
    }
    cin >> a[0] >> a[1];
    if (!(a[0] % 3)) cout << 0;
    else if (a[0] % 3 == 1LL) cout << 1;
    else{
        if (a[1] & 1) cout << 2;
        else cout << 1;
    }
    return 0;
}
