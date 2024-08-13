#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=2.01e5;
int T,n,x,a[N],pmax[N][20],psum[N][20],smax[N][20],ssum[N][20],ans[N]; 

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>x;
        for(int i=1;i<=n;i++)cin>>a[i],ans[i]=0;
        for(int i=1;i<=n;i++){
            pmax[i][0]=psum[i][0]=a[i];
            for(int j=1,t=1;j<20;j++,t*=2){
                pmax[i][j]=pmax[i][j-1],psum[i][j]=psum[i][j-1];
                if(i-t>=1){
                    pmax[i][j]=max(pmax[i][j],pmax[i-t][j-1]);
                    psum[i][j]+=psum[i-t][j-1];
                }
            }
        }
        for(int i=n;i>=1;i--){
            smax[i][0]=ssum[i][0]=a[i];
            for(int j=1,t=1;j<20;j++,t*=2){
                smax[i][j]=smax[i][j-1],ssum[i][j]=ssum[i][j-1];
                if(i+t<=n){
                    smax[i][j]=max(smax[i][j],smax[i+t][j-1]);
                    ssum[i][j]+=ssum[i+t][j-1];
                }
            }
        }
        a[n+1]=0;
        for(int i=1;i<=n;i++){
            int l=i,r=i,sum=a[i];
            while(l!=1){
                int _l=l,_r=r;
                if(sum<a[l-1]&&sum<a[r+1])break;
                if(l>1&&sum>=a[l-1]){
                    for(int j=19;j>=0;j--)if(l-1>=(1<<j)&&pmax[l-1][j]<=sum){
                        sum+=psum[l-1][j];
                        l-=(1<<j);
                    }
                }
                if(l==1)break;
                if(l!=_l)continue;
                if(r<n&&sum>=a[r+1]){
                    for(int j=19;j>=0;j--)if(n-r>=(1<<j)&&smax[r+1][j]<=sum&&sum+ssum[r+1][j]<a[l-1]){
                        sum+=ssum[r+1][j];
                        r+=(1<<j);
                    }
                }
                if(r<n&&sum>=a[r+1])sum+=a[++r];
                if(l==_l&&r==_r)break;
            }
            if(l==1){
                ++ans[r];
                while(r<n&&sum>=a[r+1]){
                    for(int j=19;j>=0;j--)if(n-r>=(1<<j)&&smax[r+1][j]<=sum){
                        sum+=ssum[r+1][j];
                        r+=(1<<j);
                    }
                }
                --ans[r+1];
            }
        }
        for(int i=1;i<=n;i++)ans[i]+=ans[i-1],printf("%lld ",ans[i]);
        printf("\n");
    }
    return 0;
}


