#include <fstream>
#include <string>
#include <cstring>
#include "Account.h"

using namespace std::string_literals; // This is for easier string literal concatenation

extern std::string BANKING_PATH;

namespace Bnk {



Account::Account(std::string id, long cashAmount) : id(id), cashAmount(cashAmount), accFile(BANKING_PATH + "/accs/" + id, std::ios::out | std::ios::binary) {

    // Throw an exception if failed to open acc file
    if(!this->accFile.is_open()) {
        throw std::runtime_error(("Account file number "s + this->id + " not found"s).c_str());
    }

    // Check whether file is valid by reading its first 4 bytes which should be "\0ACC"
    char magicNum[4]; 
    this->accFile.read(magicNum, sizeof(magicNum));
    if(std::memcmp(magicNum, "\0ACC", 4) != 0) { // Not equal
        this->accFile.close();
        this->accFile.open(BANKING_PATH + "/accs/" + id, std::ios::out | std::ios::binary);
        this->accFile.write("\0ACC", 4);
    }

}



Account::~Account() {

    this->accFile.write(this->accData, sizeof(this->accData)); // Save account's data to file

    this->accFile.close; // Close account file

}



}
