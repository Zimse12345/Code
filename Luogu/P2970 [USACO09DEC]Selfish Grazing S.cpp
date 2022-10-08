#include <iostream>
#include <algorithm>
using namespace std;

struct p{
    int a,b;
    p(int a=0,int b=0):a(a),b(b){}
    bool operator <(const p& A){
        return b<A.b;
    }
}s[1000005];

int n;

int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>s[i].a>>s[i].b;
    sort(s+1,s+n+1);
    int t=-1e9-7,ans=0;
    for(int i=1;i<=n;i++){
        if(s[i].a>=t)t=s[i].b,++ans;
    }cout<<ans;
}
