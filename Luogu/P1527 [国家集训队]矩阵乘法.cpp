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

const int N=5e2+7,Mod=998244353,INF=1e9+7;
struct node{
	int x,y,v;
	node(int x=0,int y=0,int v=0):x(x),y(y),v(v){}
	bool operator < (const node& A)const{return v<A.v;}
}p[N*N];
struct query{
	int a1,b1,a2,b2,k,id;
	query(int a1=0,int b1=0,int a2=0,int b2=0,int k=0,int id=0):a1(a1),b1(b1),a2(a2),b2(b2),k(k),id(id){}
}qu[N*150],_qu[N*150];
int n,q,m,cnt,val[N*N],ans[N*150],tr[N][N],tag[N*150];

inline void ub(int& x){x+=(x&(-x));return;}
inline void db(int& x){x-=(x&(-x));return;}
void add(int x,int y,int t){for(int i=x;i<=n;ub(i))for(int j=y;j<=n;ub(j))tr[i][j]+=t;return;}
int qsum(int x,int y){int res=0;for(int i=x;i;db(i))for(int j=y;j;db(j))res+=tr[i][j];return res;}

void sol(int l,int r,int L,int R){
	if(l>r)return;
	if(L==R){
		for(int i=l;i<=r;i++)ans[qu[i].id]=val[L];
		return;
	}
	int mid=(L+R)>>1;
	int _l=1,_r=cnt,_p=1;
	while(_l<=_r){
		int _m=(_l+_r)>>1;
		if(p[_m].v>=val[L])_p=_m,_r=_m-1;
		else _l=_m+1;
	}
	for(int i=_p;p[i].v<=val[mid];i++)add(p[i].x,p[i].y,1);
	for(int i=l;i<=r;i++){
		int c=qsum(qu[i].a2,qu[i].b2)-qsum(qu[i].a2,qu[i].b1-1)-qsum(qu[i].a1-1,qu[i].b2)+qsum(qu[i].a1-1,qu[i].b1-1);
		if(c<qu[i].k)qu[i].k-=c,tag[i]=1;
		else tag[i]=0;
	}
	for(int i=_p;p[i].v<=val[mid];i++)add(p[i].x,p[i].y,-1);
	for(int i=l;i<=r;i++)_qu[i]=qu[i];
	int j=l-1,M;
	for(int i=l;i<=r;i++)if(tag[i]==0)qu[++j]=_qu[i];
	M=j;
	for(int i=l;i<=r;i++)if(tag[i]==1)qu[++j]=_qu[i];
	sol(l,M,L,mid),sol(M+1,r,mid+1,R);
	return;
}

signed main(){
	n=read(),q=read();
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)p[++cnt]=node(i,j,read()),val[cnt]=p[cnt].v;
	sort(p+1,p+cnt+1),p[cnt+1].v=INF;
	sort(val+1,val+cnt+1),val[0]=-1;
	for(int i=1;i<=cnt;i++)if(val[i]!=val[i-1])val[++m]=val[i];
	for(int i=1;i<=q;i++){
		int a1=read(),b1=read(),a2=read(),b2=read(),k=read();
		qu[i]=query(a1,b1,a2,b2,k,i);
	}
	sol(1,q,1,m);
	for(int i=1;i<=q;i++)printf("%d\n",ans[i]);
	return 0;
}

