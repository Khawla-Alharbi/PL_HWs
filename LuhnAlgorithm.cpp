#include <bits/stdc++.h>
using namespace std;
#define ll long long int
//#define khawla ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int checkSum(string card){
  int checksum=0;
  for (int i = 0; i < card.size(); i+=2) {
    int temp = (card[i]-'0')*2;
    if(temp>9){
      int x= temp/10;
      int y= temp%10;
      card[i]= (x+y)+'0';
    }else{
      card[i]= temp+'0';
    }
  }
  for (int i = 0; i < card.size(); i++) {
    checksum+= card[i]-'0';
  }
  return checksum;
}
int main()
{

  //khawla


  string card;

  ifstream MyReader("credit.txt");

  int i =1;
  while (getline (MyReader, card)) {
   if (i==1) {
     cout<<"#"<<"  "<<"Credit Card #"<<"      "<<"Type "<<"     "<<"Checksum"<<"  "<<"Valid?"<<'\n';
     cout<<"--------------------------------------------------"<<'\n';
   }
  string valid="NO";
  string type="Visa";
  int sum= checkSum(card);
  if (sum%10 == 0) {
    valid= "YES";
  }
  if (card[0]=='5') {
    type="MasterCard";
    cout<<i<<"  "<<card<<"   "<<type<<"  "<<sum<<"        "<<valid<<'\n';
  }else{
    cout<<i<<"  "<<card<<"   "<<type<<"        "<<sum<<"        "<<valid<<'\n';
  }



  i++;

  }


  MyReader.close();

    return 0;
}
