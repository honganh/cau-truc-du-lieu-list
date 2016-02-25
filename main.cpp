/*
@package:cautrucdulieu
@subpackage:DFS-BFS algorithm
@author :honganh
@contact:pndhainam@hotmail.com
*/

#include "include/Search.h"
#include "include/Queue.h"

int main(int argc ,char **argv)
{
   if(argc < 4){
        printf("\n Error input .");
        printf("\n Input follow : <program name> <path_file_input> <path_file_output1> <path_file_output2>");
        return -1;
    }else{
        char *input = argv[1];
        char *output_1 = argv[2];
        char *output_2 = argv[3];
        Search *search = new Search(input,output_1,output_2);
        search->DFS();

        search = new Search(input,output_1,output_2);
        search->BFS();
    }

    return 0;
}
