#include<bits/stdc++.h>

using namespace std;

#define ll long long
const int N=65536,NN=256,inf=1e9+100;

ll n,b[16];

ll f[N];
ll m;
ll g[N];
ll dp[2][2][NN][NN]; 
ll ans=inf;

inline int funca(int x){
    if(x < 0) return -x;
    return x;
}

int mimi(int x,int y,int z){
    int mi1 = min(x,y);
    return min(mi1, z);
}

inline ll calc(ll x){
    return x*(x-1)/2;
}

ll solve(ll para1){
	ll qiuhe0=0;
    ll qiuhe1=0;
	for(ll i=0;i<n;i++){
        if((para1>>i)&1){
            qiuhe1+=1;
            qiuhe0+=__builtin_popcount(para1&b[i]);
        }
    }

	qiuhe0>>=1;
	qiuhe1=calc(qiuhe1);

    return mimi(qiuhe0 , funca(qiuhe0-qiuhe1) ,funca(qiuhe0-qiuhe1-1));
}
ll cauc(ll s,ll S){
    ll res = 0;
    int flag = 255;
    int erwul = 256;
	res += dp[0][0][s&flag][S&flag];
    res += dp[0][1][s&flag][S/erwul];
    res += dp[1][0][s/erwul][S&flag];
    res += dp[1][1][s/erwul][S/erwul];
	return res;
}


void solve(){
    cin>>n>>m;
	ans=min(m,n*(n-1)/2-m);
    int ls1 = 0 ,ls2 = 0;
	for(ll i=1;i<=m;i++){
		int p1,p2;cin>>p1>>p2;
        ls1=p1-1;ls2=p2-1;
		b[ls1] = b[ls1] | (1<<ls2);
		b[ls2] = b[ls2] | (1<<ls1);
	}
		
	for(ll f2 = 0 ;f2 <= 1;f2 ++){
        for(ll f1 = 0; f1 <= 1;f1++){
            for(ll i=0;i<256;i++){
                for(ll j=0;j<256;j++){
                    ll s=i,S=j;
                    if(f2)S *= 256;
                    if(f1)s *= 256;
                    for(ll x=0;x<n;x++)if(((s>>x)&1)){
                        for(ll y=0;y<n;y++)if((S>>y)&1){
                            if(!((b[x]>>y)&1))++dp[f1][f2][i][j];
                        }
                    }
                }
            }
        }
    }
    
    ll M=(1<<n);
	for(ll s = 1; s < M ;s ++){
        g[s]=solve(s);
    }

	f[0]=0;
	for(ll s=1;s<M;s++){
		f[s]=g[s];
		for(ll ssp=s-1;ssp;ssp=(ssp-1)&s){
            if(g[ssp]+f[s^ssp]+cauc(ssp,s^ssp) < f[s]){
                f[s] = cauc(ssp,s^ssp);
                f[s] += g[ssp]+f[s^ssp];
            }
        }
	}
	ans=min(ans,f[M-1]);
    cout<<ans<<endl;

}
signed main(){
    cin.tie(0);cout.tie(0);
    ios::sync_with_stdio(0);
    solve();
}
