//
// Created by Usuario on 11/12/2022.
//

#ifndef BASE_CPP_USER_H
#define BASE_CPP_USER_H

#include <string>

using namespace std;

class User {
private:
    int userId;
    string userName;
    string displayName;
    string status;
public:
    User() {}
    User(int, string, string);
    ~User();

    int getUserId();
    string getUserName();
    string getDisplayName();
    string getStatus();

    void setUserName(const string);
    void setDisplayName(const string);
    void setStatus(const string);
};

inline int User::getUserId() {
    return this->userId;
}


#endif //BASE_CPP_USER_H
