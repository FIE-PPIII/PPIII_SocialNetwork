#include <iostream>
#include "Graph.h"

using namespace std;

int main()
{
    cout<<"Hello, world!"<<endl;
    Graph<int, float, bool> network;
    network.addNode(1, 1.0);
    network.addNode(2, 2.0);
    network.addNode(3, 3.0);
    network.addNode(4, 4.0);

    network.setEdgeBetween(3, 4, true);
    network.eraseNode(3);

    return 0;
}
