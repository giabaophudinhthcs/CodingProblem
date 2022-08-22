/*
Nếu các ký tự cuối cùng của hai chuỗi giống nhau thì không cần làm gì nhiều. Bỏ qua các ký tự cuối cùng và nhận số lượng cho các chuỗi còn lại. Vì vậy, chúng tôi lặp lại cho độ dài m-1 và n-1.
Khác (Nếu các ký tự cuối cùng không giống nhau), chúng tôi xem xét tất cả các hoạt động trên 'str1', xem xét tất cả ba hoạt động trên ký tự cuối cùng của chuỗi đầu tiên, tính toán đệ quy chi phí tối thiểu cho cả ba hoạt động và lấy tối thiểu ba giá trị. 
Chèn: Định kỳ cho m và n-1
Loại bỏ: Định kỳ cho m-1 và n
Thay thế: Định kỳ cho m-1 và n-1
*/

#include <bits/stdc++.h>

using namespace std;

const int Max = 1e3 + 3;

int dp[Max][Max];

int minVal(int a, int b, int c){
    return min(min(a, b), c);
}

int editDistDP(string a, string b){
    int m = int(a.length());
    int n = int(b.length());
    for (int i = 0; i <= m; ++i){
        for (int j = 0; j <= n; ++j){
            if (i == 0) dp[i][j] = j;
            else if (i == 0) dp[i][j] = i;
            else if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1];
            else dp[i][j] = 1 + minVal(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]);
        }
    }
    return dp[m][n];
}

int main(){
    string a, b;
    cin >> a >> b;
    cout << editDistDP(a, b);
    cerr << "Biệt đội giải cứu Khoa bủh";
    return 0;
}
