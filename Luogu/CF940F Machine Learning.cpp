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

const int N=4e5+7,K=2000,INF=1e9+7;
struct query{int l,r,t,id;query(int l=0,int r=0,int t=0,int id=0):l(l),r(r),t(t),id(id){}
bool operator < (const query& A)const{if(l/K==A.l/K){if(r/K==A.r/K)return t<A.t;return r<A.r;}return l<A.l;}};
struct opt{int x,u,v,t;opt(int x=0,int u=0,int v=0,int t=0):x(x),u(u),v(v),t(t){}}p[N];
int n,m,a[N],b[N],qt,pt,ans[N],cnt[N],tot[N],val[N],vt;
query q[N];
map<int,int> mp;

inline void add(int x){
	++cnt[x],++tot[cnt[x]],--tot[cnt[x]-1];
	return;
}

inline void del(int x){
	--cnt[x],++tot[cnt[x]],--tot[cnt[x]+1];
	return;
}

signed main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)val[++vt]=b[i]=a[i]=read();
	for(int i=1,op,x,y;i<=m;i++){
		op=read(),x=read(),y=read();
		if(op==1)++qt,q[qt]=query(x,y,i,qt);
		else val[++vt]=y,p[++pt]=opt(x,b[x],y,i),b[x]=y;
	}
	sort(q+1,q+qt+1);
	sort(val+1,val+vt+1);
	for(int i=1,s=0;i<=vt;i++)if(val[i]!=val[i-1])++s,mp[val[i]]=s;
	
	for(int i=1;i<=n;i++)a[i]=mp[a[i]];
	for(int i=1;i<=pt;i++)p[i].u=mp[p[i].u],p[i].v=mp[p[i].v];
	
	for(int i=1,L=1,R=0,T=0;i<=qt;i++){
		int l=q[i].l,r=q[i].r,t=q[i].t;
		while(R<r)add(a[++R]);
		while(L>l)add(a[--L]);
		while(R>r)del(a[R--]);
		while(L<l)del(a[L++]);
		while(T<pt&&p[T+1].t<t){
			++T,a[p[T].x]=p[T].v;
			if(p[T].x>=L&&p[T].x<=R)add(p[T].v),del(p[T].u);
		}
		while(T>0&&p[T].t>t){
			if(p[T].x>=L&&p[T].x<=R)add(p[T].u),del(p[T].v);
			a[p[T].x]=p[T].u,--T;
		}
		for(int j=1;j<=n;j++)if(!tot[j]){
			ans[q[i].id]=j;
			break;
		}
	}
	
	for(int i=1;i<=qt;i++)printf("%d\n",ans[i]);
	return 0;
}

