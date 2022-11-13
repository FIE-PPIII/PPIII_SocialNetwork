#include <iostream>
#include "Graph.h"
#include "Relation.h"
#include "User.h"

using namespace std;

int main()
{
    cout<<"Hello, world!"<<endl;
    Graph<int, User, Relation> network;
    network.addNode(1, User(1, "jnemi", "J.B. Nemi"));
    network.addNode(2, User(2, "equito", "Esteban Quito"));
    network.addNode(3, User(3, "dtrump", "Donald Trump"));
    network.addNode(4, User(4, "bobama", "Barack Obama"));

    network.setEdgeBetween(3, 4, FRIEND);
    network.eraseNode(3);

    return 0;
}
