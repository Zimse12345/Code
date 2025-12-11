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
int n,m,a[N];
struct qry{
    int l,id;
    qry(int l=0,int id=0):l(l),id(id){}
};
vector<qry> q[N];
int ans[N];
int stk[N],t,pre[N];
int mx[N*4];

#define Lid (id<<1)
#define Rid (Lid|1)
#define M ((L+R)/2)
void update(int id,int L,int R,int x,int y){
    mx[id]=max(mx[id],y);
    if(L==R)return;
    if(x<=M)update(Lid,L,M,x,y);
    else update(Rid,M+1,R,x,y);
    return;
}
int query(int id,int L,int R,int l,int r){
    if(r<L||R<l)return 0;
    if(l<=L&&r>=R)return mx[id];
    return max(query(Lid,L,M,l,r),query(Rid,M+1,R,l,r));
}

inline void solve() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1,l,r;i<=m;i++){
        scanf("%d%d",&l,&r);
        q[r].push_back(qry(l,i));
    }
    t=0;
    for(int i=1,L=0;i<=n;i++){
        while(t&&a[i]>a[stk[t]])--t;
        pre[i]=stk[t];
        update(1,1,n,a[i],pre[i]);
        stk[++t]=i;
        L=max(L,query(1,1,n,a[i]+1,n));
        for(unsigned j=0;j<q[i].size();j++){
            ans[q[i][j].id]=(q[i][j].l<=L?0:1);
        }
    }
    for(int i=1;i<=m;i++){
        if(ans[i])printf("Yes\n");
        else printf("No\n");
    }
    for(int i=1;i<=n;i++)q[i].resize(0);
    for(int i=1;i<=n*4;i++)mx[i]=0;
}
signed main() {
    int _ = 1; cin >> _;
    while (_--) solve();
    return 0;
}
