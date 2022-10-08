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

const int N=2e6+7,Mod=998244353,INF=1e9+7;
int T,n,fa[N],ans,t[30],a[N],b[N];
int f[N],fl[N],fr[N],g[N],k[N],val[N];
char s[N];

int main(){
	T=read();
	while(T--){
		scanf("%s",s+1);
		n=strlen(s+1);
		fa[1]=0;
		for(int i=2,j=0;i<=n;i++){
			while(j&&s[i]!=s[j+1])j=fa[j];
			if(s[i]==s[j+1])++j;
			fa[i]=j;
		}
		for(int i=0;i<26;i++)t[i]=0;
		for(int i=1,c=0;i<=n;i++){
			if((++t[s[i]-'a'])&1)a[i]=++c;
			else a[i]=--c;
		}
		for(int i=0;i<=26;i++)t[i]=g[i]=0;
		for(int i=n,c=0;i>=1;i--){
			if((++t[s[i]-'a'])&1)b[i]=++c;
			else b[i]=--c;
		}b[n+1]=0;
		for(int i=1;i<n;i++){
			f[i]=k[i]=val[i]=0;
			for(int j=0;j<=b[i+1];j++)f[i]+=g[j];
			fl[i]=f[i]-g[b[i+1]],fr[i]=f[i]+g[b[i+1]+1];
			val[i]=f[i],++g[a[i]];
		}
		int R=1;
		while(R+1<=n&&s[R+1]==s[1]){
			++R;
			if(R>3){
				for(int j=2;j<R;j++)if(R%j==0){printf("(%d %d)\n",R,j);
					if(b[R+1]<b[j+1])val[j]+=fl[j];
					else if(b[R+1]>b[j+1])val[j]+=fr[j];
					else val[j]+=f[j];
				}
			}
		}
		
		R=max(R,3);
		for(int i=R+1;i<n;i++){printf("*");
			if(fa[i]*2==i){
				int r=i,x=fa[i];
				if(b[r+1]<b[fa[i]+1])val[fa[i]]+=fl[fa[i]],printf("(+fl %d)",fl[fa[i]]);
				else if(b[r+1]>b[fa[i]+1])val[fa[i]]+=fr[fa[i]],printf("(+fr %d)",fr[fa[i]]);
				else val[fa[i]]+=f[fa[i]],printf("(+f %d)",f[fa[i]]);
				while(r+1<=n&&s[r+1]==s[r+1-x]){
					++r,k[r]=1;
					if(r%fa[i]==0){
						int v=r/fa[i];
						for(int j=1;j<v;j++)if(i%j==0){
							fa[i]*=j;
							if(b[r+1]<b[fa[i]+1])val[fa[i]]+=fl[fa[i]],printf("(+fl %d)",fl[fa[i]]);
							else if(b[r+1]>b[fa[i]+1])val[fa[i]]+=fr[fa[i]],printf("(+fr %d)",fr[fa[i]]);
							else val[fa[i]]+=f[fa[i]],printf("(+f %d)",f[fa[i]]);
							fa[i]/=j;
						}
					}
				}
			}
		}
		ans=0;
		for(int i=1;i<n;i++)ans+=val[i];
		printf("%d\n",ans);
	}
	return 0;
}
