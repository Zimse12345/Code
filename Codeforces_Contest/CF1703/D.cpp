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

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int T,n;
char s[N][16];
int ch[N][26],tot,tag[N],len[N];

signed main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++){
			scanf("%s",s[i]+1),len[i]=strlen(s[i]+1);
			int pos=0;
			for(int j=1;j<=len[i];j++){
				if(!ch[pos][s[i][j]-'a'])ch[pos][s[i][j]-'a']=++tot;
				pos=ch[pos][s[i][j]-'a'];
			}
			tag[pos]=1;
		}
		for(int i=1;i<=n;i++){
			int pos=0,ans=0;
			for(int j=1;j<=len[i];j++){
				if(!ch[pos][s[i][j]-'a'])break;
				pos=ch[pos][s[i][j]-'a'];
//				printf("(%d %d %d)\n",i,j,tag[pos]);
				if(tag[pos]){
					int p=0;
					for(int jj=j+1;jj<=len[i];jj++){
						if(!ch[p][s[i][jj]-'a']){p=0;break;}
						p=ch[p][s[i][jj]-'a'];
					}
					if(tag[p]){
						ans=1;
						break;
					}
				}
			}
			printf("%d",ans);
		}
		printf("\n");
		for(int i=0;i<=tot;i++){
			for(int j=0;j<26;j++)ch[i][j]=0;
			tag[i]=0;
		}
		tot=0;
	}
	return 0;
}

