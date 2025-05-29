#pragma once
#include <map>

namespace Bnk {

class Account; // Forward declaration to shut up compiler

class Bank {
public:

    Bank(); // Opens bank file

    ~Bank(); // Closes bank file, frees resources

    void openAcc(); // Opens new bank's account

private:

    std::map<char[8], Account*> accounts; // Map that stores all accounts of this bank

    std::map<std::string, int> properties; // Bank's properties (such as max amount of cash)

};

}
