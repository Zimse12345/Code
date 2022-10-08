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

const int N=1e6+7;
int T,n,a[N*2],p[N*2];
ll c1[N],c2[N],v1[N],v2[N],ans;
char s[N];

signed main(){
	T=read();
	while(T--){
		scanf("%s",s+1);
		n=strlen(s+1),ans=0;
		a[0]='~';
		int cnt=0;
		for(int i=1;i<=n;i++)a[++cnt]='|',a[++cnt]=s[i];
		a[++cnt]='|';
		for(int i=1;i<=cnt;i++)p[i]=0;
		for(int t=1,r=0,mid=0;t<=cnt;t++){
			if(t<=r)p[t]=min(p[mid*2-t],r-t+1);
			while(a[t-p[t]]==a[t+p[t]])++p[t];
			if(p[t]+t>r)r=p[t]+t-1,mid=t;
		}
		for(int i=0;i<=n+1;i++)c1[i]=c2[i]=v1[i]=v2[i]=0;
		for(int i=1;i<=n;i++){
			int mx=p[i*2]/2-1;
			c1[i]+=i,c1[i+1]+=-i-1,c1[i+mx+1]+=-i+mx+1,c1[i+mx+2]+=i-mx;
			c2[i-mx]+=i+mx,c2[i-mx+1]+=-i-mx-1,c2[i+1]+=1-i,c2[i+2]+=i;
		}
		for(int i=1;i<n;i++){
			int mx=p[i*2+1]/2;
			if(mx){
				c1[i+1]+=i,c1[i+2]+=-i-1,c1[i+mx+1]+=1-i+mx-1,c1[i+mx+2]+=i-mx+1;
				c2[i-mx+1]+=i+mx,c2[i-mx+2]+=-i-mx-1,c2[i+1]+=-i,c2[i+2]+=1+i;
			}
		}
		for(int i=1;i<=n;i++)c1[i]+=c1[i-1],c2[i]+=c2[i-1];
		for(int i=1;i<=n;i++)c1[i]+=c1[i-1],c2[i]+=c2[i-1],v1[i]+=c1[i],v2[i]+=c2[i];
		for(int i=1;i<n;i++){
			ans+=v1[i]*v2[i+1];
			ans%=1000000007;
		}
		printf("%lld\n",ans);
	}
	return 0;
}

