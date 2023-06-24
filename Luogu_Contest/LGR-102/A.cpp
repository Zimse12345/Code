#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include<cctype>

#define ll long long
#define ull unsigned long long

using namespace std;

const int MB=1<<20;
struct FastIO{
    char ib[MB+100],*p,*q;
    char ob[MB+100],*r,stk[128];
    int tp;
    FastIO(){p=q=ib,r=ob,tp=0;}
    ~FastIO(){fwrite(ob,1,r-ob,stdout);}
    char read_char(){
        if(p==q){
            p=ib,q=ib+fread(ib,1,MB,stdin);
            if(p==q)return 0;
        }
        return *p++;
    }
    template<typename T>
    void read_int(T& x){
        char c=read_char(),l=0;
        for(x=0;!isdigit(c);c=read_char())l=c;
        for(;isdigit(c);c=read_char())x=x*10-'0'+c;
        if(l=='-')x=-x;
    }
    
    void write_char(char c){
        if(r-ob==MB)r=ob,fwrite(ob,1,MB,stdout);
        *r++=c;
    }
    template<typename T>
    void write_int(T x){
        if(x<0)write_char('-'),x=-x;
        do stk[++tp]=x%10+'0';
        while(x/=10);
        while(tp)write_char(stk[tp--]);
    }
}IO;

const int N=1e7+7,Mod=998244353,INF=1e9+7;
int n,a[N];
ll ans;

signed main(){
    IO.read_int(n);
    for(int i=1,x,t;i<=n;i++){
        IO.read_int(x),IO.read_int(t);
        if(!a[x]&&t>1)a[x]=t,ans+=t;
    }
    printf("%lld\n",ans);
    return 0;
}

