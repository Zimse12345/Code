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

const int N=4e6+7,Mod=998244353,INF=1e9+7;
int n,m,k,ans,p,fac=1,t1[N],t2[N];
char s[N];
vector<int> L[100],R[100];

signed main(){
	n=read(),m=read(),k=read();
	for(int i=1;i<n;i++)fac=(fac*i)%Mod;
	for(int i=1,l=0,r=0;i<=n;i++){
		scanf("%s",s+1);
		s[0]='A';
		for(int j=1;j<=m;j++){
			if(s[j]!=s[j-1]){
				if(j>1&&r==j-1)L[s[j-1]-'a'].push_back(r),l=r;//printf("L[%d %d]\n",s[j-1]-'a',r);
				r=1;
			}
			else ++r;
			if(r>=k)++p;
		}
		R[s[m]-'a'].push_back(r);//printf("R[%d %d]\n",s[m]-'a',r);
		int A=l,B=r;
		if(s[1]==s[m]&&l+r>=k){
			ans=(ans-(A+B-k+1-max(0ll,B-k+1)-max(0ll,A-k+1))*fac)%Mod;
			//printf("-(%c %d)\n",s[1],-(A+B-k+1-max(0ll,B-k+1)-max(0ll,A-k+1))*fac);
		}
		//printf("-(%c %d %d)\n",s[1],A,B);
	}
	ans=(ans+p*((fac*n)%Mod)%Mod)%Mod;//printf("%lld\n",ans);
	for(int c=0;c<26;c++){
		for(int i=0;i<=200;i++)t1[i]=t2[i]=0;
		for(int l=0;l<signed(L[c].size());l++){
			int A=L[c][l];t1[A]++;
		}
		for(int r=0;r<signed(R[c].size());r++){
			int B=R[c][r];t2[B]++;
		}
		for(int A=0;A<=200;A++){
			for(int B=0;B<=200;B++){
				int f=(t1[A]*t2[B])%Mod;
				if(A+B>=k)ans=(ans+(A+B-k+1-max(0ll,B-k+1)-max(0ll,A-k+1))*((fac*f)%Mod))%Mod;
				//if(f)printf("+(%c %d %d %d %d)\n",c+'a',A,B,f,(A+B-k+1-max(0ll,B-k+1)-max(0ll,A-k+1))*((fac*f)%Mod));
			} 
		}
	}
	ans=(ans%Mod+Mod)%Mod;
	printf("%lld\n",ans);
	return 0;
}
