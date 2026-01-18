#include<bits/stdc++.h>
using namespace std;

/*
  generate hashvalue for password
*/
string hashvalue(string s)
{
  hash <string> hashval;
  size_t val = hashval(s);
  return to_string(val);
}

int main()
{
  int choice;

  srand(time(0));  // generate unique value each time

  unordered_map <string,string> mp; // map username with hashvalue

  while(true)
  {
    cout << "-------------------------------------------------------" << endl;
    cout << "                    INSTAGRAM LOGIN PAGE               " << endl;
    cout << "--------------------------------------------------------"<< endl;
    cout << "1. SIGN UP" << endl; 
    cout << "2. LOGIN" << endl;
    cout << "3. FORGOT PASSWORD" << endl;
    cout << "4. EXIT" << endl;
    cout << "\n-- >Enter Your choice: " << " ";
    cin >> choice;
    
    // SIGN UP
    if(choice == 1)
    {
      string username;
      string password;

      cout << "\n- >Enter Username: " << endl;
      cin >> username;

      if(mp.find(username) != mp.end())
      {
        cout << "-- >Username already used" << endl;
        continue;
      }

      cout << "- >Enter Password: " << endl;
      cin >> password;

      string val = hashvalue(password);
      cout << "\n- >Generated Hashval: " << val << endl;
      mp[username] = val; 
      cout << endl;
    }

    // LOGIN
    else if(choice == 2)
    {
      string username;
      string password;

      cout << "\n- >Enter Username: " << endl;
      cin >> username;

      if(mp.find(username) == mp.end())
      {
        cout << "-- >User doesn't exist" << endl;
        continue;
      }

      cout << "- >Enter Password: " << endl;
      cin >> password;

      string val = hashvalue(password);
      cout << "\n- >Generated Hashval: " << val << endl;

      if(val == mp[username])
      {
        cout << "\n ---- Login Successfully ----" << endl;
      }
      else
      {
        cout << "\n -- > Incorrect username or password" << endl;
      }
      cout << endl;
    }

    // FORGOT PASSWORD
    else if(choice == 3)
    {
      int input;
      int otp = 100+rand()%900;

      cout << "\n-- >Gnerated OTP: " << otp << endl;

      while(true)
      {
        cout << "\n- >Enter OTP: " << " ";
        cin >> input;

        if(otp == input)
        {
          string username;
          string password;

          cout << "\n- >Enter Username: " << endl;
          cin >> username;

          if(mp.find(username) == mp.end())
          {
            cout << "User doesn't exist" << endl;
            continue;
          }

          cout << "- >Enter new Password: " << endl;
          cin >> password;

          string val = hashvalue(password);
          mp[username] = val;

          cout << "\n- >Generated Hashval: " << val << endl;
          break;
        }
        else
        {
          cout << "- >Incorrect otp" << endl;
          cout << "- >Pls enter your otp again" << endl;
        }
      }
    }

    // END
    else
    {
      cout << "-------------------------------------------------------" << endl;
      cout << "                       ---- END ----                   " << endl;
      cout << "--------------------------------------------------------"<< endl;
        break;
    }
  }

    return 0;
}