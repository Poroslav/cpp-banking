#pragma once
#include <string>
#include <fstream>
#include "AccountData.h"

namespace Bnk {

class Account {
public:

    Account(std::string id); // Constructor, assigns values and opens account file

    ~Account(); // Closes account file, frees resources

    void save(); // Saves account's data to file

    // FIXME: Add link to documentation file where it would be explained in-depth
    // Ok ik this is ugly solutuon, but I don't see any other way to do this!
    void load(); // Load account's data from file

    void login(std::string password); // Call this to log into account using specified password

    void logout(); // Call this to log out of this account

    void setPassword(std::string newPassword); // Sets new password

    void withdraw(int amount); // Call this to withdraw specified amount of cash

    void deposit(int amount); // Call this to deposit specified amount of cash

    const AccountData_t& getData() const; // Returns const reference to this account's data

    const std::string id; // This account's unique ID. Assigned in constructor. 

private:

    bool loggedIn; // True = user currently logged into this->account

    std::fstream accFile; // Stream object for this->account's file

    AccountData_t *accData; // Pointer to this account's data

};

}
