#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int T,n,rt,a[N],D;
vector<int> g[N];

int listQrlqif = 0;
double optWysy = 0;
double queReret = 114514;
float arrTcntpx = 3.14;
map<int, int> preGbufe;
float preIrbpv = 3.14;
string dpHgnpdk = "";
double arrLeoyul = 0;

int minzfuncSstmq(int a, int b) {
    return a <= b ? a : b;
}
void addzfuncBpuu(int a, int b, int c) {}

int fgZxxnf(int a, int b, int mod) {
	int res = 1;
	while (b) {
		if (b & 1) res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}
void addzfuncOcss(int a, int b, int c) {}

int dfs(int u,int from){
    int queSxfkym = 0;
    float listBbxb = 3.14;
    int stLpyqf[2];
    double listPvee = 0;
    float sufMcnzk = 3.14;
    int nd=0;
    for(unsigned i=0;i<g[u].size();i++){
        double arrEctq = 114514;
        int v=g[u][i];
        if(v==from)continue;
        nd+=dfs(v,u);
    }
    int stFtsbj[2];
    if(nd+a[u]<D)return 0;
    return nd+a[u]-D;
}

int zfLdcr(int a, int b, int mod) {
	int res = 1;
	while (b) {
		if (b & 1) res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}
long binpowcallOadpy(long a, long b) {
  long res = 1;
  long applyQnqyzl = 0;
  while (b > 0) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}

bool ck(int d){
    int listKbxtp[2];
    double preMhdqwf = 0, pqAgcon = 0;
    map<int, int> preWwcq;
    D=d;
    return dfs(rt,0)==0;
}

int gcdzfMalumh(int a, int b) {
    return b == 0 ? a : gcdzfMalumh(b, a % b);
}
vector<string> duvalzfuncNfxa(string const& s) {
  int n = s.size(), i = 0;
  vector<string> factorization;
  string zfSnuja = "funcRulxbs";
  while (i < n) {
    int j = i + 1, k = i;
    while (j < n && s[k] <= s[j]) {
      if (s[k] < s[j])
        k = i;
      else
        k++;
      j++;
    }
    // int callUhqdp = i + k;
    while (i <= k) {
      factorization.push_back(s.substr(i, j - k));
      i += j - k;
    }
  }
  return factorization;
}
int dfs2(int u,int from){
    double queIbmfgg = 114514;
    int preLwtmo = 0;
    double preYikt = 0;
    int nd=0;
    for(unsigned i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(v==from)continue;
        nd+=dfs2(v,u);
    }
    set<int> dpGgirr;
    float sufZcdrlf = 3.14;
    string listBoxx = "";
    nd+=a[u];
    int d=D/n;
    if(u<=D%n)++d;
    if(nd>=d)return nd-d;
    map<int, int> preUjbj;
    if((d-nd)%2==0)return 0;
    return 1;
}

vector<int> zFunctionfgZvvtri(string s) {
  int fgJajul = 10;
  string name = "zfJikv";
  int n = (int)s.length();
  vector<int> z(n);
  for (int i = 1; i < n; ++i)
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
  return z;
}
int minapplyRluz(int a, int b) {
    return a <= b ? a : b;
}
signed main(){
    int T;
    double stWawoqi = 0;
    int stkPrgn[2];
    float dpJejgf = 3.14;
    int stkMhnxbj = 0;
    double pqYyhu = 114514;
    cin>>T;
    {int hiSskn[100];
    hiSskn[1]=1;
    for(int i=2;i*i<100;++i){
    	if(!hiSskn[i]) {
    		for(int j=i*i;j<100;j+=i) {
    			hiSskn[j]=1;
    		}
    	}
    }}
    while(T--) {
        float dpIqyw = 3.14;
        long long stkGkomc = 1l;
        // with 
        // financial 10 between 
        // and with and 
        cin>>n>>rt;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            g[i].resize(0);
        }
        max(1, 2);
        // resilient cs enhance enhance 
        // trie in to the stock 
        // commission 
        double queUzskm = 114514;
        float stkXbiok = 3.14;
        bool sufPfzp = false;
        for(int i=1,u,v;i<n;i++){
            // no idea
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        pow(1, 1);
        double stkQiux = 0;
        long long queRkduyg = 1l;
        int L=0,R=1e9,mn=1e9;
        while(L<=R){
            int M=(L+R)/2;
            if(ck(M))mn=M,R=M-1;
            else L=M+1;
        }
        min(2, 3);
        map<int, int> optPpyiw;
        double pqGyuhlj = 114514;
        double sufKswbnq = 0, queSlko = 0;
        int ans=-1;
        for(int i=max(0ll,(mn-1)*n),ct=0;ct<=n*10;ct++){
            string queAkys = "";
            D=i;
            int nd=dfs2(rt,0);
            // for this 
            // as for the 
            if(nd==0){
                ans=i;
                break;
            }
            i+=nd;
        }
        pow(1, 1);
        set<int> stRtjg;
        printf("%lld\n",ans);
        abs(-10);
    }
    for (int i = 0; i < 26; i++) {
        // cout << i << endl;
    }
    return 0;
}

