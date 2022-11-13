//
// Created by Usuario on 11/12/2022.
//

#include "User.h"

using namespace std;

User::User(int id, string user_name, string display_name) : userName(user_name), displayName(display_name) {
    this->userId = id;
}

User::~User() {}

string User::getUserName() {
    return this->userName;
}

string User::getDisplayName() {
    return this->displayName;
}

string User::getStatus() {
    return this->status;
}

void User::setUserName(const string name) {
    this->userName = name;
}

void User::setDisplayName(const string name) {
    this->displayName = name;
}

void User::setStatus(const string status) {
    this->status = status;
}