#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,d,k,s[N];
vector<int> p[N];

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>d>>k;
        for(int i=1;i<=n;i++)p[i].resize(0),s[i]=0;
        int mx=-1,mn=n+1,sum=0,mxp=0,mnp=0;
        for(int i=1,l,r;i<=k;i++){
            cin>>l>>r;
            p[l].push_back(r);
        }
        for(int i=1;i<d;i++){
            for(unsigned j=0;j<p[i].size();j++){
                ++s[p[i][j]];
                ++sum;
            }
        }
        for(int i=d;i<=n;i++){
            for(unsigned j=0;j<p[i].size();j++){
                ++s[p[i][j]];
                ++sum;
            }
            sum-=s[i-d];
            if(sum>mx)mx=sum,mxp=i-d+1;
            if(sum<mn)mn=sum,mnp=i-d+1;
        }
        printf("%d %d\n",mxp,mnp);
    }
    return 0;
}


