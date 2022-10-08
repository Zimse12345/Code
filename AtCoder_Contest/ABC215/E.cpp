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

int read(){int qrx=0,qry=1;char qrc=' ';
while(qrc<'0'||qrc>'9'){qrc=getchar();if(qrc=='-'){qry=-1,qrc=getchar();break;}}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-'0',qrc=getchar();return qrx*qry;}

const int N=1507,Mod=998244353,INF=1e9+7;
int n,f[N][20][2],a[N],now,ans;
char s[N];

int main(){
	n=read(),scanf("%s",s+1);
	for(int i=1;i<=n;i++)a[i]=s[i]-'A';
	int tot=(1<<10)-1;
	
	f[1<<a[1]][a[1]][0]=1;
	for(int i=2;i<=n;i++){
		now^=1;
		for(int j=0;j<=tot;j++)for(int k=0;k<10;k++)f[j][k][now]=f[j][k][now^1];
		f[1<<a[i]][a[i]][now]+=1; 
		
		for(int j=0;j<=tot;j++){
			if(j&(1<<a[i]))f[j][a[i]][now]=(f[j][a[i]][now]+f[j][a[i]][now^1])%Mod;
			else for(int k=0;k<10;k++)f[j|(1<<a[i])][a[i]][now]=(f[j|(1<<a[i])][a[i]][now]+f[j][k][now^1])%Mod;
		}
	}
	for(int i=0;i<=tot;i++)for(int j=0;j<10;j++)ans=(ans+f[i][j][now])%Mod;
	printf("%d\n",ans);
	return 0;
}
