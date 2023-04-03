#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define khawla ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main()
{
  khawla

string s ="Umm Al-Qura University (UQU) is a public university in Mecca,Saudi Arabia. "
"The university was established as the College"
"of Sharia in (1949) before being joined by new colleges and "
"renamed as Umm Al-Qura by royal decree in (1981).";

bool open= false;
string subString = "";
for (int i = 0; s[i]; i++) {
  if (s[i]== 40) {
    open= true;
    continue;
  }
  if (s[i]==41) {
    open = false;
    cout<<subString<<'\t';
    subString="";
  }
  if (open) {
    subString+=s[i];
  }
}
    return 0;
}
