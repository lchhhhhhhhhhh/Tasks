#include "head.h"

int main(int argc, char** argv)
{
    FILE* fp;
    
    int result;
    
   if((result = getopt(argc,argv,"t:")) != -1){
        const char* name = optarg;
        if(result == 't'){
        
                fp = fopen(name,"w");
                while (1){
                double res = process();
                fflush(fp);             
                }
            
            fclose(fp);
        
    }
    }
    return 0;
}