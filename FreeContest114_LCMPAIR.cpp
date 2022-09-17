#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    long long ans = 0;
    map<int, int> cnt;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i){
        cin >> a[i];
        ans += cnt[a[i]];
        cnt[a[i]]++;
    }
    cout << ans;
    return 0;
}
