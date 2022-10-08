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

const int N=1e5+7,Mod=998244353,INF=1e9+7;
int T,n,ans;
char s[N]; 

int main(){
	T=read();
	while(T--){
		n=read(),ans=INF;
		scanf("%s",s+1);
		for(char c='a';c<='z';c++){
			int L=1,R=n,k=0;
			while(L<R){
				if(s[L]==s[R])++L,--R;
				else{
					if(s[L]==c)++L,++k;
					else if(s[R]==c)--R,++k;
					else{
						k=INF;
						break;
					}
				}
			}
			ans=min(ans,k);
		}
		if(ans>=INF)ans=-1;
		printf("%d\n",ans);
	}
	return 0;
}
