%{
#include "y.tab.h"
%}

%%

[ \t\n]+           { /* Skip whitespace */ }
[.]+               { return PERIOD; }
and|or           { return CONJUNCTION; }
[a-zA-Z]+          { return WORD; }
,                   { return COMMA; }

%%

int yywrap() {
    return 1;
}
