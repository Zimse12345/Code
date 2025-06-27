#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int T,n,ans[N];
char s[N]; 

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        scanf("%s",s+1);
        int sum=0,c=0;
        for(int i=1,x=0;i<=n;i++){
            if(s[i]=='P')++x;
            else sum+=x;
        }
        for(int i=1;i<=n;){
            int j=i;
            while(j<n&&s[j+1]==s[i])++j;
            if((j-i+1)&1){
                if(s[i]=='P'){
                    if(c&1)--c;
                    else ++c;
                }
                else{
                    if(c&1)++c;
                    else c=max(0ll,c-1);
                }
            }
            i=j+1;
        }
        c/=2;
        c=(c+1)/2;
        c+=(sum-c+1)/2;
        printf("%lld\n",c);
    }
    return 0;
}


