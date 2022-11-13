//
// Created by Usuario on 11/13/2022.
//

#ifndef BASE_CPP_USER_H
#define BASE_CPP_USER_H

#include <map>
#include <string>

using namespace std;

class User {
private:
    int userId;
    string userName;
    string displayName;
    string status;
    map<int, User*> following;
    map<int, User*> aux;

public:
    User(int userId, string user_name, string display_name);
    virtual ~User() {}

    int getUserId();
    string getUserName();
    string getDisplayName();
    string getStatus();
    const map<int, User*>& getFollowing();
    const map<int, User*>& getAux();
    void setDisplayName(string);
    void setStatus(string);
    void follow(int, User*);
    void unfollow(int);
    void addFollower(int, User*);
    void removeFollower(int);
    string getFeed();
};

inline int User::getUserId() {
    return this->userId;
}


#endif //BASE_CPP_USER_H
