#include <bits/stdc++.h>
using namespace std;
#define ll long long int
//#define khawla ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int mySize(string s){
  int cnt=0;
  for (int i=0; s[i]; i++) {
    cnt++;
  }
  return cnt;
}
bool isLower(char c){
  if (c<97) {
    return false;
  }else{
    return true;
  }
}
string camelOrPascal(string s, bool camel){
  string n= "";
  bool foundSpace= false;
  int sizeString= mySize(s);
  int i = 0;
  if (!camel) {
    if (isLower(s[i])) {
      s[0]= s[0] -32;

    }
    n+= s[0];
    i=1;
  }
  for ( ; i < sizeString; i++) {

    if(s[i]==' '){
      foundSpace=true;
      continue;
    }

    if(!isLower(s[i])&& !foundSpace){
      s[i]= s[i] +32;
    }


  if (foundSpace) {
    if (isLower(s[i])) {
      s[i]= s[i] -32;
    }
    foundSpace= !foundSpace;
  }
    n+=s[i];

}
return n;
}
string snakeOrtrain(string s, bool snake){
  string n= "";
  int sizeString= mySize(s);
  int i = 0;

  for ( ; i < sizeString; i++) {

    if(s[i]==' '){
       if (snake) {
        s[i]= '_';
       }else{
        s[i]= '-';
       }
   }else if(!isLower(s[i])){
      s[i]= s[i] +32;}

    n+=s[i];
}
  return n;
}
int main()
{
 // khawla
  string s; getline(cin,s);
  cout<<"------------------------------"<<'\n';
  cout<<"Camel Case:  "<<camelOrPascal(s,true)<<'\n';  //Camel Case
  cout<<"Pascal Case: "<<camelOrPascal(s,false)<<'\n'; //Pascal Case
  cout<<"Snake Case:  "<<snakeOrtrain(s,true)<<'\n';   //snake_case
  cout<<"Train Case:  "<<snakeOrtrain(s,false)<<'\n';  //train-case
    return 0;
}
