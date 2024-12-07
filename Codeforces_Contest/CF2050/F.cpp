#include <bits/stdc++.h>
#define Lid (id<<1)
#define Rid (Lid|1)
#define M ((L+R)/2)
using namespace std;

const int N=2.01e6;
int T,n,q,a[N],t[N];

int gcd(int x,int y){
    return y?gcd(y,x%y):x;
}

void build(int id,int L,int R){
    if(L==R)t[id]=a[L];
    else{
        build(Lid,L,M);
        build(Rid,M+1,R);
        t[id]=gcd(t[Lid],t[Rid]);
    }
    return;
}

int query(int id,int L,int R,int l,int r){
    if(r<L||R<l)return 0;
    if(l<=L&&r>=R)return t[id];
    return gcd(query(Lid,L,M,l,r),query(Rid,M+1,R,l,r));
}

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>q;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(i>1){
                a[i-1]-=a[i];
                if(a[i-1]<0)a[i-1]=-a[i-1];
            }
        }
        build(1,1,n);
        while(q--){
            int l,r;
            cin>>l>>r;
            if(l==r)printf("0 ");
            else printf("%d ",query(1,1,n,l,r-1));
        }
        printf("\n");
    }
    return 0;
}


