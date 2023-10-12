#include "head.h"

int main(int argc, char** argv)
{
    FILE* fp;
    char str[50];
    char post[50];
    int result;
    
   if((result = getopt(argc,argv,"t:")) != -1){
        const char* name = optarg;
        if(result == 't'){
                //system("stty -icanon");
                char in = getchar();
                while(1){
                    
                    char* p;
                    
                    if (in == 'B'){
                        p =  readline("");
                    
                    strcpy(str,p);
                        char fir[50];
                        char sec[50];
                        tbin(str,fir);
                        trans(fir,sec);
                        result = calc(sec);
                        bint_print(result);
                    }
                    else if (in == 'H'){
                        p =  readline("");
                    
                    strcpy(str,p);
                        char sec[50];
                        trans(hex(str),sec);
                        result = calc(sec);
                        printf("%s",inttohex(result));
                    }
                    else
                        {
                            p =  readline("");
                    
                    strcpy(str,p);
                            dec(str);
                }
                            
                }
            
            fclose(fp);
        }
        
    
        }
    return 0;
}