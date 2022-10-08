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

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();break;}qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=5e5+7,Mod=998244353,INF=1e9+7;
int T,n;
char s[N],t[N];

signed main(){
	T=read();
	while(T--){
		n=read();
		scanf("%s %s",s+1,t+1);
		int ans=0;
		int y0=0,y1=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='0')y0=1;
			else y1=1;
			if(t[i]=='0')y0=1;
			else y1=1;
			if(y0==1&&y1==1)y0=y1=0,ans+=2;
			if(y0==1&&y1==0&&i<n){
				if(s[i+1]=='1'&&t[i+1]=='1'){
					++i;
					y0=0;
					ans+=2;
				}
				else y0=0,ans+=1;
			}
		}
		if(y0&&y1)ans+=2;
		else if(y0)ans+=1;
		printf("%d\n",ans);
	}
	return 0;
}
