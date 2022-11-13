//
// Created by Usuario on 11/13/2022.
//

#ifndef PPIII_SOCIALNETWORK_SOCIALNETWORK_H
#define PPIII_SOCIALNETWORK_SOCIALNETWORK_H

#include <map>
#include "User.h"

using namespace std;

class SocialNetwork {
private:
    map<int, User> users;
    map<string, User*> usersByUserName;

public:
    SocialNetwork() {}
    ~SocialNetwork() {}

    void addUser(User);
    User& getUser(int);
    User& getUser(string);
    void deleteUser(int);
    void followUser(int follower, int followed);
    void unfollowUser(int follower, int followed);
    void setUserStatus(int, string);
    string getUserFeed(int);
};


#endif //PPIII_SOCIALNETWORK_SOCIALNETWORK_H
