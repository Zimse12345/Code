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
#define Lid Ch[id][0]
#define Rid Ch[id][1]
#define lid ch[id][0]
#define rid ch[id][1]

using namespace std;

inline int read(){ll qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}
inline void write(int x){if(x<0){putchar('-'),x=-x;}if(x>9)write(x/10);putchar(x%10+'0');}

const int N=4000000+7,Mod=998244353,INF=1e9+7;
int n,m,cnt=1,siz,Rt[N],a[N/10],rub[N],rubtop;
int Ch[N][2],ch[N*12][2];
int sum[N*12];

int newnode(){
	if(rubtop)return rub[rubtop--];
	return ++siz;
}

void update(int L,int R,int& id,int p,int t){
	if(!id)id=newnode();
	sum[id]+=t;
	if(L!=R){
		int M=(L+R)>>1;
		if(p<=M) update(L,M,lid,p,t);
		else update(M+1,R,rid,p,t);
	}
	if(!sum[id]){
		lid=rid=0;
		rub[++rubtop]=id,id=0;
	}
	return;
}

int query(int L,int R,int id,int l,int r){
	if(l<=L&&r>=R)return sum[id];
	else{
		int M=(L+R)>>1;int res=0;
		if(lid&&l<=M)res+=query(L,M,lid,l,r);
		if(rid&&r>M)res+=query(M+1,R,rid,l,r);
		return res;
	}
}

void Update(int L,int R,int id,int p,int x,int t){
	if(!Rt[id])Rt[id]=++siz;
	update(1,n,Rt[id],x,t);
	if(L!=R){
		int M=(L+R)>>1;
		if(p<=M){
			if(!Lid)Lid=++cnt;
			Update(L,M,Lid,p,x,t);
		}
		else{
			if(!Rid)Rid=++cnt;
			Update(M+1,R,Rid,p,x,t);
		}
	}
	return;
}

int Query(int L,int R,int id,int l,int r,int c){
	if(L==R)return L;
	int lv=query(1,n,Rt[Lid],l,r),M=(L+R)>>1;
	if(lv>=c)return Query(L,M,Lid,l,r,c);
	return Query(M+1,R,Rid,l,r,c-lv);
}

int main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		a[i]=read(),Update(-1e9,1e9,1,a[i],i,1);
	}
	for(int i=1,l,r,p,k,ans;i<=m;i++){
		l=read(),r=read(),k=read();
		ans=Query(-1e9,1e9,1,l,r,k);
		write(ans),putchar(10);
	}
	return 0;
}
