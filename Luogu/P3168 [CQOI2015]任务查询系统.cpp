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
#define M ((L+R)>>1)
#define Lid ch[id][0]
#define Rid ch[id][1]

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e5+7,Mod=998244353,INF=1e9+7;
int m,n,rt[N];
int sum[N*64],cnt[N*64],ch[N*64][2],tot;
vector<int> s[N];

int update(int L,int R,int id,int x){
	int _id=++tot;
	if(L==R)sum[_id]=sum[id]+x,cnt[_id]=cnt[id]+(x<0?-1:1);
	else{
		if(abs(x)<=M)ch[_id][0]=update(L,M,Lid,x),ch[_id][1]=Rid;
		else ch[_id][1]=update(M+1,R,Rid,x),ch[_id][0]=Lid;
		sum[_id]=sum[ch[_id][0]]+sum[ch[_id][1]],cnt[_id]=cnt[ch[_id][0]]+cnt[ch[_id][1]];
	}
	return _id;
}

int query(int L,int R,int id,int k){
	if(L==R)return min(k*L,sum[id]);
	if(cnt[id]<=k)return sum[id];
	if(cnt[Lid]<=k)return sum[Lid]+query(M+1,R,Rid,k-cnt[Lid]);
	return query(L,M,Lid,k);
}

signed main(){
	m=read(),n=read();
	for(int i=1,l,r,p;i<=m;i++)l=read(),r=read(),p=read(),s[l].push_back(p),s[r+1].push_back(-p);
	for(int i=1;i<=n;i++){
		rt[i]=rt[i-1];
		for(unsigned j=0;j<s[i].size();j++){
			rt[i]=update(1,1e7,rt[i],s[i][j]);
		}
	}
	for(int i=1,x,a,b,c,ans=1;i<=n;i++){
		x=read(),a=read(),b=read(),c=read();
		int k=1+(a*ans+b)%c;
		ans=query(1,1e7,rt[x],k);
		printf("%lld\n",ans);
	}
	return 0;
}

