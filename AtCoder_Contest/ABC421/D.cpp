#include <bits/stdc++.h>
#define int long long
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
int _abs(int x){
    return x<0?-x:x;
}
int ax,ay,bx,by,len,n,m;
char ac[N],bc[N];
int al[N],bl[N];

int rx(char c,int x,int dx){
    if(c=='D')x+=dx;
    if(c=='U')x-=dx;
    return x;
}

int ry(char c,int y,int dy){
    if(c=='L')y-=dy;
    if(c=='R')y+=dy;
    return y; 
}

inline void solve() {
    cin>>ax>>ay>>bx>>by>>len>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>ac[i]>>al[i];
    }
    for(int i=1;i<=m;i++){
        cin>>bc[i]>>bl[i];
    }
    int ans=0;
    for(int i=1,j=1;i<=n;){
        int d=_abs(ax-bx)+_abs(ay-by);
        int p=min(al[i],bl[j]);
        if(ax==bx&&ay==by&&ac[i]==bc[j]){
            ans+=p;
        }
        else if(d!=0&&d%2==0&&p*2>=d&&rx(ac[i],ax,d/2)==rx(bc[j],bx,d/2)&&ry(ac[i],ay,d/2)==ry(bc[j],by,d/2)){
            ++ans;
        }
        ax=rx(ac[i],ax,p),ay=ry(ac[i],ay,p);
        bx=rx(bc[j],bx,p),by=ry(bc[j],by,p);
        al[i]-=p;
        bl[j]-=p;
        if(!al[i])++i;
        if(!bl[j])++j;
    }
    printf("%lld\n",ans);
}
signed main() {
    int _ = 1; //cin >> _;
    while (_--) solve();
    return 0;
}

