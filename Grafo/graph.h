#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <list>
#include <cmath>


extern int x_space, y_space;


template<class Dist>
class Node;

template<class Dist>
class NodePtrDist
{
public:
    NodePtrDist();
    NodePtrDist(Node<Dist>* _node_ptr, Dist _dist);

    Dist dist;
    Node<Dist>* node_ptr;
};

template<class Dist>
class Node
{
public:
    Node(Dist _x, Dist _y);

    Dist x, y;
    std::list<NodePtrDist<Dist> > neighbors;
};

template<class Dist>
class Graph
{
public:
    Graph(std::vector<std::vector<Node<Dist>*> >* _nodes, int _h, int _w);
    ~Graph();
    void draw();
    void delete_edge(int i1, int j1, int i2, int j2);
    void delete_edge(Node<Dist>* n1, Node<Dist>* n2);
    void delete_node(int i, int j);
private:
    int h, w;
    std::vector<std::vector<Node<Dist>*> >* nodes;
};

template<class Dist>
Dist get_euc_dist(Node<Dist>* n1, Node<Dist>* n2)
{
    return std::sqrt(std::pow(n2->x - n1->x, 2) + std::pow(n2->y - n1->y, 2));
}

template<class Dist>
Graph<Dist>* create_graph_type1(int h, int w)
{
    std::vector<std::vector<Node<Dist>*> >* nodes = new std::vector<std::vector<Node<Dist>*> >(h, std::vector<Node<Dist>*>(w, nullptr));

    Dist x = 0;
    Dist y = 0;
    for (int i = 0; i < h; ++i)
    {
        x = 0;
        for (int j = 0; j < w; ++j)
        {
            (*nodes)[i][j] = new Node<Dist>(x, y);
            x += x_space;
        }
        y += y_space;
    }

    NodePtrDist<Dist> npd;
    Dist dist;
    int a, b;
    
    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            a = -1;
            b = -1;
            if (i+a >= 0 && i+a < h && j+b >= 0 && j+b < w)
            {
                dist = get_euc_dist((*nodes)[i][j], (*nodes)[i+a][j+b]);
                npd = NodePtrDist<Dist>((*nodes)[i+a][j+b], dist);
                ((*nodes)[i][j]->neighbors).push_back(npd);
            }

            a = -1;
            b = 0;
            if (i+a >= 0 && i+a < h && j+b >= 0 && j+b < w)
            {
                dist = get_euc_dist((*nodes)[i][j], (*nodes)[i+a][j+b]);
                npd = NodePtrDist<Dist>((*nodes)[i+a][j+b], dist);
                ((*nodes)[i][j]->neighbors).push_back(npd);
            }

            a = -1;
            b = 1;
            if (i+a >= 0 && i+a < h && j+b >= 0 && j+b < w)
            {
                dist = get_euc_dist((*nodes)[i][j], (*nodes)[i+a][j+b]);
                npd = NodePtrDist<Dist>((*nodes)[i+a][j+b], dist);
                ((*nodes)[i][j]->neighbors).push_back(npd);
            }

            a = 0;
            b = -1;
            if (i+a >= 0 && i+a < h && j+b >= 0 && j+b < w)
            {
                dist = get_euc_dist((*nodes)[i][j], (*nodes)[i+a][j+b]);
                npd = NodePtrDist<Dist>((*nodes)[i+a][j+b], dist);
                ((*nodes)[i][j]->neighbors).push_back(npd);
            }

            a = 0;
            b = 1;
            if (i+a >= 0 && i+a < h && j+b >= 0 && j+b < w)
            {
                dist = get_euc_dist((*nodes)[i][j], (*nodes)[i+a][j+b]);
                npd = NodePtrDist<Dist>((*nodes)[i+a][j+b], dist);
                ((*nodes)[i][j]->neighbors).push_back(npd);
            }

            a = 1;
            b = -1;
            if (i+a >= 0 && i+a < h && j+b >= 0 && j+b < w)
            {
                dist = get_euc_dist((*nodes)[i][j], (*nodes)[i+a][j+b]);
                npd = NodePtrDist<Dist>((*nodes)[i+a][j+b], dist);
                ((*nodes)[i][j]->neighbors).push_back(npd);
            }

            a = 1;
            b = 0;
            if (i+a >= 0 && i+a < h && j+b >= 0 && j+b < w)
            {
                dist = get_euc_dist((*nodes)[i][j], (*nodes)[i+a][j+b]);
                npd = NodePtrDist<Dist>((*nodes)[i+a][j+b], dist);
                ((*nodes)[i][j]->neighbors).push_back(npd);
            }

            a = 1;
            b = 1;
            if (i+a >= 0 && i+a < h && j+b >= 0 && j+b < w)
            {
                dist = get_euc_dist((*nodes)[i][j], (*nodes)[i+a][j+b]);
                npd = NodePtrDist<Dist>((*nodes)[i+a][j+b], dist);
                ((*nodes)[i][j]->neighbors).push_back(npd);
            }           
        } 
    }

    Graph<Dist>* g = new Graph<Dist>(nodes, h, w);
    return g;
}

#endif