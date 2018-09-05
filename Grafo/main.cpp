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
    
    draw_graph(&argc, argv);

    delete graph;

    return 0;
}