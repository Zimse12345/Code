#include <bits/stdc++.h>
#include "silent.h"

using namespace std;

ofstream score("score.txt");

template <typename T>
inline void check(const T &condition, const std::string &message){
  if(!condition){
    cerr << message << flush << endl;
    score << -1 << flush << endl;
    exit(0);
  }
  return;
}

namespace GLOBAL{
int n, q, r;
string sta, ans[105];
}
using namespace GLOBAL;

string query(vector<int> p){
	++q; check(q <= 100, "Too many queries.");
	check(p.size() == n, "Length of p incorrect.");
	vector<bool> used(n, 0);
	for(int i = 0; i < n; ++i){
		--p[i]; check(p[i] >= -1 && p[i] < n, "Index not in range.");
		if(p[i] >= 0){
			check(!used[p[i]] && p[i] != i, "Given query not a staggered permutation.");
			used[p[i]] = true;
		}
	}
	string result; result.resize(n);
	for(int i = 0; i < n; ++i)
		if(p[i] >= 0)
	    	result[i] = ans[i][p[i]];
		else
			result[i] = '-';
	return result;
}

void answer(string a){
	check(r == 0, "Answered Twice!"); ++r;
	check(a.size() == n, "Answer too short or too long.");
	if(a != sta){
	  cerr << "Wrong answer: expected answer " << sta << " got " << a << endl;
	  score << 0 << endl;
	  exit(0);
	}
	cerr << "Answer correct, with " << q << " queries" << endl;
	return;
}



int main(){
  ifstream inf("silent.in");
  int T; string tp; inf >> T >> tp;
  double scr = 100;
  for(; T--; ){
    inf >> n;
    q = 0, r = 0;
    inf >> sta;
    for(int i = 0; i < n; ++i) inf >> ans[i];
    solve(n, tp[0]);
    if(r != 1) scr = 0;
    scr = min(scr, 100 * pow(0.9, (q - 10) / 5));
  }
  
  cerr << "All batches correct!" << flush << endl;
  score << scr << flush << endl;
  return 0;
}

