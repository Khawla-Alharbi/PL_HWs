#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define khawla ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
string Decryption(string message, int key){
  string hiddenMsg= "";
  for (int i = 0; message[i]; i++) {
    if (message[i] == 32) {
      hiddenMsg+=' ';
    }else if (message[i] >= ('a'+key)) {
      hiddenMsg+= char(message[i]-key);
    }else{
      hiddenMsg+= char(message[i]+(26-key));
    }
  }
  return hiddenMsg;
}
int main()
{
  khawla
  int freq[26]={0};
  int cnt=0;
  string message= "cxknxawxccxkncqjcrbcqnljcrwcqnqjcqxvnrbfqnancqnqnjacrb";

  for (int i = 0; message[i]; i++) {
    if (freq[message[i]-'a']==0) {
      cnt++;
    }
    freq[message[i]-'a']++;
  }


   multimap<int, char,greater<int>> freqmap;

  for (int i = 0; i < 26; i++) {
    if (freq[i] > 0) {
      freqmap.emplace(freq[i],char(i+'a'));
    }
  }

  int i=1;
  cout<<"*************** Frequency table ***************\n\n";
  for (auto it = freqmap.begin(); it != freqmap.end() ; it++) {
    cout<<i<<"- "<< it->second<<": "<< it->first<<" -> ";
    int letterCount=it->first;
    for (int i = 0; i < letterCount; i++) {
      cout<<"*";
    }
    i++;
    cout<<'\n';
  }
  cout<<"\n-------------------------------- \n";
  cout<<"convert most frequence letters to 'e': \n\n";
  auto it = freqmap.begin();
  for (int i = 0; i < cnt/2; i++) {
    int tkey= abs(it->second - 'e');
    cout<<"convert "<< it->second <<" to e "<<" key: "<<tkey<<"  -> ";
    cout<<Decryption(message,tkey)<<'\n';
    it++;
  }




    return 0;
}
