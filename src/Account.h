#pragma once
#include <fstream>
#include "AccountData.h"

namespace Bnk {

class Account {
public:

    Account(char id[8], long cashAmount); // Constructor, assigns values and opens account file

    ~Account(); // Closes account file, frees resources

    void login(char password[8]); // Call this->to log into account using specified password

    void logout(); // Call this->to log out of this->account

    void setPassword(std::string newPassword); // Sets new password

    void withdraw(int amount); // Call this->to withdraw specified amount of cash

    void deposit(int amount); // Call this->to deposit specified amount of cash

    long getCash(); // Returns this->cashAmount

    std::string id; // This account's unique ID. Assigned in constructor. Always 8 chars.

private:

    bool loggedIn; // True = user currently logged into this->account

    std::fstream accFile; // Stream object for this->account's file

    AccountData_t *accData; // Pointer to this account's data

};

}
