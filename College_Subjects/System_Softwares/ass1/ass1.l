%{
#include<stdio.h>
%}


%%
"#include" {printf("include statement \n");}
"<"|">"|"{"|"}"|";"   { printf("Punctuations : %s\n", yytext);}
[a-z]+[.]h { printf("header file %s \n",yytext);}
int|float|long|void  {printf("Keyword found : %s \n",yytext);}
[a-zA-Z_][a-zA-Z_0-9]*"(" {printf("function Name: %s)\n",yytext);}
[a-zA-Z_][a-zA-Z_0-9]* {printf("variable name: %s \n",yytext);}
["].*["] {printf("string iterable:%s \n",yytext);}
")" {}
"="|"-"|"+" {printf("operator: %s\n",yytext);}
[0-9]+ {printf("Integer:%s\n",yytext);}
[0-9]+.[0-9]+ {printf("Decimal Integer :%s\n",yytext);}
[/][/].* {printf("single line commant:%s \n",yytext);}
"/*"[^*]*"*/" {printf("multi-line comment:%s",yytext);}
%%


int yywrap()
{
    return 1;
}

int main()
{
    yyin = fopen("test.c","r");
    yylex();
    return 0;
}