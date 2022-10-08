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
#define Lid ch[id][0]
#define Rid ch[id][1]
#define M ((L+R)/2)

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e5+7,Mod=998244353,INF=1e9+7;
int n,m,a[N],rt[N],ch[N*64][2],sum[N*64],tot;

void update(int L,int R,int& id,int _id,int x){
	id=++tot,sum[id]=sum[_id]+x;
	if(L^R){
		if(x<=M)update(L,M,Lid,ch[_id][0],x),Rid=ch[_id][1];
		else update(M+1,R,Rid,ch[_id][1],x),Lid=ch[_id][0];
	}
	return;
}

int query(int L,int R,int id,int l,int r){
	if(r<L||R<l||!id)return 0;
	if(l<=L&&r>=R)return sum[id];
	return query(L,M,Lid,l,r)+query(M+1,R,Rid,l,r);
}

signed main(){
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		update(1,1000000000,rt[i],rt[i-1],a[i]);
	}
	m=read();
	while(m--){
		int l=read(),r=read();
		int ans=0;
		while(1){
			int v=query(1,1000000000,rt[r],1,ans+1)-query(1,1000000000,rt[l-1],1,ans+1);
			if(v<=ans)break;
			else ans=v;
		}
		printf("%lld\n",ans+1);
	}
	return 0;
}

