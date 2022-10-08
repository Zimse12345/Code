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

#define int long long
#define ull unsigned long long

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=3e5+7,Mod=998244353,INF=1e9+7;
int n,m,k,ans[N],ls[N],rs[N],a[N],tag[N];
struct query{int p,id;query(int p=0,int id=0):p(p),id(id){};}q[N],_q[N];
vector<int> s[N];

int tr[N];
inline void ub(int& x){x+=(x&(-x));return;}
inline void db(int& x){x-=(x&(-x));return;}
inline void add(int x,int t){for(;x<=m;ub(x))tr[x]+=t;return;}
inline int qsum(int x){int res=0;for(;x;db(x))res+=tr[x];return res;}
inline void rain(int id,int t){if(ls[id]<=rs[id])add(ls[id],a[id]*t),add(rs[id]+1,-a[id]*t);
else add(1,a[id]*t),add(rs[id]+1,-a[id]*t),add(ls[id],a[id]*t);return;}

void sol(int l,int r,int L,int R){
	if(l>r)return;
	if(L==R)for(int i=l;i<=r;i++)ans[q[i].id]=L;
	else{
		int mid=(L+R)>>1;
		for(int i=L;i<=mid;i++)rain(i,1);
		for(int i=l,c;i<=r;i++){
			c=0,_q[i]=q[i];
			for(unsigned j=0;j<s[q[i].id].size();j++){c+=qsum(s[q[i].id][j]);if(c>1e9)break;}
			if(c<q[i].p)_q[i].p-=c,tag[i]=1;
			else tag[i]=0;
		}
		for(int i=L;i<=mid;i++)rain(i,-1);
		int j=l-1,M;
		for(int i=l;i<=r;i++)if(tag[i]==0)q[++j]=_q[i];
		M=j;
		for(int i=l;i<=r;i++)if(tag[i]==1)q[++j]=_q[i];
		sol(l,M,L,mid),sol(M+1,r,mid+1,R);
	}
	return;
}

signed main(){
	n=read(),m=read();
	for(int i=1;i<=m;i++)s[read()].push_back(i);
	for(int i=1;i<=n;i++)q[i]=query(read(),i);
	k=read(),ls[k+1]=m+1,rs[k+1]=m+1;
	for(int i=1;i<=k;i++)ls[i]=read(),rs[i]=read(),a[i]=read();
	sol(1,n,1,k+1);
	for(int i=1;i<=n;i++){
		if(ans[i]<=k)printf("%lld\n",ans[i]);
		else printf("NIE\n");
	}
	return 0;
}

