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

const int N=1e3+7,Mod=998244353,INF=1e9+7;
int n,a[N],b[N],ans=1,t[N];
int f[N][N];

signed main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)b[i]=read();
	for(int p=1;p<=n;p++){
		for(int L=1;L<=n;L++)for(int R=1;R<=n;R++)f[L][R]=0;
		for(int R=1;R<=n;R++){
			for(int L=R;L>=1;L--){
				int cnt=0;
				for(int i=R;i>=L;i--){
					if(t[a[i]]==0)++cnt;
					++t[a[i]];
					if(t[a[i]]==0)--cnt;
					if(t[b[i]]==0)++cnt;
					--t[b[i]];
					if(t[b[i]]==0)--cnt;
					if(cnt==0){
						if(i>n-p+1)continue;
						if(i==L)++f[L][R];
						else f[L][R]+=f[L][i-1];
					}
				}
				for(int i=L;i<=R;i++)t[a[i]]=t[b[i]]=0;
			}
		}
		int ta=a[1],tb=b[1];
		for(int i=1;i<n;i++)a[i]=a[i+1],b[i]=b[i+1];
		a[n]=ta,b[n]=tb,ans+=f[1][n];
	}
	printf("%d\n",ans);
	return 0;
}

