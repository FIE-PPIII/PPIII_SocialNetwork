//
// Created by Usuario on 11/12/2022.
//

#ifndef BASE_CPP_GRAPH_H
#define BASE_CPP_GRAPH_H

#include "Node.h"

using namespace std;

template <typename Key, typename Type, typename Link>
class Graph {
private:
    map<Key, Node<Key, Type, Link>> container;

public:
    Graph() {}
    ~Graph() {}

    void addNode(Key, Type);
    Type& contentAt(Key);
    const map<Key, Link>& getEdgesAt(Key);
    bool hasEdgeBetween(Key, Key);
    Link getEdgeBetween(Key, Key);
    void setEdgeBetween(Key, Key, Link);
    void eraseEdgeBetween(Key, Key);
    void eraseNode(Key);

};

template<typename Key, typename Type, typename Link>
void Graph<Key, Type, Link>::addNode(Key key, Type value) {
    if (this->container.find(key) == this->container.end())
        this->container[key] = value;
}

template<typename Key, typename Type, typename Link>
Type &Graph<Key, Type, Link>::contentAt(Key key) {
    return this->container.at(key).getContent();
}

template<typename Key, typename Type, typename Link>
const map<Key, Link> &Graph<Key, Type, Link>::getEdgesAt(Key key) {
    return this->container.at(key).getEdges();
}

template<typename Key, typename Type, typename Link>
bool Graph<Key, Type, Link>::hasEdgeBetween(Key key1, Key key2) {
    return this->container.at(key1).hasEdgeWith(key2);
}

template<typename Key, typename Type, typename Link>
Link Graph<Key, Type, Link>::getEdgeBetween(Key key1, Key key2) {
    return this->container.at(key1).getEdgeWith(key2);
}

template<typename Key, typename Type, typename Link>
void Graph<Key, Type, Link>::setEdgeBetween(Key key1, Key key2, Link l) {
    this->container.at(key1).setEdgeWith(key2, l);
    this->container.at(key2).setEdgeWith(key1, l);
}

template<typename Key, typename Type, typename Link>
void Graph<Key, Type, Link>::eraseEdgeBetween(Key key1, Key key2) {
    this->container.at(key1).eraseEdgeWith(key2);
    this->container.at(key2).eraseEdgeWith(key1);
}

template<typename Key, typename Type, typename Link>
void Graph<Key, Type, Link>::eraseNode(Key key) {
    Node<Key, Type, Link> aux = this->container.at(key);
    for (typename map<Key, Link>::const_iterator it = aux.getEdges().begin(); it != aux.getEdges().end(); it++) {
        this->eraseEdgeBetween(key, it->second);
    }
    this->container.erase(key);
}


#endif //BASE_CPP_GRAPH_H
