#include <iostream>
#include "SocialNetwork.h"

using namespace std;

int main()
{
    SocialNetwork network = SocialNetwork();
    network.addUser(User(1, "jnemi", "J.B. Nemi"));
    network.addUser(User(2, "dtrump", "Donald Trump"));
    network.addUser(User(3, "bobama", "Barack Obama"));
    network.followUser(1, 2);
    network.followUser(1, 3);
    network.followUser(2, 3);
    network.followUser(3, 2);
    network.getUser("dtrump").setStatus("Vote Red!");
    network.getUser("bobama").setStatus("Vote Blue!");

    cout<<network.getUser("jnemi").getFeed()<<endl<<endl;
    cout<<network.getUser("dtrump").getFeed()<<endl<<endl;
    cout<<network.getUser("bobama").getFeed()<<endl<<endl;

    return 0;
}
