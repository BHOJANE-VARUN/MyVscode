%{
#include "myas3.tab.h"
%}

%%
[\t\n] {}
int|float|double {return dt;}
[a-z]+ {return id;}
; {return sm;}
, {return cm;}
%%

int yywrap()
{
    return 1;
}
