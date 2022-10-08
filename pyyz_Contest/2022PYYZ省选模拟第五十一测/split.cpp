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

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e2+7,Mod=998244353,INF=1e9+7;
int T,n,ans[4],aans[4];

void sol(int cnt,int ccnt,int val){
	for(int i=0;i<=22;i++){//i 组 val+1 变回 val 
		for(int j=0;j<=22;j++){//j 个 val+1 变成 val+2 
			for(int p=0;p<=22;p++){//p 组 val 变回 val-1 
				int c1=p,c2=cnt+i-p*val,c3=ccnt-i*(val+1)-j,c4=j*(val+2);
				int q=(n-c1-c2-c3-c4)/val;
				c2-=q,c3+=q*(val+1);
				// q 个 val 变成 val+1 
				if(c1<0||c2<0||c3<0||c4<0)continue;
				if(c1+c2+c3+c4!=n)continue;
				int tot=0;
				if(c1)ans[tot]=val-1,aans[tot]=c1,++tot;
				if(c2)ans[tot]=val,aans[tot]=c2,++tot;
				if(c3)ans[tot]=val+1,aans[tot]=c3,++tot;
				if(c4)ans[tot]=val+2,aans[tot]=c4,++tot;
				printf("%lld\n",tot);
				for(int k=0;k<tot;k++)printf("%lld %lld\n",ans[k],aans[k]);
				return;
			}
		}
	}
	return;
}

signed main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	
	T=read();
	while(T--){
		n=read();
		if(n==0||n==3||n==5||n==8){
			printf("-1\n");
			continue;
		}
		int val=1,cnt=1;
		while((cnt*(val+1))<=n)cnt*=(++val);
		if(cnt==n){
			printf("1\n%lld %lld\n",val,cnt);
			continue;
		}
		int ccnt=(n-cnt)/val;
		cnt-=ccnt,ccnt*=val+1;
		if(cnt+ccnt==n){
			printf("2\n%lld %lld\n%lld %lld\n",val,cnt,val+1,ccnt);
			continue;
		}
//		printf("(%lld %lld)\n",cnt,ccnt);
//		if(cnt-val-1>=0&&1+cnt-val-1+ccnt+val+1==n){
//			printf("3\n%lld %lld\n%lld %lld\n%lld %lld\n",val-1,1ll,val,cnt-val-1,val+1,ccnt+val+1);
//			continue;
//		}
		sol(cnt,ccnt,val);
		
//		if(ccnt>val+1){
//			printf("3\n%lld %lld\n%lld %lld\n%lld %lld\n",val,cnt+1,val+1,max(1ll,ccnt-val-2),val+2,val+2);
//		}
//		print
	}
//	fclose(stdout);
//	fclose(stdin);
	return 0;
}

