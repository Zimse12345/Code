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
char s[N],ans[N],t[N];
int len,anslen=INF;

void update(int i){
	int w=0;
	for(int j=0;j<9;j++)if(i&(1<<j))w+=j+1;
	if(w>anslen)return;
	if(w<anslen){
		w=0;
		for(int j=0;j<9;j++)if(i&(1<<j)){
			for(int k=0;k<=j;k++)ans[++w]='0'+j+1;
		}
		anslen=w;
		return;
	}
	int tag=0;
	w=0;
	for(int j=0;j<9;j++)if(i&(1<<j)){
		for(int k=0;k<=j;k++)t[++w]='0'+j+1;
	}
	for(int i=1;i<=w;i++){
		if(t[i]<ans[i]){tag=1;break;}
		if(t[i]>ans[i])break;
	}
	if(tag)for(int i=1;i<=w;i++)ans[i]=t[i];
	return;
}

void upt(){
	int tag=0;
	for(int i=1;i<=len;i++){
		if(t[i]<ans[i]){tag=1;break;}
		if(t[i]>ans[i])break;
	}
	if(anslen>len)anslen=len,tag=1;
	if(tag)for(int i=1;i<=len;i++)ans[i]=t[i];
	return;
}

signed main(){
	scanf("%s",s+1);
	len=strlen(s+1);
	for(int i=0;i<(1<<9);i++){
		int w=0;
		for(int j=0;j<9;j++)if(i&(1<<j))w+=j+1;
		if(w>len)update(i);
		if(w==len){
			int cnt[10];
			for(int j=1;j<=len;j++){
				for(int k=0;k<9;k++){
					if(i&(1<<k))cnt[k+1]=k+1;
					else cnt[k+1]=0;
				}
				int tag=1;
				for(int k=1;k<j;k++){
					if(!cnt[s[k]-'0']){tag=0;break;}
					--cnt[s[k]-'0'];
					t[k]=s[k];
				}
				if(!tag)break;
				tag=0;
				for(int k=s[j]-'0'+1;k<=9;k++)if(cnt[k]){tag=k,--cnt[k];break;}
				if(!tag)continue;
				t[j]=tag+'0';
				int cur=j;
				for(int k=1;k<=9;k++)while(cnt[k])--cnt[k],t[++cur]=k+'0';
				upt();
			}
		}
	}
	for(int i=1;i<=anslen;i++)printf("%c",ans[i]);
	printf("\n");
	return 0;
}

