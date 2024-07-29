#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int T,n,x;

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>x;
        int ans=0;
        for(int a=1;a<x&&a<n;a++){
            for(int bc=2;a+bc<=x&&a*bc<n;bc++){
                int m=n-a*bc;
                int l=1,r=bc/2,res=0;
                while(l<=r){
                    int mid=(l+r)/2;
                    if(mid*(bc-mid)<=m)res=mid,l=mid+1;
                    else r=mid-1;
                }
                ans+=res*2;
                if(bc%2==0&&res==bc/2)--ans;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}


