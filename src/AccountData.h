#pragma once
#include <ctypes>

struct AccountData_t {
    char password[8]; // This account's password (always 8 chars)
    uint64_t cashAmount; // Amount of cash on this account
};

