#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,a[N]; 

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        sort(a+1,a+n+1);
        a[0]=-1;
        int s=0;
        for(int l=1;l<=n;){
            int r=l;
            while(r<n&&a[r+1]==a[r])++r;
            if(r-l+1>=4){
                s=2;
                break;
            }
            if(r-l+1>=2){
                if(s==1&&a[l]==a[l-1]+1){
                    s=2;
                    break;
                }
                s=1;
            }
            else{
                if(a[l]>a[l-1]+1)s=0;
            }
            l=r+1;
        }
        if(s==2)printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}


