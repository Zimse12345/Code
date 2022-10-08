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

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int SZ=350,Id[N],cnt,Bl[N],Br[N];
int n,m,A[N],presum[N],ans[N],ql[N],qr[N];

struct query{
	int l,r,id;
	query(int l=0,int r=0,int id=0):l(l),r(r),id(id){}
	bool operator < (const query& _)const{return r<_.r;}
};
vector<query> q[2];

struct val{
	int a,b;
	val(int a=0,int b=0):a(a),b(b){}
}a[N];

inline int bf(int l,int r){
	priority_queue<int> Q;
	int sum=0;
	for(int j=l;j<=r;j++){
		if(!Q.empty()&&-Q.top()<min(a[j].a,a[j].b))sum+=-Q.top(),Q.pop(),Q.push(-a[j].a),Q.push(-a[j].b);
		else sum+=min(a[j].a,a[j].b),Q.push(-max(a[j].a,a[j].b));
	}
	return sum;
}

void sol(int t){
	int _n=0;
	for(int i=(t?2:3);i<=n;i+=2)a[++_n]=val(A[i-1],A[i]);
	for(unsigned i=0;i<q[t].size();i++){
		int l=q[t][i].l,r=q[t][i].r;
		if(t)l=(l+1)/2,r=r/2;
		else l=l/2,r=r/2;
		q[t][i]=query(l,r,q[t][i].id);
	}
	
	cnt=0;
	for(int l=1,r;l<=_n;){
		r=min(_n,l+SZ-1);
		++cnt,Bl[cnt]=l,Br[cnt]=r;
		for(int i=l;i<=r;i++)Id[i]=cnt;
		l=r+1;
	}
	vector<query> qu[1024];
	for(unsigned i=0;i<q[t].size();i++){
		int l=q[t][i].l,r=q[t][i].r,id=q[t][i].id;
		qu[Id[l]].emplace_back(l,r,id);
	}
	for(int i=1;i<=cnt;i++){
		sort(qu[i].begin(),qu[i].end());
		unsigned I=0;
		while(I<qu[i].size()&&Id[qu[i][I].r]==i)ans[qu[i][I].id]=bf(qu[i][I].l,qu[i][I].r),++I;
		int R=Br[i],sum=0;
		priority_queue<int> Q;
		priority_queue<int> v;
		while(I<qu[i].size()){
			int l=qu[i][I].l,r=qu[i][I].r,id=qu[i][I].id;
			++I;
			while(R<r){
				++R;
//				printf("[%lld %lld]\n",a[R].a,a[R].b);
				if(!Q.empty()&&-Q.top()<min(a[R].a,a[R].b)){
					sum+=-Q.top();//printf("+(%lld)!\n",-Q.top());
					v.push(-Q.top()),Q.pop();
					Q.push(-a[R].a),Q.push(-a[R].b);
				}
				else{
					sum+=min(a[R].a,a[R].b);
					v.push(min(a[R].a,a[R].b));//printf("+(%lld)\n",min(a[R].a,a[R].b));
					Q.push(-max(a[R].a,a[R].b));
				}
			}
			priority_queue<int> _Q;
			int lsum=0;
			for(int j=l;j<=Br[i];j++){
				if(!_Q.empty()&&-_Q.top()<min(a[j].a,a[j].b)){
					lsum+=-_Q.top(),_Q.pop();
					_Q.push(-a[j].a),_Q.push(-a[j].b);
				}
				else{
					lsum+=min(a[j].a,a[j].b);
					_Q.push(-max(a[j].a,a[j].b));//printf("a[%lld] %lld %lld\n",j,a[j].a,a[j].b);
				}
			}
			int res=sum+lsum;
			vector<int> _v;
			while(!_Q.empty()&&!v.empty()&&-_Q.top()<v.top()){//printf("(%lld %lld %lld %lld %lld)\n",l,r,id,-_Q.top(),v.top());
				res=res-v.top()+(-_Q.top());
				_v.push_back(v.top());
				v.pop(),_Q.pop();
			}
			for(unsigned j=0;j<_v.size();j++)v.push(_v[j]);
			ans[id]=res;
		}
	}
	return;
}

signed main(){
//	freopen("ex_game4.in","r",stdin);
//	freopen("game.out","w",stdout);
	
	n=read(),m=read();
	for(int i=1;i<=n;i++)A[i]=read(),presum[i]=presum[i-1]+A[i];
	for(int i=1,l,r;i<=m;i++){
		l=read(),r=read();
		ql[i]=l,qr[i]=r;
		if(l==r)continue;
		if((r-l+1)&1)--r;
		q[l&1].emplace_back(l,r,i);
	}
	sol(0),sol(1);
	for(int i=1;i<=m;i++)printf("%lld\n",presum[qr[i]]-presum[ql[i]-1]-ans[i]);
	return 0;
}

