#include "head.h"

int main(int argc, char** argv)
{
    FILE* fp;
    
    int result;
    
   if((result = getopt(argc,argv,"t:")) != -1){
        const char* name = optarg;
        if(result == 't'){
        
                fp = fopen(name,"w");
                #ifdef _DEBUG
                    printf("已创建文件.\n");
                #endif
                while (1){
                double res = process();
                fflush(fp);             
                }
            
            fclose(fp);
        
    }
    }
    return 0;
}