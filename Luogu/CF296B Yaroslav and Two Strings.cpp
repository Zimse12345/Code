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

const int N=1e5+7,Mod=1e9+7,INF=1e9+7;
int n,f[N][2][2];
char s[N],t[N]; 
inline void add(int& x,int y){(x+=y)%=Mod;return;}
inline void update(int i){
	if(s[i]<t[i])add(f[i][0][1],f[i-1][0][0]+f[i-1][0][1]),add(f[i][1][1],f[i-1][1][0]+f[i-1][1][1]); 
	else if(s[i]>t[i])add(f[i][1][0],f[i-1][0][0]+f[i-1][1][0]),add(f[i][1][1],f[i-1][0][1]+f[i-1][1][1]);
	else add(f[i][0][0],f[i-1][0][0]),add(f[i][0][1],f[i-1][0][1]),add(f[i][1][0],f[i-1][1][0]),add(f[i][1][1],f[i-1][1][1]);
	return;
}

signed main(){
	n=read();
	scanf("%s %s",s+1,t+1);
	f[0][0][0]=1;
	for(int i=1;i<=n;i++){
		if(s[i]!='?'&&t[i]!='?')update(i);
		if(s[i]=='?'&&t[i]!='?')for(char a='0';a<='9';a++)s[i]=a,update(i);
		if(s[i]!='?'&&t[i]=='?')for(char a='0';a<='9';a++)t[i]=a,update(i);
		if(s[i]=='?'&&t[i]=='?')for(char a='0';a<='9';a++)for(char b='0';b<='9';b++)s[i]=a,t[i]=b,update(i);
	}
	printf("%lld\n",f[n][1][1]);
	return 0;
}

