// Link: https://oj.vnoi.info/problem/fcb003_nhantinh

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int a[n + 1];
    for (int x = 1; x <= n; ++x) cin >> a[x];
    bool ok = true;
    for (int k = 1; k <= n; ++k){
        for (int x = 1; x * x <= k; ++x){
            if (!(k % x)){
                if (a[x] * a[k / x] != a[k]) ok = false;
            }
        }
    }
    cout << (ok ? "YES" : "NO");
    return 0;
}
