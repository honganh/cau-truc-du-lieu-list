#ifndef SEARCH_H
#define SEARCH_H
#include "File.h"
#include "Queue.h"
#include "Stack.h"
#include <string.h>
class Search
{
    public:
        Search(char *input ,char *output_1 ,char *output_2);
        virtual ~Search();
        void BFS();
        void DFS();
    private:
        //path of input file
        char *in_path;
        //path output bfs file
        char *out_one_path;
        //path output dfs file
        char *out_two_path;
        //matrix
        int **graph;
        //matrix sign visisted
        bool **flag;
        //start point
        int begin[2];
        //end point
        int goal[2];
        //size of matrix
        int size;
        //File in;
        //File out;
};

#endif // SEARCH_H
