%{
#include "index.tab.h"
extern int yylval;
%}


%%

[0-9]+   { yylval = atoi(yytext); return NUM; }
[+\-]    { return yytext[0]; }
[\n\t ]  ;  // skip whitespace
.        { return yytext[0]; }

%%
int yywrap() { return 1; }
