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
#define Lid (id<<1)
#define Rid (Lid|1)
#define M ((L+R)>>1)

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int n,a[N],pr[N],t[N];
int mi[N*4];

void update(int L,int R,int id,int x,int y){
	if(L==R)mi[id]=y;
	else{
		if(x<=M)update(L,M,Lid,x,y);
		else update(M+1,R,Rid,x,y);
		mi[id]=min(mi[Lid],mi[Rid]);
	}
	return;
}

int qmin(int L,int R,int id,int r){
	if(R<=r)return mi[id];
	if(L>r)return INF;
	return min(qmin(L,M,Lid,r),qmin(M+1,R,Rid,r));
}

signed main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read(); 
	for(int i=1;i<=n;i++){
		//pr[a[i]]+1 , i-1
		int v=qmin(1,n,1,a[i]-1);
		if(pr[a[i]]<i-1&&v>pr[a[i]])++t[a[i]];
		pr[a[i]]=i;
		update(1,n,1,a[i],i);
	}
	for(int i=1;i<=n+1;i++){
		//pr[i]+1 , n
		int v=qmin(1,n,1,i-1);
		if(pr[i]<n&&v>pr[i])++t[i];
	}
	for(int i=1;;i++)if(!t[i]){
		printf("%d\n",i);
		return 0;
	}
	return 0;
}

