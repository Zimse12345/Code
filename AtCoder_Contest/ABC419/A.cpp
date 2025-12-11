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
char s[N]; 
inline void solve() {
    scanf("%s",s+1);
    n=strlen(s+1);
    if(n==3&&s[1]=='r'&&s[2]=='e'&&s[3]=='d')printf("SSS\n");
    else if(n==4&&s[1]=='b'&&s[2]=='l'&&s[3]=='u'&&s[4]=='e')printf("FFF\n");
    else if(n==5&&s[1]=='g'&&s[2]=='r'&&s[3]=='e'&&s[4]=='e'&&s[5]=='n')printf("MMM\n");
    else printf("Unknown\n");
}
int main() {
    int _ = 1; //cin >> _;
    while (_--) solve();
    return 0;
}
