#include "head.h"

void trans(char* str,char* p){
    Stack s;   
    init_stackc(&s);   
    char e;
    int i;
    int j=0;
    for(i=0 ; i<strlen(str) ; i++)  
    {
    
        
        while(isdigit(str[i]) || '.'==str[i])
        {
            p[j++]=str[i++];
            if(!isdigit(str[i]) && '.'!=str[i])
                p[j++]=' ';   
        }
 

        if('('==str[i])
            stack_pushc(&s,str[i]);
 
        
        if(')'==str[i])
        {
            while('(' != *(s.pTop-1))
            {
                stack_popc(&s,&e);
                p[j++]=e;
                p[j++]=' ';
            }
            stack_popc(&s,&e);  
        }
 
   
        if('+'==str[i] || '-'==str[i])
        {
            while(!StackEmpty(&s) && '('!=*(s.pTop-1))
            {
                stack_popc(&s,&e);
                p[j++]=e;
                p[j++]=' ';
            }
            stack_pushc(&s,str[i]);
        }
 

        if('*'==str[i] || '/'==str[i] || '%'==str[i])
        {
            while(!StackEmpty(&s) && '('!=*(s.pTop-1) && '+'!=*(s.pTop-1) && '-'!=*(s.pTop-1))
            {
                stack_popc(&s,&e);
                p[j++]=e;
                p[j++]=' ';
            }
           stack_pushc(&s,str[i]);
        }
    }
    
    
    while(!StackEmpty(&s)){
        stack_popc(&s,&e);
        if('('!=e)
        {
            p[j++]=e;
            p[j++]=' ';
        }
    }
    p[--j]='\0';
}

double calc(char* str){
    int i;
    double e,a,b;
    char c[50];
    Stackn n;
    init_stack(&n);
    for(i=0; i<strlen(str); i++){
        int d=0;
        while(isdigit(str[i]) || str[i] =='.'){
            c[d++] = str[i++];
            c[d] = '\0';
            if(!isdigit(str[i]) && str[i] != '.'){
                e = atof(c);
                stack_push(&n,e);
            } 
        }
        switch(str[i]){
            case '+':
                stack_pop(&n,&a);
                stack_pop(&n,&b);
                stack_push(&n,a+b);
                break;
            case '-':
                stack_pop(&n,&a);
                stack_pop(&n,&b);
                stack_push(&n,b-a);
                break;
            case '*':
                stack_pop(&n,&a);
                stack_pop(&n,&b);
                stack_push(&n,a*b);
                break;
            case '/':
                stack_pop(&n,&a);
                stack_pop(&n,&b);
                if(a!=0)
                    stack_push(&n,b/a);
                else
                {
                    printf("Math error!\n");
                    return 0;
                }
                break;
        }
    }
    stack_pop(&n,&e);
    return e;

}

double process(){
    int i;
    
    char str[50];
    char post[50];
    char *out;
    char* p;
    p =  readline("");
    strcpy(str,p);
    if(str[0]=='h'&&str[1]=='e'&&str[2]=='l'&&str[3]=='p')
    {
        printf("input expression to calculate\nuse\"ctrl+u\"to clear\n");
        //printf("");
        return 0;
    }
    // if(str[0]=='q'&&str[1]=='u'&&str[2]=='i'&&str[3]=='t')
    // {
    //     return 0;
    // }
    printf("\033[0;30;35m \n对应的后缀表达式： \033[0m \n");
    trans(str,post);
    printf("%s\n",post);
    printf("\033[0;30;35m \n表达式的结果是： \033[0m \n");
    double res = calc(post);
    printf("%f\n",res);
    return res;
}