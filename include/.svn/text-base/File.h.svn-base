#ifndef FILE_H
#define FILE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Node.h"
class File{
    private:
    FILE *f;
    int *result;
    int result_size;
   public:
    File();
    virtual ~File();
    bool file_open(const char *path,const char *mode);
    bool file_close();
    bool file_write(Node *node);
    bool file_read();
    int* get_result();
    int get_result_size();
    void process_line(char *line);
    char*  strcopy( const char *src,int start,int end);
};
#endif // FILE_H_INCLUDED
