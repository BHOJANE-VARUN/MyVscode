%{
#include<stdio.h>
int lc =0,cc =0,wc=0,ic=0;
%}

%%
[\n] {lc++;}
[a-zA-Z]+ {cc += yyleng;}
%%

int yywrap()
{
    return 1;
}

int main()
{
    yyin = fopen("temp.txt","r");
    yylex();
    printf("total no of lines: %d\n",lc);
    printf("total no of characters: %d\n",cc);
    return 0;
}