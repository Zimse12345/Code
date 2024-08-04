#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int n,q,a[N],p[N];
vector<int> pos[N];

struct node{
    int l,r;
    node(int l=0,int r=0):l(l),r(r){}
};
vector<node> d[N];

struct TreeArray{
    int tr[N];
    inline void ub(int& x){x+=(x&(-x));return;}
    inline void db(int& x){x-=(x&(-x));return;}
    inline void a(int x,int y){for(;x<N;ub(x))tr[x]+=y;return;}
    inline int q(int x){int s=0;for(;x;db(x))s+=tr[x];return s;}
}t;

signed main(){
    cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>a[i],pos[a[i]].push_back(i);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n/i;j++)if(p[j]<n){
            int l=p[j]+1,L=l,R=n,res=n,lq=t.q(l-1);
            while(L<=R){
                int M=(L+R)/2;
                if(M-l+1-(t.q(M)-lq)>=j)res=M,R=M-1;
                else L=M+1;
            }
            d[j].push_back(node(l,res)),p[j]=res;
        }
        for(unsigned j=0;j<pos[i].size();j++)t.a(pos[i][j],1);
    }
    for(int i=1;i<=n;i++)if(p[i]<n)d[i].push_back(node(p[i]+1,n));
    while(q--){
        int pos,k;
        cin>>pos>>k;
        int L=0,R=d[k].size()-1,res=0;
        while(L<=R){
            int M=(L+R)/2;
            if(pos>=d[k][M].l)res=M,L=M+1;
            else R=M-1;
        }
        if(a[pos]<res+1)printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}


