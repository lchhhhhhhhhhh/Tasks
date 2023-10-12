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
    int i,t;
    double e,a,b;
    char c[50];
    Stackn n;
    init_stack(&n);
    #ifdef _DEBUG
        printf("Fail to initialize stack!!!\n");
    #endif
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
                    return ERROR;
                }
                break;
        }
    }
    stack_pop(&n,&e);
    if (e == ERROR)
        printf("建议检查表达式！\n");
    return e;

}

double dec(char str[]){
    int i;
    
    
    char post[50];
    
    if(str[0]=='h'&&str[1]=='e'&&str[2]=='l'&&str[3]=='p')
    {
        printf("input expression to calculate\nuse\"ctrl+u\"to clear\n");
        //printf("");
        return 0;
    }
    if(str[0]=='q'&&str[1]=='u'&&str[2]=='i'&&str[3]=='t')
    {
        return 0;
    }
    printf("\033[0;30;35m \n对应的后缀表达式： \033[0m \n");
    trans(str,post);
    printf("%s\n",post);
    printf("\033[0;30;35m \n表达式的结果是： \033[0m \n");
    double res = calc(post);
    printf("%f\n",res);
    return res;
}

void tbin(char* str,char* post){
    int i = 0;
    int a,b,d,f;
    char tr[50];
    while (str[i] != '\0'){
    while (isdigit(str[i])){
        tr[i] = str[i];
        ++i;
    }
    a = strlen(tr);
    int c = a;
    d = 0;
    for(int e = 0;e <= a; ++e){
        
        b = tr[e] - '0';
        b *= pow(2,c);
        --c;
        d += b;
    }
    memset(tr,0,sizeof(tr));
    f = 0;
    char ch[30];
    sprintf(ch,"%d",d);
    for(int e = 0;ch[e] !='\0';++e){
        ch[e] = post[f];
        ++f;
    }
    memset(ch,0,sizeof(ch));
    if (!isdigit(str[i])) 
    {
        post[f] = str[i];
        ++i;
        ++f;
        }
    }
    post[f] = '\0';
}

int bint_print(double dec_0)
{
    int dec = dec_0;
	int a[100];
	int i = 0;
	
	while (dec>0)
	{
		a[i] = dec % 2;
		i = i + 1;
		dec = dec / 2;
	}
	for (i--; i >= 0; i--)
		printf("%d", a[i]);
	return 0;

}

char* inttohex(int aa)
{
     char str[50];
     static  int  i = 0;
     if  (aa < 16)         
     {
         if  (aa < 10)         
             str[i] = aa +  '0' ;
         else
             str[i] = aa - 10 +  'A' ;
         str[i+1] =  '\0' ; 
     }
     else
     {
         inttohex(aa / 16);   
         i++;                 
         aa %= 16;            
         if  (aa < 10)         
             str[i] = aa +  '0' ;
         else
             str[i] = aa - 10 +  'A' ;
     }
     return str;
}

int get_hex(char ch)
{
    if(ch >= '0' && ch <= '9')
    {
        return ch - '0';
    }
    if(ch >= 'A' && ch <='F') 
    {
        return ch - 'A' + 10;
    }
    if(ch >= 'a' && ch <= 'f')
    {
        return ch - 'a' + 10;
    }
    return -1;
}

long hexToDec(char *source)
{
    long sum = 0;
    long t = 1;
    int i, len;
 
    len = strlen(source);
    for(i=len-1; i>=0; i--)
    {
        sum += t * get_hex(*(source + i));
        t *= 16;
    }  
 
    return sum;
}

// long hex_sep(char* str){
//     char c[50];
//     int i,p;
//     i = 0;
//     p = 0;
    
//     while ((str[i] != '+') && (str[i] != '-') && (str[i] != '*') && (str[i] != '/'))
//     {
//         c[p] = str[i];
//         ++p;
//         ++i;
//     }
// }

char* hex(char str[]){
    int i,a,b;
    char c[50];
    char post[50];
    i = 0;
    int p = 0;
    b = 0;
    while (str[i] != '\0')
    {
    while ((str[i] != '+') && (str[i] != '-') && (str[i] != '*') && (str[i] != '/'))
    {
        c[p] = str[i];
        ++p;
        ++i;
    }
    a = hexToDec(c);
    sprintf(post,"%d",a);
    ++b;
    if ((str[i] == '+') || (str[i] == '-') || (str[i] == '*') || (str[i] == '/'))
        {
            post[b] = str[i];
        }
    }
    return post;
}

// void total(FILE* fp,const char* name){
//     fp = fopen(name,"w");
//                 #ifdef _DEBUG
//                     printf("已创建文件.\n");
//                 #endif
//                 while (1){
//                 double res = process();
//                 fflush(fp); 
//                 }
// }

char get_char()
{
    fd_set rfds;
    struct timeval tv;
    char ch = 0;
 
    FD_ZERO(&rfds);
    FD_SET(0, &rfds);
    tv.tv_sec = 1;
    tv.tv_usec = 10;
 
    if (select(1, &rfds, NULL, NULL, &tv) > 0){
        ch = getchar(); 
    }
    return ch;
}

