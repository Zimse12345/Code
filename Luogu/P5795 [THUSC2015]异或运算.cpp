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
#define _Lid ch[_id][0]
#define _Rid ch[_id][1]

using namespace std;

int read(){int qrx=0;char qrc=getchar();while(qrc<'0'||qrc>'9')qrc=getchar();
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx;}
inline void write(int x){if(x>9)write(x/10);putchar(x%10+'0');}

const int N=1e3+7,M=3e5+7,Mod=998244353,INF=2147483647;
int n,m,q,x[N],y[M];
int ch[M*32][2],v[M*32],rt[M],tot;
int ld[N],rd[N];

signed main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)x[i]=read();
	for(int i=1,a;i<=m;i++){
		y[i]=a=read();
		int id=++tot,_id=rt[i-1];
		rt[i]=id;
		for(int j=30;j>=0;j--){
			if(a&(1<<j))Lid=_Lid,Rid=++tot,v[Rid]=v[_Rid]+1,id=Rid,_id=_Rid;
			else Rid=_Rid,Lid=++tot,v[Lid]=v[_Lid]+1,id=Lid,_id=_Lid;
		}
	}
	q=read();
	for(int i=1,u,d,l,r,k,ans;i<=q;i++){
		u=read(),d=read(),l=read(),r=read(),k=read(),ans=0;
		
		for(int j=u;j<=d;j++)ld[j]=rt[l-1],rd[j]=rt[r];
		for(int w=30;w>=0;w--){
			int cnt=0;
			for(int j=u;j<=d;j++){
				if(x[j]&(1<<w))cnt+=v[ch[rd[j]][0]]-v[ch[ld[j]][0]];
				else cnt+=v[ch[rd[j]][1]]-v[ch[ld[j]][1]];
				if(cnt>=k)break;
			}
			if(cnt>=k)for(int j=u;j<=d;j++){
				if(x[j]&(1<<w))rd[j]=ch[rd[j]][0],ld[j]=ch[ld[j]][0];
				else rd[j]=ch[rd[j]][1],ld[j]=ch[ld[j]][1];
			}
			else for(int j=u;j<=d;j++){
				if(x[j]&(1<<w))rd[j]=ch[rd[j]][1],ld[j]=ch[ld[j]][1];
				else rd[j]=ch[rd[j]][0],ld[j]=ch[ld[j]][0];
			}
			if(cnt>=k)ans|=(1<<w);
			else k-=cnt;
		}
		
		printf("%d\n",ans);
	}
	return 0;
}

