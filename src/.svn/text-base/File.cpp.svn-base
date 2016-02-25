#include "../include/File.h"
File::File(){
    this->f = NULL;
    this->result = new int[2500];
    this->result_size = 0;
}
File::~File(){
    delete this->result;
}
bool File::file_open(const char *path,const char *mode){
    this->f = fopen(path,mode);
    if(this->f == NULL){
        return false;
    }else{
        return true;
    }
}
bool File::file_close(){
    if(this->f != NULL){
        fclose(this->f);
        return true;
    }
    return false;
}
bool File::file_write(Node *node){
    if(this->f != NULL){
        fprintf(this->f,"%d %d\n",node->get_X(),node->get_Y());
        return true;
    }
    return false;
}
bool File::file_read(){
    if(this->f != NULL){
       this->result_size = 0;
       char *line = new char[80];
       while(fgets(line,80,this->f) != NULL){
            this->process_line(line);
           // printf("\n----------------------------\n");
            //for(int i=0 ; i < this->result_size ;i++){
              //printf("%d ,",this->result[i]);
            //}
       }
        delete line;
        return true;
    }
    return false;
}
int* File::get_result(){
    int *res = new int[this->result_size];
    for(int i = 0; i< this->result_size ;i++){
        res[i] = this->result[i];

    }
    return res ;
}
int File::get_result_size(){return this->result_size ;}
void File::process_line(char * line){
    int len;

    len = strlen(line);

   // printf("\nLine:%s:%d",line,strlen(line));
    if(len == 1){
        return ;
    }
    int i =0 ,j =0;
    while(i <= len){
        if(line[i] == ' '|| line[i] =='\0'){

                char *sub = new char[i-j];
                sub = this->strcopy(line,j,i);
               // printf("\n SUB STIRNG: %s ->%d:%d",sub,j,i);
               this->result[this->result_size] = strtol(sub,(char **)NULL,10);
                j = i+1;this->result_size++;
                delete sub;

        }
        i++;
    }
}
 char*  File::strcopy(const char *src,int start,int end){
        int i;
        char *dest = new char[end-start];
        for (i = start ; i < end && src[i] != '\0' ; i++)
               dest[i-start] = src[i];
        return dest;
}


