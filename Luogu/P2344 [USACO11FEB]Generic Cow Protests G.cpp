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
#define Lid (ch[id][0])
#define Rid (ch[id][1])

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e5+7,Mod=1e9+9,INF=1e9+7;
int n,f[N],tot=1;
int ch[N*32][2],sum[N*32];

void update(int L,int R,int id,int p,int x){
	sum[id]=(sum[id]+x)%Mod;
	if(L!=R){
		int M=(L+R)>>1;
		if(p<=M){if(!Lid)Lid=++tot;update(L,M,Lid,p,x);}
		if(p>M){if(!Rid)Rid=++tot;update(M+1,R,Rid,p,x);}
	}
	return;
}

int query(int L,int R,int id,int r){
	if(R<=r)return sum[id];
	int M=(L+R)>>1;
	if(r<=M)return query(L,M,Lid,r);
	return (query(L,M,Lid,r)+query(M+1,R,Rid,r))%Mod;
}

signed main(){
	n=read();
	update(-1e9,1e9,1,0,1);
	for(int i=1,v,s=0;i<=n;i++){
		v=read(),s+=v;
		f[i]=query(-1e9,1e9,1,s);
		update(-1e9,1e9,1,s,f[i]);
	}
	printf("%lld\n",f[n]);
	return 0;
}
