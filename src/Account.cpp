#include <fstream>
#include <string>
#include "Account.h"

using namespace std::string_literals; // This is for easier string literal concatenation

extern std::string BANKING_PATH;

namespace Bnk {



Account::Account(std::string id, long cashAmount) : id(id), cashAmount(cashAmount), accFile(BANKING_PATH + "/accs/"s + id, std::ios::in | std::ios::out | std::ios::binary) {
    // Throw an exception if failed to open acc file
    if(!this->accFile.is_open()) {
        throw std::runtime_error(("Account file number "s + this->id + " not found"s).c_str());
    }
}



Account::~Account() {
    this->save(); // Save account's data file
    
    delete this->accData; // Delete account's data (it is saved to a file now)

    this->accFile.close(); // Close account file. Optional, but I think this is a good practice.
}



void Account::save() {
    this->accFile.seekp(0); // Place writing head at the beginning of the file

    // Write account's data to file
    this->accFile.write(reinterpret_cast<char*>(this->accData), sizeof(this->accData));
}



void Account::load() {
    this->accFile.seekg(0); // Place reading head at the beginning of the file

    // Read file's data into account's data
    this->accFile.read(reinterpret_cast<char*>(this->accData), sizeof(this->accData));
}



void Account::login(std::string password) {
    if(password == this->accData.password) { // Check password correctness (vulnerable, ik)
        this->loggedIn = true;
    } else {
        throw std::runtime_error(("Wrong password for account"s + this->id).c_str());
    }
}



void Account::logout() {
    this->loggedIn = false;
}



void Account::setPassword(std::string newPassword) {
    if(!this->loggedIn) { // Error if not logged in
        throw runtime_error(("Login needed to change password, account"s + this->id).c_str());
    }
    this->accData.password = newPassword.c_str(); // Update account's password
}



void Account::withdraw(int amount) {
    if(!this->loggedIn) { // Error if not logged in
        throw runtime_error(("Login needed to withdraw, account"s + this->id).c_str());
    }
    
}




}
