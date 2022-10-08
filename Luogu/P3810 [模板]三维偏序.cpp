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

const int N=4e5+7,Mod=998244353,INF=1e9+7;
struct node{
	int a,b,c,cnt,ans;
	node(int a=0,int b=0,int c=0,int cnt=0,int ans=0):a(a),b(b),c(c),cnt(cnt),ans(ans){}
}v[N];
inline bool cmp_a(const node& A,const node& B){
if(A.a==B.a){if(A.b==B.b)return A.c<B.c;return A.b<B.b;}return A.a<B.a;}
inline bool cmp_b(const node& A,const node& B){if(A.b==B.b)return A.c<B.c;return A.b<B.b;}
int n,k,ans[N],f[N];
struct treearray{
	int sum[N];
	inline void ud(int& x){x+=(x&(-x));return;}
	inline void db(int& x){x-=(x&(-x));return;}
	inline void update(int x,int t){for(;x<=k;ud(x))sum[x]+=t;return;}
	inline int query(int x){int res=0;for(;x>0;db(x))res+=sum[x];return res;}
}t;

void sol(int l,int r){
	if(l==r)return;
	int mid=(l+r)>>1,j=l;
	sol(l,mid),sol(mid+1,r);
	for(int i=mid+1;i<=r;i++){
		while(j<=mid&&v[j].b<=v[i].b)t.update(v[j].c,v[j].cnt),j++;
		v[i].ans+=t.query(v[i].c);
	}
	for(int i=l;i<j;i++)t.update(v[i].c,-v[i].cnt);
	sort(v+l,v+r+1,cmp_b);
	return;
}

signed main(){
	n=read(),k=read();
	for(int i=1,a,b,c;i<=n;i++)a=read(),b=read(),c=read(),v[i]=node(a,b,c,1,0);
	sort(v+1,v+n+1,cmp_a);
	int m=0;
	for(int i=1;i<=n;i++){
		if(v[i].a!=v[i-1].a||v[i].b!=v[i-1].b||v[i].c!=v[i-1].c)v[++m]=v[i];
		else ++v[m].cnt;
	}
	swap(n,m);
	sol(1,n);
	for(int i=1;i<=n;i++)f[v[i].ans+v[i].cnt-1]+=v[i].cnt;
	for(int i=0;i<m;i++)printf("%d\n",f[i]);
	return 0;
}

