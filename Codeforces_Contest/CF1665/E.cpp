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

const int N=1e7+7,Mod=998244353,INF=1e9+7;
int T,n,q,a[200000],rt[200000],ch[N][2],s[N],tot;

inline void ins(int id,int _id,int x){
	s[id]=s[_id]+1;
	for(int i=29;i>=0;i--){
		if(x&(1<<i)){
			ch[id][1]=++tot,ch[id][0]=ch[_id][0];
			id=ch[id][1],_id=ch[_id][1];
			s[id]=s[_id]+1;
		}
		else{
			ch[id][0]=++tot,ch[id][1]=ch[_id][1];
			id=ch[id][0],_id=ch[_id][0];
			s[id]=s[_id]+1;
		}
	}
	return;
}

inline void add(int id,int _id,int t,int h){
	s[t]+=s[id]-s[_id];
	for(int i=h;i>=0;i--){
		if(s[ch[id][0]]-s[ch[_id][0]]>0){
			id=ch[id][0],_id=ch[_id][0];
			if(!ch[t][0])ch[t][0]=++tot;
			t=ch[t][0];
		}
		else{
			id=ch[id][1],_id=ch[_id][1];
			if(!ch[t][1])ch[t][1]=++tot;
			t=ch[t][1];
		}
		s[t]+=s[id]-s[_id];
	}
	return;
}

signed main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++){
			a[i]=read(),rt[i]=++tot;
			ins(rt[i],rt[i-1],a[i]);
		}
		q=read();
		for(int i=1,l,r;i<=q;i++){
			l=read(),r=read();
			int id=rt[r],_id=rt[l-1],ans=0,iid=0,_tot=tot;
			for(int j=29;j>=0;j--){
				int v=s[ch[iid][0]]+s[ch[id][0]]-s[ch[_id][0]];
				if(v>1){
					id=ch[id][0],_id=ch[_id][0],iid=ch[iid][0];
				}
				else if(v==1){
					ans|=(1<<j);
					if(!s[ch[iid][0]]){
						if(!iid)iid=++tot;
						if(!ch[iid][1])ch[iid][1]=++tot;
						add(ch[id][0],ch[_id][0],ch[iid][1],j-1);
					}
					else{
						if(!iid)iid=++tot;
						if(!ch[iid][1])ch[iid][1]=++tot;
						add(ch[iid][0],0,ch[iid][1],j-1);
					}
					id=ch[id][1],_id=ch[_id][1],iid=ch[iid][1];
				}
				else{
					ans|=(1<<j);
					id=ch[id][1],_id=ch[_id][1],iid=ch[iid][1];
				}
			}
			printf("%d\n",ans);
			for(int i=_tot+1;i<=tot;i++)ch[i][0]=ch[i][1]=s[i]=0;
			tot=_tot;
		} 
		for(int i=0;i<=tot;i++)ch[i][0]=ch[i][1]=s[i]=0;
		tot=0;
	}
	return 0;
}
