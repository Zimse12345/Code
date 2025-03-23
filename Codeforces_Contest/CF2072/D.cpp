#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,a[N];

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        int ansl=1,ansr=1,ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1,s=0;j<=n;j++){
                if(a[i]>a[j])++s;
                if(a[i]<a[j])--s;
                if(s>ans)ans=s,ansl=i,ansr=j;
            }
        }
        printf("%d %d\n",ansl,ansr);
    }
    return 0;
}


