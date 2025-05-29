#pragma once

namespace Bnk {

class Account {
public:

    Account(char id[8], long cashAmount); // Constructor, assigns values and opens account file

    ~Account(); // Closes account file, frees resources

    void login(char password[8]); // Call this to log into account using specified password

    void withdraw(int amount); // Call this to withdraw specified amount of cash

    void deposit(int amount); // Call this to deposit specified amount of cash

    long getCash(); // Returns this.cashAmount

    const char id[8]; // This account's unique ID. Assigned in constructor

private:

    bool loggedIn; // True = user currently logged into this account

    long cashAmount; // Amount of cash this account has

};

}
