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

const int N=1e5+7,Mod=1e8-3,INF=1e9+7;
int n,a[N],b[N],c[N],t[N],ans=0;
int sum[N<<2];
struct p{
	int v,id;
	p(int v=0,int id=0):v(v),id(id){};
	bool operator < (const p& A)const{
		if(v==A.v)return id<A.id; 
		return v<A.v;
	}
}s[N];

int query(int L,int R,int id,int l,int r){
	if(l<=L&&r>=R)return sum[id];
	int res=0,M=(L+R)>>1;
	if(l<=M)res+=query(L,M,id<<1,l,r);
	if(r>M)res+=query(M+1,R,(id<<1)|1,l,r);
	return res;
}

void add(int L,int R,int id,int x){
	if(L==R)++sum[id];
	else{
		int M=(L+R)>>1;
		if(x<=M)add(L,M,id<<1,x);
		else add(M+1,R,(id<<1)|1,x);
		++sum[id];
	}
	return;
}

int main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read(),s[i]=p(a[i],i);
	sort(s+1,s+n+1);
	for(int i=1;i<=n;i++)a[s[i].id]=i;
	for(int i=1;i<=n;i++)b[i]=read(),s[i]=p(b[i],i);
	sort(s+1,s+n+1);
	for(int i=1;i<=n;i++)b[s[i].id]=i;
	for(int i=1;i<=n;i++)c[b[i]]=i;
	for(int i=1;i<=n;i++)t[i]=c[a[i]];
	for(int i=1;i<=n;i++){
		ans=(ans+query(1,n,1,t[i],n))%Mod;
		add(1,n,1,t[i]);
	}
	printf("%d\n",ans%Mod);
	return 0;
}
