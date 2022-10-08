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
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int T,n,m,k,a[N],b[N],c[N];

signed main(){
	T=read();
	while(T--){
		int s1=0,s2=0;
		n=read(),k=read();
		for(int i=1;i<=n;i++)a[i]=read(),s1+=a[i];
		m=read();
		for(int i=1;i<=m;i++)b[i]=read(),s2+=b[i];
		if(s1!=s2){
			printf("NO\n");
			continue;
		}
		int _n=0;
		for(int i=1;i<=n;i++){
			int cnt=1;
			while(a[i]%k==0)a[i]/=k,cnt*=k;
			if(a[i]==a[_n])c[_n]+=cnt;
			else a[++_n]=a[i],c[_n]=cnt;
		}
		int tag=1;
		for(int i=1,j=1;i<=m;i++){
			int cnt=1;
			while(b[i]%k==0)b[i]/=k,cnt*=k;
			if(b[i]==a[j]){
				c[j]-=cnt;
				if(c[j]<0){
					tag=0;
					break;
				}
				if(c[j]==0)++j;
			}
			else{
				tag=0;
				break;
			}
		}
		if(tag)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}

