//
// Created by Usuario on 11/13/2022.
//

#include "User.h"

User::User(int userId, string user_name, string display_name) : userName(user_name), displayName(display_name) {
    this->userId = userId;
}

string User::getUserName() {
    return this->userName;
}

string User::getDisplayName() {
    return this->displayName;
}

string User::getStatus() {
    return this->status;
}

const map<int, User*>& User::getFollowing() {
    return this->following;
}

const map<int, User*>& User::getAux() {
    return this->aux;
}

void User::setDisplayName(string name) {
    this->displayName = name;
}

void User::setStatus(string status) {
    this->status = status;
}

void User::follow(int key, User * user_following) {
    if (this->aux.find(key) != this->aux.end()) {  // The third user is following this user
        this->aux.erase(key);
    }
    this->following.insert(pair<int, User*>(key, user_following));
}

void User::unfollow(int key) {
    if (this->following.find(key) != this->following.end()) {  // If this user is following third user
        User* user_following = this->following.at(key);
        if (user_following->following.find(this->userId) != user_following->following.end()) {  // If third user is following this user
            this->aux.insert(pair<int, User*>(key, user_following));
        }
        this->following.erase(key);
    }
}

void User::addFollower(int key, User * follower) {
    if (this->following.find(key) == this->following.end()) {  // If this user is NOT following third user
        this->aux.insert(pair<int, User*>(key, follower));
    }
}

void User::removeFollower(int key) {
    if (this->aux.find(key) != this->aux.end()) {  // If this user is NOT following third user
        this->aux.erase(key);
    }
}

string User::getFeed() {
    string feed = "This is your feed, " + this->displayName + ":";
    for (map<int, User*>::iterator it = this->following.begin(); it != this->following.end(); it++) {
        feed = feed + "\n" + (it->second->displayName) + ": " + (it->second->getStatus());
    }
    return feed;
}