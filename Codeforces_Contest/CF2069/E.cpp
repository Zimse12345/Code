#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,a,b,ab,ba,n,A[N],ta,B[N],tb;
char s[N];

signed main(){
    cin>>T;
    while(T--){
        scanf("%s",s+1);
        n=strlen(s+1);
        cin>>a>>b>>ab>>ba;
        int S=ab+ba;
        for(int i=1;i<=n;i++){
            if(s[i]=='A')--a;
            if(s[i]=='B')--b;
        }
        int sum=0;
        ta=tb=0;
        for(int l=1;l<=n;){
            int r=l;
            while(r<n&&s[r+1]!=s[r])++r;
            int len=r-l+1;
            if(len>1){
                sum+=(len-1)/2;
                if(s[l]!=s[r]){
                    if(s[l]=='A')A[++ta]=len/2;
                    if(s[l]=='B')B[++tb]=len/2;
                }
            }
            l=r+1;
        }
        if(ta){
            sort(A+1,A+ta+1);
            for(int i=1;i<=ta;i++)if(ab>=A[i])ab-=A[i],++sum; 
        }
        if(tb){
            sort(B+1,B+tb+1);
            for(int i=1;i<=tb;i++)if(ba>=B[i])ba-=B[i],++sum; 
        }
        sum=min(sum,S);
        a+=sum,b+=sum;
        if(a>=0&&b>=0)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}


