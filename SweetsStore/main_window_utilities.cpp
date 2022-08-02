#include "main_window_utilities.h"

#include <iostream>

#include "utilities.h"

bool checkPassowrd(std::string password) {
    if(!password.length() or password.length() < 8) { return false; }

    return true;
}

bool checkCredentials(std::string email, std::string password) {
    if(!checkEmail(email, "@gmail.com") or !checkPassowrd(password)) { return false; }

    return true;
}
