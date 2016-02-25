#include "../include/Search.h"

Search::Search(char *input ,char *output_1 ,char *output_2)
{
    this->in_path = new char[strlen(input)];
    this->out_one_path = new char[strlen(output_1)];
    this->out_two_path = new char[strlen(output_2)];
    strcpy(this->in_path,input);
    strcpy(this->out_one_path,output_1);
    strcpy(this->out_two_path,output_2);
    //printf("\n INPUT PATH : %s",this->in_path);
    //printf("\n OUTPUT ONE PATH : %s",this->out_one_path);
    //printf("\n OUTPUT TWO PATH : %s",this->out_two_path);
    File in;
    in.file_open(this->in_path,"rt");

    in.file_read();
    int len = in.get_result_size();
    int *res = new int[len+1];
    //printf("\nLen:%d",len);
    res = in.get_result();
    in.file_close();
    //res is array input from input file
    //begin point
    this->begin[0] = res[0];
    this->begin[1] = res[1];
    //end point
    this->goal[0] = res[2];
    this->goal[1] = res[3];
    //size of graph;
    this->size = res[4];
    //printf("\nSIZE:%d\n",this->size);
    this->graph = new int*[this->size];
    int j,i;
    for(i = 0 ;i < this->size ;i++){
            this->graph[i] = new int[this->size];
    }

    for( i = 0 ;i < this->size ;i++){
        for( j = 0;j < this->size ;j++){
            this->graph[i][j] = res[5 + ((i*this->size) + j)];
        }
    }
    /*for(i = 0 ;i < this->size ;i++){
        for(j = 0;j < this->size ;j++){
            printf("%d,",this->graph[i][j]);
        }
        printf("\n");
    }*/
    this->flag = new bool*[this->size];
    for(i = 0 ;i < this->size ;i++){
        this->flag[i] = new bool[this->size];
    }
    //matrix flag
    for(i = 0 ;i < this->size ;i++){
            for(j = 0;j < this->size ;j++){
                this->flag[i][j] = false;
            }
    }
    delete res;
}

Search::~Search()
{
    delete this->in_path;
    delete this->out_one_path;
    delete this->out_two_path;
    int i;
    for(i = 0 ;i < this->size ;i++){
            delete []this->graph[i];
    }
    delete this->graph;
    for(i = 0 ;i < this->size ;i++){
            delete []this->flag[i];
    }
    delete this->flag;

}
void Search::BFS(){
        File out;
        out.file_open(this->out_one_path,"a+");
        Queue Q;
        int x,y,value;
        x = begin[0];
        y = begin[1];
        value = this->graph[x][y];
        //insert start point to queue
        Q.insert(x,y,value);
        this->flag[x][y] = true;
        Node *tmp = new Node();
        while(!Q.isempty()){
            tmp = Q.remove();
            out.file_write(tmp);
            x = tmp->get_X();
            y = tmp->get_Y();
            //found goal
            if(x == goal[0] && y == goal[1]){
                out.file_close();
                break;
            }
            //left
            if( (y-1 >= 0) && (this->graph[x][y-1] == 1) && (this->flag[x][y-1] == false) ){
                Q.insert(x,y-1,this->graph[x][y-1]);
                this->flag[x][y-1] = true ;
            }
            //right
            if( (y+1 < this->size) && (this->graph[x][y+1] == 1) && (this->flag[x][y+1] == false) ){
                Q.insert(x,y+1,this->graph[x][y+1]);
                this->flag[x][y+1] = true ;
            }
            //up

            if( (x-1 >= 0) && (this->graph[x-1][y] == 1) && (this->flag[x-1][y] == false) ){
                Q.insert(x-1,y,this->graph[x-1][y]);
                this->flag[x-1][y] = true ;
            }
            //down
            if( (x+1 < this->size)  && (this->graph[x+1][y] == 1) && (this->flag[x+1][y] == false) ){
                Q.insert(x+1,y,this->graph[x+1][y]);
                this->flag[x+1][y] = true ;
            }


        }
        delete tmp;

}
void Search::DFS(){
    File out;
    out.file_open(this->out_two_path,"a+");
    Stack S;
    int x,y,value;
    x = begin[0];
    y = begin[1];
    value = this->graph[x][y];
//insert start point to queue
    S.insert(x,y,value);
    this->flag[x][y] = true;
    Node *tmp = new Node();
    while(!S.isempty()){
        tmp = S.remove();
        out.file_write(tmp);
        x = tmp->get_X();
        y = tmp->get_Y();
    //found goal
        if(x == goal[0] && y == goal[1]){
            out.file_close();
            break;
        }
    //left
        if( (y-1 >= 0) && (this->graph[x][y-1] == 1) && (this->flag[x][y-1] == false) ){
            S.insert(x,y-1,this->graph[x][y-1]);
            this->flag[x][y-1] = true ;
        }
    //rigth
        if( (y + 1 < this->size) && (this->graph[x][y+1] == 1) && (this->flag[x][y+1] == false) ){
            S.insert(x,y+1,this->graph[x][y+1]);
            this->flag[x][y+1] = true ;
        }
    //up
        if(((x-1) >= 0) && (this->graph[x-1][y] == 1) && (this->flag[x-1][y] == false) ){
            S.insert(x-1,y,this->graph[x-1][y]);
            this->flag[x-1][y] = true ;
        }
    //down
        if(((x + 1) < this->size)  && (this->graph[x + 1][y] == 1) && (this->flag[x + 1][y] == false) ){
            S.insert(x +1,y,this->graph[x + 1][y]);
            this->flag[x + 1][y] = true ;
        }

    }
    delete tmp;

}


