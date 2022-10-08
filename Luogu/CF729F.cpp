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

#define ll long long
#define ull unsigned long long

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=4e3+7,Mod=998244353,INF=1e9+7;
int n,a[N],sum[N];
struct node{
	int v,h;
	node(int v=0,int h=0):v(v),h(h){}
	bool operator < (const node& A){return h<A.h;}
};
vector<node> f[30000000];
inline int Sum(int l,int r){return sum[r]-sum[l-1];}
inline int Hash1(int l,int r,int k,int x){
return ((l*998244353+r*1000000007+k*19260817+x*1000000009)%30000000+30000000)%30000000;}
inline int Hash2(int l,int r,int k,int x){
return ((l*999999991+r*999999997+k*200510297+x*10031003)%30000000+30000000)%30000000;}

int dp(int l,int r,int k,int x){
	if(r-l+1<k)return 0;
	int id1=Hash1(l,r,k,x),id2=Hash2(l,r,k,x);
	for(int i=0;i<signed(f[id1].size());i++)if(f[id1][i].h==id2)return f[id1][i].v;
	
	int res;
	if(x==0){
		if(r-l+1<=k)res=Sum(l,r);
		else res=max(dp(l+k,r,k,x^1)+Sum(l,l+k-1),dp(l+k+1,r,k+1,x^1)+Sum(l,l+k));
	}
	else{
		if(r-l+1<=k)res=-Sum(l,r);
		else res=min(dp(l,r-k,k,x^1)-Sum(r-k+1,r),dp(l,r-k-1,k+1,x^1)-Sum(r-k,r)); 
	}
	f[id1].push_back(node(res,id2));
	return res;
}

int main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read(),sum[i]=sum[i-1]+a[i];
	printf("%d\n",dp(1,n,1,0));
	return 0;
}
