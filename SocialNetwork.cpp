//
// Created by Usuario on 11/13/2022.
//

#include "SocialNetwork.h"

void SocialNetwork::addUser(User user) {
    this->users.insert(pair<int, User>(user.getUserId(), user));
    User* aux = &(this->users.at(user.getUserId()));
    this->usersByUserName.insert(pair<string, User*>(user.getUserName(), aux));
}

User& SocialNetwork::getUser(int key) {
    return this->users.at(key);
}

User& SocialNetwork::getUser(string userName) {
    return *(this->usersByUserName.at(userName));
}

void SocialNetwork::deleteUser(int key) {
    // Removing non-mutual followers
    const map<int, User*> aux = this->users.at(key).getAux();
    for (map<int, User*>::const_iterator it = aux.begin(); it != aux.end(); it++){
        it->second->unfollow(key);
    }
    // Removing mutual followers and following users
    const map<int, User*> aux_following = this->users.at(key).getAux();
    for (map<int, User*>::const_iterator it = aux_following.begin(); it != aux_following.end(); it++){
        it->second->unfollow(key);
    }
    // Removing user from network
    this->usersByUserName.erase(this->users.at(key).getUserName());
    this->users.erase(key);
}

void SocialNetwork::followUser(int follower, int followed) {
    User* followerUser = &(this->users.at(follower));
    User* followedUser = &(this->users.at(followed));
    followerUser->follow(followed, followedUser);
    followedUser->addFollower(follower, followerUser);
}

void SocialNetwork::unfollowUser(int follower, int followed) {
    this->users.at(follower).unfollow(followed);
    this->users.at(followed).removeFollower(follower);
}

void SocialNetwork::setUserStatus(int key, string status) {
    this->users.at(key).setStatus(status);
}

string SocialNetwork::getUserFeed(int key) {
    return this->users.at(key).getFeed();
}