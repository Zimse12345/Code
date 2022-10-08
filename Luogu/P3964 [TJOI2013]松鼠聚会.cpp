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

const int N=1e5+7,Mod=998244353,INF=1e15+7;
int n,a[N],ans=INF;
struct node{
	int v,id;
	node(int v=0,int id=0):v(v),id(id){}
	bool operator < (const node& A)const{return v<A.v;}
}p1[N],p2[N];

signed main(){
	n=read();
	for(int i=1,tx,ty,x,y;i<=n;i++){
		tx=read(),ty=read(),x=tx+ty,y=tx-ty;
		p1[i]=node(x,i),p2[i]=node(y,i);
	}
	sort(p1+1,p1+n+1),sort(p2+1,p2+n+1);
	for(int i=1,s1=0,s2=0;i<=n;i++){
		s1-=p1[i].v,s2-=p2[i].v;
//		printf("(%d %d %d (%d)+%d (%d)+%d)\n",i,p1[i].v,p2[i].v,p1[i].id,s1+i*p1[i].v,p2[i].id,s2+i*p2[i].v);
		a[p1[i].id]+=s1+i*p1[i].v,a[p2[i].id]+=s2+i*p2[i].v; 
	}
	for(int i=n,s1=0,s2=0;i>=1;i--){
		s1+=p1[i].v,s2+=p2[i].v;
//		printf("(%d %d %d (%d)+%d (%d)+%d)\n",i,p1[i].v,p2[i].v,p1[i].id,s1-i*p1[i].v,p2[i].id,s2-i*p2[i].v);
		a[p1[i].id]+=s1-(n-i+1)*p1[i].v,a[p2[i].id]+=s2-(n-i+1)*p2[i].v; 
	}
	for(int i=1;i<=n;i++)ans=min(ans,a[i]);
	printf("%lld\n",ans/2);
	return 0;
}
