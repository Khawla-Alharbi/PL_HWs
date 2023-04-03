#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define khawla ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main()
{
  khawla
  
  string message= "WKHUH LV QR SODFH OLNH KRPH";
  string hiddenMsg= "";
  int key= 3;

  for (int i = 0; message[i]; i++) {
    if (message[i] == 32) {
      hiddenMsg+=' ';
    }else if (message[i] >= ('A'+3)) {
      hiddenMsg+= char(message[i]-3);
    }else{
      hiddenMsg+= char(message[i]+(26-key));
    }
  }
  cout<<hiddenMsg;
    return 0;
}
