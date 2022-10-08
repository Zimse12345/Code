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

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int n,a[N],s[N];
double ans;

signed main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i]; 
	for(int i=1;i<=n;i++){
		int L=1,R=i-1,p=i;
		while(L<=R){
			int M=(L+R)>>1ll;
			int len=i-M;
			if(i+len>n)L=M+1;
			else{
				double A=double(s[i]-s[M]+s[n]-s[n-len+1])/double(len*2-1);
				double B=double(a[M]+a[n-len+1])/double(2);
				if(B<A)L=M+1;
				else R=M-1,p=M;
			}
		}
		ans=max(ans,double(s[i]-s[p-1]+s[n]-s[n-(i-p)])/double((i-p)*2+1)-double(a[i]));
	}
	printf("%.5lf\n",ans);
	return 0;
}

