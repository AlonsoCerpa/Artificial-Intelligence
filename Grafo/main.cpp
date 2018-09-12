#include <iostream>
#include <GL/glut.h>

#include "graph.h"
#include "draw_graph.h"

//g++ *.cpp -lGL -lGLU -lglut

extern Graph<float>* graph;
extern int x_window, y_window;
int x_space, y_space;

int main(int argc, char** argv)
{
    x_window = 600;
    y_window = 600;
    x_space = 60;
    y_space = 60;
    int h = x_window / x_space;
    int w = y_window / y_space;
    graph = create_graph_type1<float>(h, w);

    graph->delete_edge(0,0,1,1);
    graph->delete_node(2,7);
    graph->delete_node(5,5);

    int x = 8;
    for (int y = 0; y < h-1; ++y)
    {
        graph->delete_edge(x, y, x, y+1);
    }

//////////////////////////////////////

    std::list<Node<float>*> path1;
    graph->find_path_dfs(0, 0, 3, 3, path1);
    
    std::cout << "Depth first search:\n";
    for (auto it = path1.begin(); it != path1.end(); ++it)
    {
        std::cout << "(" << (*it)->x << ", " << (*it)->y << "); ";
    }
    std::cout << "\n\n";

//////////////////////////////////////////

    std::list<Node<float>*> path2;
    graph->find_path_hill_climb(0, 0, 3, 3, path2);
    
    std::cout << "Hill climbing:\n";
    for (auto it = path2.begin(); it != path2.end(); ++it)
    {
        std::cout << "(" << (*it)->x << ", " << (*it)->y << "); ";
    }
    std::cout << "\n";

////////////////////////////////////////////////

    draw_graph(&argc, argv);

    delete graph;

    return 0;
}