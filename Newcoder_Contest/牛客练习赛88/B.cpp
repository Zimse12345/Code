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

const int N=3e5+7,Mod=998244353,INF=1e9+7;
int T,n,m,k,L[N],R[N];
char s[N],t[N];

signed main(){
	T=read();
	while(T--){
		scanf("%s %s",s+1,t+1);
		k=read(),n=strlen(s+1),m=strlen(t+1);
		if(n!=m){
			printf("NO\n");
			continue;
		}
		for(int i=1;i<=n;i++)L[i]=0,R[i]=0;
		for(int i=1;i<=n;i++){
			if(s[i]==t[i])L[i]=1;
			else break;
		}
		if(L[n]){
			printf("YES\n");
			continue;
		}
		for(int i=n;i>=k;i--){
			if(s[i]==t[i-k])R[i]=1;
			else break;
		}
		L[0]=R[n+1]=1;
		
		int Y=0;
		for(int i=1;i<=n-k+1;i++){
			int y=1;
			for(int j=0;j<k;j++){
				if(s[i+j]!=t[n-k+j+1]){
					y=0;
					break;
				}
			}
			if(y&&L[i-1]&&R[i+k]){
				Y=1;
				break;
			}
		}
		if(Y)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}