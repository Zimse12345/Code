#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6,K=512;
struct query{
	int l,r,id;
	query(int l=0,int r=0,int id=0):l(l),r(r),id(id){}
	bool operator < (const query& A)const{
		if(l/K==A.l/K)return r<A.r;
		return l<A.l;
	}
}q[N];
int T,n,m,a[N],t[N],cnt,ans[N];

void add(int x){
    if(t[x]%2==0)++cnt;
    else --cnt;
	t[x]++;
	return;
}

void del(int x){
    if(t[x]%2==0)++cnt;
    else --cnt;
	t[x]--;
	return;
}

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>m;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1,l,r;i<=m;i++)cin>>l>>r,q[i]=query(l,r,i);
        sort(q+1,q+m+1);
    	for(int i=1,l,r,L=1,R=0;i<=m;i++){
    		l=q[i].l,r=q[i].r;
    		while(R<r)add(a[++R]);
    		while(L>l)add(a[--L]);
    		while(R>r)del(a[R--]);
    		while(L<l)del(a[L++]);
    		ans[q[i].id]=cnt;
    	}
    	for(int i=1;i<=m;i++){
    	    if(ans[i])printf("NO\n");
    	    else printf("YES\n");
        }
        for(int i=1;i<=n;i++)t[a[i]]=0;
        cnt=0;
    }
	return 0;
}
