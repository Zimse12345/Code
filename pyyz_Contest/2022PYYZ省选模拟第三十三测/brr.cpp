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
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e6+7,Mod=998244353,INF=1e9+7;
int n,m,f[N],ch[N][26],tot,ans;
char s[N];
struct node{
	int pos,len;
	node(int pos=0,int len=0):pos(pos),len(len){}
};
vector<node> p[N];

void ins(int pos,int len){
	ans=max(ans,len);
	int id=0;
	for(int i=0;i<len;i++){
		if(!ch[id][s[pos+i]-'a'])ch[id][s[pos+i]-'a']=++tot;
		id=ch[id][s[pos+i]-'a'];
	}
	int t=p[id].size()-1;
	while(t>=0&&p[id][t].pos>=pos&&p[id][t].len<=len)p[id].resize(t),--t;
	p[id].push_back(node(pos,len));
	return;
}

signed main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	while((m+1)*(m+2)/2<=n)++m;
	for(int i=1;i*2<=n;i++)swap(s[i],s[n-i+1]);
	for(int i=1;i<=n;i++){
		int id=0,len=0;
		while(1){
			id=ch[id][s[i+len]-'a'];
			if(!id)break;
			for(int j=0;j<signed(p[id].size());j++){
				if(p[id][j].pos+p[id][j].len<=i)ins(i,p[id][j].len+1);
				if(p[id][j].pos+p[id][j].len<=i-1)ins(i-1,p[id][j].len+1);
			}
			++len;if(i+len>n||len>m)break;
		}
		ins(i,1);
	}
	printf("%d\n",ans);
	return 0;
}

