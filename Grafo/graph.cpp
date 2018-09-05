#include "graph.h"

#include <GL/glut.h>

template<class Dist>
NodePtrDist<Dist>::NodePtrDist()
{
    
}

template<class Dist>
NodePtrDist<Dist>::NodePtrDist(Node<Dist>* _node_ptr, Dist _dist)
{
    dist = _dist;
    node_ptr = _node_ptr;
}

/////////////////////////////////////////////////////////////////

template<class Dist>
Node<Dist>::Node(Dist _x, Dist _y)
{
	x = _x;
	y = _y;
}

/////////////////////////////////////////////////////////////////

template<class Dist>
Graph<Dist>::Graph(std::vector<std::vector<Node<Dist>*> >* _nodes, int _h, int _w)
{
    nodes = _nodes;
    h = _h;
    w = _w;
}

template<class Dist>
Graph<Dist>::~Graph()
{
    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            if ((*nodes)[i][j] != nullptr)
            {
                delete (*nodes)[i][j];
            }
        }
    }
    delete nodes;
}

template<class Dist>
void Graph<Dist>::delete_edge(int i1, int j1, int i2, int j2)
{
	Node<Dist>* n1 = (*nodes)[j1][i1];
	Node<Dist>* n2 = (*nodes)[j2][i2];

	if (n1 != nullptr && n2 != nullptr)
	{
		for (auto it = (n1->neighbors).begin(); it != (n1->neighbors).end(); ++it)
		{
			if ((*it).node_ptr == n2)
			{
				(n1->neighbors).erase(it);
				break;
			}
		}

		for (auto it = (n2->neighbors).begin(); it != (n2->neighbors).end(); ++it)
		{
			if ((*it).node_ptr == n1)
			{
				(n2->neighbors).erase(it);
				break;
			}
		}
	}
}

template<class Dist>
void Graph<Dist>::delete_edge(Node<Dist>* n1, Node<Dist>* n2)
{
	for (auto it = (n1->neighbors).begin(); it != (n1->neighbors).end(); ++it)
	{
		if ((*it).node_ptr == n2)
		{
			(n1->neighbors).erase(it);
			break;
		}
	}

	for (auto it = (n2->neighbors).begin(); it != (n2->neighbors).end(); ++it)
	{
		if ((*it).node_ptr == n1)
		{
			(n2->neighbors).erase(it);
			break;
		}
	}
}

template<class Dist>
void Graph<Dist>::delete_node(int i, int j)
{
	Node<Dist>* n1 = (*nodes)[j][i];
	Node<Dist>* n2;

	if (n1 != nullptr)
	{
		for (auto it = (n1->neighbors).begin(); it != (n1->neighbors).end(); ++it)
		{
			n2 = (*it).node_ptr;
			for (auto it2 = (n2->neighbors).begin(); it2 != (n2->neighbors).end(); ++it2)
			{
				if ((*it2).node_ptr == n1)
				{
					(n2->neighbors).erase(it2);
					break;
				}
			}
		}
		delete (*nodes)[j][i];
		(*nodes)[j][i] = nullptr;		
	}
}

template<class Dist>
void Graph<Dist>::draw()
{
	Node<Dist>* n;
	NodePtrDist<Dist> npd;
	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			n = (*nodes)[i][j];
			if (n != nullptr)
			{
				for (auto it = (n->neighbors).begin(); it != (n->neighbors).end(); ++it)
				{
					npd = *it;
					glBegin(GL_LINES);
					glColor3d(255, 0, 0);
					glVertex2d(n->x, n->y);
					glVertex2d((npd.node_ptr)->x, (npd.node_ptr)->y);
					glEnd();
				}	
			}	
		}
	}

	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			n = (*nodes)[i][j];
			if (n != nullptr)
			{
				glBegin(GL_POINTS);
				glColor3d(255,255,255);
				glVertex2d(n->x, n->y);
				glEnd();
			}
		}
	}
}


template class NodePtrDist<float>;
template class NodePtrDist<double>;
template class Node<float>;
template class Node<double>;
template class Graph<float>;
template class Graph<double>;