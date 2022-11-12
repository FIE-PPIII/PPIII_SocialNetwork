//
// Created by Usuario on 11/12/2022.
//

#ifndef BASE_CPP_NODE_H
#define BASE_CPP_NODE_H

#include <map>

using namespace std;

template <typename Key, typename Type, typename Link>
class Node {
private:
    Type content;
    map<Key, Link> edges;

public:
    Node() {}
    Node(Type);
    ~Node();

    Type& getContent();
    const map<Key, Link> & getEdges();
    bool hasEdgeWith(Key);
    Link getEdgeWith(Key);
    void setEdgeWith(Key, Link);
    void eraseEdgeWith(Key);
};

template<typename Key, typename Type, typename Link>
Node<Key, Type, Link>::Node(Type value) {
    this->content = value;
}

template<typename Key, typename Type, typename Link>
Node<Key, Type, Link>::~Node() {

}

template<typename Key, typename Type, typename Link>
Type &Node<Key, Type, Link>::getContent() {
    return this->content;
}

template<typename Key, typename Type, typename Link>
const map<Key, Link> &Node<Key, Type, Link>::getEdges() {
    return this->edges;
}

template<typename Key, typename Type, typename Link>
bool Node<Key, Type, Link>::hasEdgeWith(Key k) {
    return (this->edges.find(k) != this->edges.end());
}

template<typename Key, typename Type, typename Link>
Link Node<Key, Type, Link>::getEdgeWith(Key k) {
    return this->edges.at(k);
}

template<typename Key, typename Type, typename Link>
void Node<Key, Type, Link>::setEdgeWith(Key k, Link l) {
    this->edges[k] = l;
}

template<typename Key, typename Type, typename Link>
void Node<Key, Type, Link>::eraseEdgeWith(Key k) {
    this->edges.erase(k);
}


#endif //BASE_CPP_NODE_H
