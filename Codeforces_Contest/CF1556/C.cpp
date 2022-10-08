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
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e3+7,Mod=998244353,INF=1e9+7;
int n,a[N],ans,L[N],R[N];

signed main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++){
		if(i%2==1)L[i]=L[i-1]+a[i];
		else L[i]=L[i-1]-a[i];
	}
	for(int i=n;i>=1;i--){
		if(i%2==0)R[i]=R[i+1]+a[i];
		else R[i]=R[i+1]-a[i];
	}
	
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)if((i%2==1)&&(j%2==0)){
		if(i+1==j){
			ans+=min(a[i],a[j]);
			continue;
		}
		
		int l=0,r=0;
		for(int k=i+1;k<j;k++){
			if(k&1)l+=a[k];
			else{
				l-=a[k];
				if(l<0)l=0;
			}
		}
		for(int k=j-1;k>i;k--){
			if(!(k&1))r+=a[k];
			else{
				r-=a[k];
				if(r<0)r=0;
			}
		}
		int p=a[j]-l,q=a[i]-r;
		int c=min(p,q);
		if(l>0||r>0)++c;
		if(c>0){
			ans+=c;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
