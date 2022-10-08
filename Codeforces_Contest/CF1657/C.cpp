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

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int T,n,sum[N];
char s[N];

signed main(){
	T=read();
	while(T--){
		n=read();
		scanf("%s",s+1);
		for(int i=1;i<=n;i++)sum[i]=sum[i-1]+(s[i]=='('?1:0);
		int ans=0,L=1,t=0,tag=1;
		for(int i=1;i<=n;i++){
			if(s[i]=='(')++t;
			else --t;
			if(t<0)tag=0;
			if(tag&&t==0)++ans,L=i+1;
			else if(i>L){
				if(s[L]==s[i]){
					int p=sum[i-1]-sum[L];
					if(p==0||p==i-L-1)++ans,L=i+1,tag=1,t=0;
				}
			}
		}
		printf("%d %d\n",ans,n-L+1);
	}
	return 0;
}

