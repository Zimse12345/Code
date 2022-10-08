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
while(qrc<'0'||qrc>'9'){qrc=getchar();if(qrc=='-'){qry=-1,qrc=getchar();break;}}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-'0',qrc=getchar();return qrx*qry;}

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int T,n,a[N];
char s[N],t[N];

int main(){
	T=read();
	while(T--){
		n=read();
		scanf("%s%s",s+1,t+1);
		for(int i=1;i<=n;i++)a[i]=0;
		int ans=0;
		for(int i=1;i<=n;i++)if(t[i]=='1'){
			if(s[i]=='0')++ans;
			else{
				if(i>1&&s[i-1]=='1'&&a[i-1]==0)a[i-1]=1,++ans;
				else if(i<n&&s[i+1]=='1'&&a[i+1]==0)a[i+1]=1,++ans;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

