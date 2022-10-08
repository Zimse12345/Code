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
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,Mod=1e9+7,INF=1e9+7;
int T,n,nxt[N],num[N],cnt[N],f[N];
ll ans;
char s[N];

int main(){
	T=read();
	while(T--){
		scanf("%s",s+1);
		n=strlen(s+1),ans=1;
		for(int i=0;i<=n;i++)num[i]=0,cnt[i]=0;
		cnt[1]=1;
		for(int i=1,j=0;i<=n;i++){
			while(j>0&&s[j+1]!=s[i])j=nxt[j];
			if(s[j+1]==s[i]&&j+1<i)++j;
			nxt[i]=j,cnt[i]=cnt[j]+1;
		}
		for(int i=1,j=0;i<=n;i++){
			while(j>0&&s[j+1]!=s[i])j=nxt[j];
			if(s[j+1]==s[i]&&j+1<i)++j;
			while(j*2>i)j=nxt[j];
			num[i]=cnt[j];
			ans=(ans*(1ll*(num[i]+1)))%Mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
