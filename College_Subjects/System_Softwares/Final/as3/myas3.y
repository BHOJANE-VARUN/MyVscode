%{
#include<stdio.h>
#include<stdlib.h>
int yyerror(char* str);
int yylex();
%}

%token id cm dt sm
%start s

%%
s: dt varun sm {printf("valid assignment statement\n"); return 0;}
;
varun: id | id cm varun
;
%%

int yyerror(char* str)
{
    printf("error occuried: %s \n",str);
}

int main()
{
    printf("enter a assignment statement:");
    yyparse();
    return 0;
}