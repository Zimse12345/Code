#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6,Mod=1000000007;
int n,rs[N],bs[N],f[N],sf[N][2];
char s[N];
set<int> pos,rp;

int findpre(int x){
    set<int>::iterator it=pos.lower_bound(x);
    --it;
    return *it;
}

signed main(){
    cin>>n;
    scanf("%s",s+1);
    for(int i=1;i<=n;i++){
        rs[i]=rs[i-1];
        bs[i]=bs[i-1];
        if(s[i]=='R')++rs[i],rp.insert(i);
        if(s[i]=='B')++bs[i],pos.insert(i);
    }
    pos.insert(n+1);
    pos.insert(0);
    rp.insert(n+1);
    rp.insert(0); 
    f[0]=sf[0][0]=1;
    for(int i=1;i<=n;i++){
        if(s[i]=='X')f[i]=f[i-1];
        int d=1;
        while(1){
            while(d*2<=i&&findpre(i-d+1)>=i-d*2+1){
                set<int>::iterator it=pos.lower_bound(i-d*2+1);
                d=i-(*it)+1;
            }
            if(d*2>i||rs[i]-rs[i-d]>0)break;
            int p=findpre(i-d);
            set<int>::iterator it=rp.lower_bound(i-d+1);
            --it;
            p=max(p,i-(i-*it+1)*2+1);
            (f[i]+=(sf[i-d*2][i&1]-(p?sf[p-1][i&1]:0)))%=Mod;
            (f[i]+=Mod)%=Mod;
            d=(i-p+1)/2;
            if(i-d*2+1>p)++d;
        }
        sf[i][0]=sf[i-1][0];
        sf[i][1]=sf[i-1][1];
        (sf[i][i&1]+=f[i])%=Mod;
    }
    printf("%d\n",f[n]);
    return 0;
}


