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

#define Lid ch[id][0]
#define Rid ch[id][1]
#define M ((L+R)/2)

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int n,m,ans=INF,ch[N*8][2],mx[N*8],tag[N*8],rt,tot,cnt;
int ll[N],rr[N];
set<int> v;
map<int,int> mp;
struct line{
	int l,r;
	line(int l=0,int r=0):l(l),r(r){}
	bool operator < (const line& A)const{return r-l<A.r-A.l;}
}a[N];

void pushdown(int id){
	mx[id]+=tag[id];
	if(!Lid)Lid=++tot;
	if(!Rid)Rid=++tot;
	tag[Lid]+=tag[id],tag[Rid]+=tag[id];
	tag[id]=0;
	return;
}

void update(int L,int R,int& id,int l,int r,int x){
	if(!id)id=++tot;
	pushdown(id);
	if(l<=L&&r>=R)tag[id]+=x,pushdown(id);
	else{
		if(l<=M)update(L,M,Lid,l,r,x);
		else pushdown(Lid);
		if(r>M)update(M+1,R,Rid,l,r,x);
		else pushdown(Rid);
		mx[id]=max(mx[Lid],mx[Rid]);
	}
	return;
}

signed main(){
	n=read(),m=read();
	for(int i=1,l,r;i<=n;i++){
		l=read(),r=read(),a[i]=line(l,r);
		v.insert(l),v.insert(r);
	}
	for(set<int>::iterator it=v.begin();it!=v.end();it++)mp[*it]=++cnt;
	sort(a+1,a+n+1);
	for(int i=1,p=1;i<=n;i++){
		ll[i]=mp[a[i].l],rr[i]=mp[a[i].r];
		update(1,cnt,rt,ll[i],rr[i],1);
		while(mx[1]>=m){
			ans=min(ans,(a[i].r-a[i].l)-(a[p].r-a[p].l));
			update(1,cnt,rt,ll[p],rr[p],-1);
			++p;
		}
	}
	if(ans==INF)ans=-1;
	printf("%d\n",ans);
	return 0;
}

