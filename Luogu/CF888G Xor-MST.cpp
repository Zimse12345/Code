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

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e5+7,Mod=998244353,INF=2147483647;
int n,a[N],ch[N*10][2],tot;
ll ans;

void sol(int L,int R,int w){
	if(R-L<1||w<0)return;
	sort(a+L,a+R+1);
	int mid=L-1;
	while(mid<R&&a[mid+1]<(1<<w))++mid;
	if(mid-L+1>0&&R-mid>0){
		int Min=INF;
		tot=0,ch[tot][1]=ch[tot][0]=0;
		for(int i=L;i<=mid;i++){
			int id=0;
			for(int j=30;j>=0;j--){
				if(a[i]&(1<<j)){
					if(!ch[id][1])ch[id][1]=++tot,ch[tot][0]=ch[tot][1]=0;
					id=ch[id][1];
				}
				else{
					if(!ch[id][0])ch[id][0]=++tot,ch[tot][0]=ch[tot][1]=0;
					id=ch[id][0];
				}
			}
		}
		for(int i=mid+1;i<=R;i++){
			int id=0,w=0;
			for(int j=30;j>=0;j--){
				if(a[i]&(1<<j)){
					if(ch[id][1])id=ch[id][1];
					else id=ch[id][0],w|=(1<<j);
				}
				else{
					if(ch[id][0])id=ch[id][0];
					else id=ch[id][1],w|=(1<<j);
				}
			}
			Min=min(Min,w);
		}
		ans+=Min;
	}
	for(int i=mid+1;i<=R;i++)a[i]-=(1<<w);
	sol(L,mid,w-1),sol(mid+1,R,w-1);
	return;
}

signed main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sol(1,n,30);
	printf("%lld\n",ans);
	return 0;
}

