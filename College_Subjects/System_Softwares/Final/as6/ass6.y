%{
#include <stdio.h>
#include <stdlib.h>

void yyerror(char *s);
int yylex();
%}

%token WORD PERIOD COMMA CONJUNCTION

%%

sentence: simple_sentence PERIOD            { printf("Simple Sentence\n"); return 0;}
        | compound_sentence PERIOD         { printf("Compound Sentence\n"); return 0; }
        ;

simple_sentence: subject verb             { printf("Simple Sentence\n"); }
               ;

compound_sentence: simple_sentence CONJUNCTION simple_sentence 
                 { printf("Compound Sentence\n"); }
                 ;

subject: WORD                               { /* Subject is a word (noun) */ }
       ;

verb: WORD                                  { /* Verb is a word (verb) */ }
    ;

%%

void yyerror(char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main() {
    printf("Enter sentence:\n");
    yyparse();
    return 0;
}
