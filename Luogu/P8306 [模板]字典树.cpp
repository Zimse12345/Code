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

const int N=3e6+7,Mod=998244353,INF=1e9+7;

inline int Id(char c){
	if('A'<=c&&c<='Z')return c-'A';
	if('a'<=c&&c<='z')return c-'a'+26;
	if('0'<=c&&c<='9')return c-'0'+52;
	return 0;
}
int ch[N][64],cnt[N],tot;
int T,n,q;
char s[N];

signed main(){
	T=read();
	while(T--){
		n=read(),q=read();
		while(n--){
			scanf("%s",s+1);
			int len=strlen(s+1),pos=0;
			for(int i=1;i<=len;i++){
				s[i]=Id(s[i]);
				if(!ch[pos][s[i]])ch[pos][s[i]]=++tot;
				pos=ch[pos][s[i]];
				++cnt[pos];
			}
		}
		while(q--){
			scanf("%s",s+1);
			int len=strlen(s+1),pos=0;
			for(int i=1;i<=len;i++){
				s[i]=Id(s[i]);
				pos=ch[pos][s[i]];
				if(!pos)break;
			}
			printf("%d\n",cnt[pos]);
		}
		for(int i=0;i<=tot;i++){
			for(int j=0;j<64;j++)ch[i][j]=0;
			cnt[i]=0;
		}
		tot=0;
	}
	return 0;
}

