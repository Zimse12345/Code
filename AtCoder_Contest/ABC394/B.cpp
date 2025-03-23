#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
struct str{
    string s;
    bool operator < (const str& _)const{return s.length()<_.s.length();}
}a[N];
int n;

signed main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i].s;
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)cout<<a[i].s;
    return 0;
}


