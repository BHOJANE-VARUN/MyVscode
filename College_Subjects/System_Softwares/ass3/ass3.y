%{
#include<stdio.h>
#include<stdlib.h>
int yyerror(const char* str);
%}

%token DT COMMA SC ID


%%
S: DT var_list SC { printf("valid declaration statement\n");}
var_list: ID | 
        ID COMMA var_list
        ;
%%

int yyerror(const char* str)
{
    printf("Invalid Syntax\n");
    return 0;
}

int main()
{
   
    printf("Enter declaration statement:");
    yyparse();
    
    
    return 0;
}





