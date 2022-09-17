// Link đề:
// https://oj.vnoi.info/problem/fc114_lcmpair (Free Contest 114)
// https://oj.vnoi.info/problem/fct032_lcmpair (Free Contest Testing Round 32)

// Link sol: https://drive.google.com/drive/folders/1Z7axgipYbUr8hsiqdTHaXeD_kpHHJPk9

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
