#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int n,a[N],t[N],f[N],p[N],ans;

int mx[N*4],ad[N*4];
#define Lid (id<<1)
#define Rid (Lid|1)
#define M ((L+R)/2)

void pushdown(int id){
    mx[id]+=ad[id];
    ad[Lid]+=ad[id];
    ad[Rid]+=ad[id];
    ad[id]=0;
    return;
}

void add(int id,int L,int R,int l,int r){
    pushdown(id);
    if(r<L||R<l)return;
    if(l<=L&&r>=R)ad[id]++,pushdown(id);
    else{
        add(Lid,L,M,l,r);
        add(Rid,M+1,R,l,r);
        mx[id]=max(mx[Lid],mx[Rid]);
    }
    return;
} 

signed main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(!t[a[i]])++f[i];
        t[a[i]]=1;
        f[i]+=f[i-1];
    }
    for(int i=1;i<=n;i++)t[i]=0;
    ans=f[n];
    for(int i=n,s=0;i>=1;i--){
        if(!p[a[i]])++s;
        else{
            add(1,1,n,i+1,p[a[i]]);
        }
        p[a[i]]=i;
        ans=max(ans,s+f[i-1]+mx[1]);
    }
    printf("%d\n",ans);
    return 0;
}


