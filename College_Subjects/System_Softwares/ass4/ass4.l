%{
#include <stdio.h>
#include <stdlib.h>
#include "ass4.tab.h"

extern int yylval;
%}

%%

"-"[0-9]+  { yylval = atoi(yytext); return NUM; }
[0-9]+     { yylval = atoi(yytext); return NUM; }
[\n]       { return 0; }
[\t ]+     { /* Ignore whitespace */ }
"("        { return '('; }
")"        { return ')'; }
.          { return yytext[0]; }

%%

int yywrap() {
    return 1;
}
