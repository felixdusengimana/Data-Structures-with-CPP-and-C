#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <sstream>
using namespace std;

std::vector<std::string> string_split(const std::string& str) {
    std::vector<std::string> result;
    std::istringstream iss(str);
    for (std::string s; iss >> s; )
        result.push_back(s);
    return result;
}

string generateAccountNumber(){
    srand((unsigned) time(0));
    int randomNumber = rand()%900+100;
    time_t now = time(0);
    tm *ltm = localtime(&now);
    return to_string(randomNumber)+to_string((1900 + ltm->tm_year))+to_string((1 + ltm->tm_mon));
}

int save_to_file(string type, string fname, string lname, float balance){
    fstream file;
    file.open("database.txt", ios::app);
    if(file){
        if(type.compare("create_account")==0){
            string accountNo = generateAccountNumber();
            string data = accountNo+" "+fname+" "+lname+" "+to_string(balance);
            file<<data<< endl;
            cout<<"\t\tCONGRATULATIONS, "<<lname<<" "<<fname<<endl;
            cout<<"\t\tYOUR ACCOUNT NUMBER IS:: "<<accountNo<<endl;
        }else if(type.compare("deposit")==0){
                // string strTemp;
                // bool found = false;
                // while(file >> strTemp)
                // {
                //     if(strTemp == strReplace){
                //         strTemp = strNew;
                //         found = true;
                //     }
                //     strTemp += "\n";
                //     fileout << strTemp;
                //     if(found) break;
                // }
                // return 0;
        }
        file.close();
        return 1;
    }
    return 0;
}

int read_from_file(string type, string id){
    ifstream file;
    file.open("database.txt", ios::in);
    bool found = false;
    if(file){
        if(type.compare("get_balance")==0){
        string accountData, line;
        vector<string> single_user_data;
        while (getline(file, line))
        {
            single_user_data = string_split(line);
            if(single_user_data[0].compare(id)==0){
             cout<<"\n\t\t************\n\t\tFirst name: "<<single_user_data[1]<<endl;
             cout<<"\t\tLast name: "<<single_user_data[2]<<endl;
             cout<<"\t\tAcount number: "<<single_user_data[0]<<endl;
             cout<<"\t\tBalance: "<<single_user_data[3]<<endl;
             found = true;
             break;
            }
        }
        if(!found){
            cout<<"\n\t\tACCOUNT NOT FOUND!\n";
        }
    }else if (type.compare("get_all_users")==0)
    {
        /* code */
    }
        file.close();
        return 1;
    }
    return 0;
}

int create_account(){
    string fname, lname;
    float initbalance=0.0f;
    cout<<"\n\t\tEnter First Name: ";
    cin>>fname;
    cout<<"\t\tEnter Last  Name: ";
    cin>>lname;
    cout<<"\t\tEnter Initial Balance: ";
    cin>>initbalance;
    cout<<endl;

    int success = save_to_file("create_account",fname, lname,initbalance);
   return success;
}

string get_account_no(){
  string accountNo;
  cout<<"\t\tEnter your account number:: ";
  cin>>accountNo;
  return accountNo;
}

int menu(){
  int choice;
  cout<<"\n\t\t*****MENU*****\n";
  string options[] = {"Open Account", "Balance Enquiry", "Deposit", "Withdrawal", "Close an Account", "Show All Account", "Quit"};
  int len = sizeof(options)/sizeof(options[0]);
  for (int i = 0; i < len; ++i)
  {
      cout<<"\t\t"<<i+1<<". "<<options[i]<<endl;
  }
  
  cout<<"\n\t\tEnter your choice: ";
  cin>>choice;


  return choice;
}

void method_caller(int id){
  do{
    int success;
    string accountNo;
    switch(id){
        case 1:
            success = create_account();
        break;
        case 2:
             accountNo = get_account_no();
             success = read_from_file("get_balance",accountNo);
        case 3:
             accountNo = get_account_no();
             success = save_to_file("deposit", "", "", 100);
        break;
        default:
            cout<<"The choice isn't recorginized, Try again!";
        break;
    }
    id = menu();
  }while(id!=7);
}

int main(int argc, char const *argv[])
{
    cout<<"\n\t\t*******BANK MANAGEMENT SYSTEM.********\n\n";
    int file_open_success = save_to_file("","","",0);
    if(file_open_success){
        int choice = menu();
        method_caller(choice);
    }else{
      cout<<"Unable to open file, unexpected error occured."<<endl;
    }
    return 0;
}