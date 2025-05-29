#pragma once

namespace Bnk {

class Account {
public:

    void login(char password[8]); // Call this to log into account using specified password

    void withdraw(int amount); // Call this to withdraw specified amount of cash

    void deposit(int amount); // Call this to deposit specified amount of cash

private:

    bool loggedIn; // True = user currently logged into this account

    long cash; // Amount of cash this account has

};

}
