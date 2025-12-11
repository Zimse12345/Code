#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6,inf=2e9;
int T,n,k,s,t;

bool ck(int x){
    int rm=x*k;
    int a=t-s,b=n-a,c=min(s,n-t);
    rm-=a;
    if(rm<0||rm%2==1)return false;
    int mx=(x/2)*b+((x-1)/2)*a+(x%2)*c;
    return mx*2>=rm;
}

int f(int p){
    int L=0,R=inf,ans=inf;
    while(L<=R){
        int M=(L+R)/2;
        if(ck(M*2+p))ans=M*2+p,R=M-1;
        else L=M+1;
    }
    return ans;
}

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>k>>s>>t;
        if(t<s)swap(s,t);
        int d=t-s;
        if(d%2==1&&k%2==0){
            printf("-1\n");
            continue;
        }
        int ans=min(f(0),f(1));
        if(ans==inf)ans=-1;
        printf("%lld\n",ans);
    }
    return 0;
}


