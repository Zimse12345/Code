#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n;
char s[N];

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        scanf("%s",s+1);
        int sum=0;
        long long ans=0;
        for(int i=1;i<n;i+=2){
            if(sum<=0)s[i]='(',++sum;
            else s[i]=')',--sum,ans+=sum*2+1;
            if(s[i+1]==')')--sum,ans+=sum*2+1;
            else ++sum;
        }
        printf("%lld\n",ans);
    }
    return 0;
}


