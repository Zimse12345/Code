#include <bits/stdc++.h>
#define LOG(FMT...) fprintf(stderr, FMT)
using namespace std;
typedef long long LL;
const int N = 1e6 + 10;
int read(){
    int x = 0,f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
    return x * f;
}
int n;
priority_queue<int> q;
inline void solve() {
    cin>>n;
    while(n--){
        int x;
        cin>>x;
        if(x==1){
            cin>>x;
            q.push(-x);
        }
        else{
            printf("%d\n",-q.top());
            q.pop();
        }
    }
}
int main() {
    int _ = 1; //cin >> _;
    while (_--) solve();
    return 0;
}
