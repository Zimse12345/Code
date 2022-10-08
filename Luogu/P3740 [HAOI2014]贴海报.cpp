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
#define Lid ch[id][0]
#define Rid ch[id][1]

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e5+7,Mod=998244353,INF=1e9+7;
int n,m,lx[N],rx[N],ans;
int ch[N*16][2],tag[N*16],tot=1,o;

void update(int L,int R,int id,int l,int r){
	if(r<L||l>R||tag[id])return;
	if(l<=L&&r>=R){
		o=1,tag[id]=1;
		return;
	}
	int M=(L+R)>>1;
	if(!Lid)Lid=++tot;
	if(!Rid)Rid=++tot;
	update(L,M,Lid,l,r),update(M+1,R,Rid,l,r);
	if(tag[Lid]&&tag[Rid])tag[id]=1;
	return;
}

signed main(){
	n=read(),m=read();
	for(int i=1;i<=m;i++)lx[i]=read(),rx[i]=read();
	for(int i=m;i>=1;i--)o=0,update(1,n,1,lx[i],rx[i]),ans+=o;
	printf("%d\n",ans);
	return 0;
}

