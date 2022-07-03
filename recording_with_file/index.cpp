#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <sstream>
#include <filesystem>

#define MIN_AMOUNT 10

using namespace std;
using std::filesystem::current_path;

const string DATABASE_FILENAME = "database.txt";
const string DATABASE_TEMP_FILENAME = "temp_database.txt";

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

int update_file(string id, string type, string fname, string lname, float balance){
    fstream file;
    fstream file2;
    
    file.open(DATABASE_FILENAME, ios::in);
    file2.open(DATABASE_TEMP_FILENAME, ios::app);

    string accountData, line;
    bool found = false;
    vector<string> single_user_data;

    if(file && file2){
    file2.flush();
    while (getline(file, line)){
            single_user_data = string_split(line);
          if(single_user_data[0].compare(id)==0){
            if(type.compare("close")!=0){
             float newBalance = (type.compare("deposit")==0) ? stof(single_user_data[3])+balance: stof(single_user_data[3])-balance;
             if(newBalance<MIN_AMOUNT){
              cout<<"\n\t\tYou've to leave at least $"<<MIN_AMOUNT<<" in your account."<<endl;
              cout<<"\n\t\tYour Balance: "<<single_user_data[3]<<endl;
              file.close();
              file2.close();
              remove("temp_database.txt");
              return 0;
             }
             string first_name = (fname.empty()) ?  single_user_data[1]: fname;
             string last_name = (lname.empty()) ?  single_user_data[2]: lname;

             string data = id+" "+first_name+" "+last_name+" "+to_string(newBalance);
             file2<<data<< endl;
             cout<<"\n\t\tAcount number: "<<single_user_data[0]<<endl;
             cout<<"\t\tYour new Balance is: "<<to_string(newBalance)<<endl;
             found = true;
            }else{
              found = true;
            }
          }else{
            file2<<line<<endl;
          }
    }
  }


    file.close();
    file2.close();


    if(!found){
      cout<<"\n\t\tACCOUNT NOT FOUND!\n";
    }else{
        if(remove("database.txt") == 0 && rename("temp_database.txt", "database.txt")==0){
          return 1;
        }
        return 1;
    }

    remove("temp_database.txt");
    return 0;
}

int save_to_file(string type, string fname, string lname, float balance){
    fstream file;
    file.open(DATABASE_FILENAME, ios::app);
    
    if(file){
        if(type.compare("create_account")==0){
            string accountNo = generateAccountNumber();
            string data = accountNo+" "+fname+" "+lname+" "+to_string(balance);
            file<<data<< endl;
            cout<<"\t\tCONGRATULATIONS, "<<lname<<" "<<fname<<endl;
            cout<<"\t\tYOUR ACCOUNT NUMBER IS:: "<<accountNo<<endl;
        }
        file.close();
        return 1;
    }
    return 0;
}

int read_from_file(string type, string id){
    ifstream file;
    file.open(DATABASE_FILENAME, ios::in);
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
             cout<<"\t\tBalance: $"<<single_user_data[3]<<endl;
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
    std::getline(std::cin, fname);
    cout<<"\t\tEnter Last  Name: ";
    cin>>lname;
    new_balance:
    cout<<"\t\tEnter Initial Balance: ";
    cin>>initbalance;
    cout<<endl;
    if(initbalance<MIN_AMOUNT){
        cout<<"\n\t\tThe amount of money to start with is at least $"<<MIN_AMOUNT<<endl;
        goto new_balance;
    }
    int success = save_to_file("create_account",fname, lname,initbalance);
   return success;
}

string get_account_no(){
  string accountNo;
  cout<<"\t\tEnter your account number:: ";
  cin>>accountNo;
  return accountNo;
}

int update_infos(){
    string fname, lname;
    string accountNo = get_account_no();
    cout<<"\n\t\tEnter First Name: ";
    cin>>fname;
    cout<<"\t\tEnter Last  Name: ";
    cin>>lname;
    int success = update_file(accountNo, "update", fname, lname, 0);
    if(success==1){
       cout<<"\n\t\tAccount infomations updated!"<<endl;
       cout<<"\t\tInfomations\n\t\t--------------"<<endl;
       cout<<"\t\tFirst name: "<<fname<<endl;
       cout<<"\t\tLast name: "<<lname<<endl;
    }
    return success;
}

int menu(){
  int choice;
  cout<<"\n\t\t*****MENU*****\n";
  string options[] = {"Open Account", "Balance Enquiry", "Deposit", "Withdrawal", "Close an Account", "Update your infomations", "Quit"};
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
    float amount;
    switch(id){
        case 1:
            success = create_account();
        break;
        case 2:
             accountNo = get_account_no();
             success = read_from_file("get_balance",accountNo);
        break;
        case 3:
             accountNo = get_account_no();
             cout<<"\t\tEnter deposit amount:: ";
             cin>>amount;
             if (amount<=0)
                cout<<"\n We only accept deposit money from $1"<<endl;
             success = update_file(accountNo, "deposit", "", "", amount);
        break;
        case 4:
             accountNo = get_account_no();
             cout<<"\t\tEnter withdraw amount:: ";
             cin>>amount;
             if (amount<=0)
                cout<<"\n We only accept withdraw money from $1"<<endl;
             success = update_file(accountNo, "withdraw", "", "", amount);
        break;
        case 5:
             accountNo = get_account_no();
             success = update_file(accountNo, "close", "", "", 0);
             if(success==1){
              cout<<"\n\t\tBye Bye! Account deleted successfully";
             }
        break;
        case 6:
              success = update_infos();
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