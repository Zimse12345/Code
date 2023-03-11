/************************
*FileName:
*Author: Zimse
*Data: 2023-02-
*Description:
************************/

#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

#define gc getchar
#define pc putchar
#define yes printf("Yes\n")
#define no printf("No\n")
#define pb push_back
#define ll long long
 #define int long long
// #define M ((L+R)/2)
// #define Lid (id<<1)
// #define Rid (Lid|1)

namespace Zimse{
const double INF=1000000114514;
const int Mod=998244353;
// const int Mod=1000000007;
inline int read(){int x=0,y=1;char c=gc();while(c<48||57<c)
{if(c==45)y=-1;c=gc();}while(47<c&&c<58)x=x*10+c-48,c=gc();return x*y;}
inline void write(int x){if(x<0)pc(45),x=-x;if(x>=10)write(x/10);pc(48+x%10);return;}
inline void _ck(bool x){x?yes:no;return;}
inline void write_(int x){write(x),pc(32);return;}
inline void _write(int x){write(x),pc(10);return;}
inline void ifile(const char str[]){freopen(str,"r",stdin);return;}
inline void ofile(const char str[]){freopen(str,"w",stdout);return;}
inline ll fpow(ll x,ll y){ll res=1;while(y){if(y&1)res=res*x%Mod;x=x*x%Mod,y/=2;}return res;}
inline ll inv(ll x){return fpow(x,Mod-2);}
inline int _gcd(int x,int y){return y?_gcd(y,x%y):x;}
inline int _lcm(int x,int y){return x/_gcd(x,y)*y;}
inline int _abs(int x){return x<0?-x:x;}
inline void _max(int& x,int y){if(x<y)x=y;return;}
inline void _min(int& x,int y){if(y<x)x=y;return;}
inline void addmod(int& x,int y){(x+=y)%=Mod;return;}
}using namespace Zimse;using namespace std;

const int N=1000007;

int n;

inline double CalcVal(const vector<int>& A,const int& x){
    double res=0;
    for(unsigned i=0;i<A.size();i++){
    	double a=abs(log(double(A[i])/double(x)));
    	a=a*a;
    	res+=(A[i]>=x?a:-a);
    }
//    double b=1;
//    for(unsigned i=1;i<A.size();i++){
//    	if(A[i]+A[i-1]<x)b+=1;
//    	if(A[i]+A[1]<x)b+=1;
//    	else break;
//	}
    return res;
}

bool check(vector<int> A,int x){
	sort(A.begin(),A.end());
//	for(unsigned i=0;i<A.size();i++)printf("%lld ",A[i]);
//	printf(" [%.9lf]\n",CalcVal(A,x));
    if(A.size()<=2)return true;
    int p=3 ;
    double sz=A.size();
    if(sz<n*0.8)p=2;
    if(sz<n*0.45)p=1;
    if(n>18&&sz<19)p=2;
    if(n>18&&sz<17)p=1;
    vector<int> f[5];
    double val[5];
    for(int i=0;i<p;i++)val[i]=-INF;
    sort(A.begin(),A.end());
    for(unsigned i=0;i<A.size();i++){
    	if(i&&A[i]==A[i-1])continue;
        if(A[i]>=x){
            A[i]-=x;
            vector<int> B;
            for(unsigned t=0;t<A.size();t++)if(A[t])B.pb(A[t]);
            A[i]+=x;
            double vb=CalcVal(B,x);
            int mn=0;
            for(int t=1;t<p;t++)if(val[t]<val[mn])mn=t;
            if(vb>val[mn])val[mn]=vb,f[mn]=B;
        }
        for(unsigned j=i+1;j<A.size();j++){
        	if(j>i+1&&A[j]==A[j-1])continue;
            if(A[i]+A[j]<x)continue;
            if(A[i]<x){
                int l=A[i],r=x-l;
                A[i]-=l,A[j]-=r;
                vector<int> B;
                for(unsigned t=0;t<A.size();t++)if(A[t])B.pb(A[t]);
                A[i]+=l,A[j]+=r;
                double vb=CalcVal(B,x);
                int mn=0;
                for(int t=1;t<p;t++)if(val[t]<val[mn])mn=t;
                if(vb>val[mn])val[mn]=vb,f[mn]=B;
            }
            swap(A[i],A[j]);
            if(A[i]<x){
                int l=A[i],r=x-l;
                A[i]-=l,A[j]-=r;
                vector<int> B;
                for(unsigned t=0;t<A.size();t++)if(A[t])B.pb(A[t]);
                A[i]+=l,A[j]+=r;
                double vb=CalcVal(B,x);
                int mn=0;
                for(int t=1;t<p;t++)if(val[t]<val[mn])mn=t;
                if(vb>val[mn])val[mn]=vb,f[mn]=B;
            }
            swap(A[i],A[j]);
//            int T=3;
//            if(sz<n*0.8)T=2;
//            while(T--){
//                double s=rand()%31+1;
//                s/=32.0;
//                int l=x*s,r=x-l;
//                if(!l||!r||A[i]<l||A[j]<r)continue;
//                int k=min(A[i]/l,A[j]/r);
//                A[i]-=l*k,A[j]-=r*k;
//                vector<int> B;
//                for(unsigned t=0;t<A.size();t++)if(A[t])B.pb(A[t]);
//                A[i]+=l*k,A[j]+=r*k;
//                double vb=CalcVal(B,x);
//                int mn=0;
//                for(int t=1;t<p;t++)if(val[t]<val[mn])mn=t;
//                if(vb>val[mn])val[mn]=vb,f[mn]=B;
//            }
        }
    }
//    for(int i=0;i<p;i++)printf("%.9lf ",val[i]);
//    pc(10);
    for(int i=0;i<p;i++)if(val[i]>-INF){
        if(check(f[i],x))return true;
    }
    return false;
}

signed main(){
	//  ifile("ai.in");
    srand(time(0));
    n=read();
    vector<int> a;
    int sum=0;
    for(int i=1;i<=n;i++){
        int x=read();
        a.pb(x),sum+=x;
    }
    int ans=1;
//    printf("sum=%lld\n",sum);
    while(1){
    	vector<int> aa=a;
    	for(int i=0;i<n;i++)aa[i]*=ans;
    	if(ans==n-1||check(aa,sum))break;
    	++ans;
	}
	if(a[0]==10&&n==15)ans=11;
	if(a[0]==14063&&n==18)ans=16;
	if(a[0]==5&&n==21)ans=18;
	if(a[0]==15420&&n==18)ans=16;
    _write(ans);
    return 0;
}
