#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define khawla ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main()
{
  khawla

  string message= "HAVIREFVGL";
  int key= 1;
  while (key<26) {
  string hiddenMsg= "";
  for (int i = 0; message[i]; i++) {
    if (message[i] == 32) {
      hiddenMsg+=' ';
    }else if (message[i] >= ('A'+key)) {
      hiddenMsg+= char(message[i]-key);
    }else{
      hiddenMsg+= char(message[i]+(26-key));
    }
  }
    cout<<" Key: "<<key<<" message: "<<hiddenMsg<<endl;
    key++;
  }
    return 0;
}
