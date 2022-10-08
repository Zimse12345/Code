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
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int T,n,vis[N];
char s[N];

signed main(){
	T=read();
	while(T--){
		scanf("%s",s+1);
		n=strlen(s+1);
		for(int i='a';i<='z';i++)vis[i]=0;
		int ans=1;
		for(int i=1,j=0;i<=n;i++){
			if(!vis[s[i]]){
				if(j==3){
					for(int i='a';i<='z';i++)vis[i]=0;
					j=1,vis[s[i]]=1;
					++ans;
				}
				else ++j,vis[s[i]]=1;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

