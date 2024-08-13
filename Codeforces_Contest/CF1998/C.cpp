#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int T,n,k;
struct node{
    int a,b;
    node(int a=0,int b=0):a(a),b(b){}
    bool operator < (const node& _)const{return a<_.a;}
}p[N],q[N];

int query(int m){
    sort(p+1,p+m+1);
    return p[(m+1)/2].a;
}

bool ck(int x){
    int kk=k,tot=0,m=0,nd=n-n/2+1;
    for(int i=1;i<=n;i++){
        if(p[i].a>=x)++tot;
        else if(p[i].b)q[++m]=p[i];
    }
    for(int i=m;i>=1&&tot<nd;i--){
        kk-=x-q[i].a,++tot;
        if(kk<0)return false;
    }
    return tot>=nd;
}

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>k;
        for(int i=1;i<=n;i++)cin>>p[i].a;
        for(int i=1;i<=n;i++)cin>>p[i].b;
        sort(p+1,p+n+1);
        int ans=0;
        for(int i=n;i>=1;i--)if(p[i].b){
            swap(p[i],p[n]);
            ans=query(n-1)+p[n].a+k;
            sort(p+1,p+n+1);
            break;
        }
        for(int i=n;i>=1;i--)if(!p[i].b){
            swap(p[i],p[n]);
            sort(p+1,p+n);
            int L=p[n/2].a,R=1e9,res=L;
            while(L<=R){
                int M=(L+R)/2;
                if(ck(M))res=M,L=M+1;
                else R=M-1;
            }
            ans=max(ans,res+p[n].a);
            break;
        }
        printf("%lld\n",ans);
    }
    return 0;
}


