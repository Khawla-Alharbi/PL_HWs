
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define khawla ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
string bankname (string bb){
  int BankNumber= stoi(bb);
  string name;

  switch (BankNumber) {
    case 05: name = "Al Inma Bank                 "; break;
    case 10: name = "Saudi National Bank (SNB)    "; break;
    case 15: name = "Al Bilad Bank                "; break;
    case 20: name = "Riyad Bank                   "; break;
    case 30: name = "Arab National Bank (ANB)     "; break;
    case 45: name = "Saudi British Bank (SABB)    "; break;
    case 55: name = "Banque Saudi Fransi"; break;
    case 60: name = "Bank Al Jazira                "; break;
    case 65: name = "Saudi Investment Bank (SAIB) "; break;
    case 73: name = "First Abu Dhabi Bank (FAB)    "; break;
    case 80: name = "Al Rajhi Bank                "; break;
    case 90: name = "Gulf International Bank (GiB)"; break;
    case 95: name = "Emirates NBD               "; break;

  }
  return name;
}
string validation(string card){
  string valid="NO";
  int first=(int) card[0] - 55;
  int second=(int) card[1] - 55;
  string newSub= to_string(first)+to_string(second);
  string bank= card.substr(2,2);
  card= card.substr(4)+ newSub +bank;
  //bankname(bank);
  int div1= stoi(card.substr(0,9))%97;
  string StrDiv2= to_string(div1)+card.substr(9,7);
  int div2= stoi(StrDiv2)%97;
  string StrDiv3= to_string(div2)+card.substr(16,7);
  int div3= stoi(StrDiv3)%97;
  string StrDiv4= to_string(div3)+card.substr(23,4);
  int div4= stoi(StrDiv4)%97;
  if (div4==1) {
    valid="YES";
  }
  return valid;

}
int main()
{

khawla

string card;
cout<<"----------------------------------------------------------------------------"<<'\n';
cout<<"IBAN"<<"                        "<<"BANK_CODE"<<"   "<<"BANK_NAME"<<"                    "<<"VALID?"<<'\n';
cout<<"----------------------------------------------------------------------------"<<'\n';
ifstream MyReader("IBAN.txt");
while (getline (MyReader, card)) {
string BankCode=card.substr(4,2);
cout<<card<<"    "<<BankCode<<"          "<<bankname(BankCode)<<""<<validation(card)<<'\n';


}
  MyReader.close();
return 0;
}
