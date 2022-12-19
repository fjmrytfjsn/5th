%{
#include "y.tab.h"
%}

%option noyywrap
DIGIT	[0-9]

%%
[ \t\r]+ {}

"-"?{DIGIT}+("."{DIGIT}*)? {
    sscanf(yytext, "%lf", &yylval);
    return NUM;
}

"-"?"."{DIGIT}+ {
    sscanf(yytext, "%lf", &yylval);
    return NUM;
}

[-+*/()\n$=] {
    return yytext[0];
}
[A-Za-z] {
    yylval.varname = yytext[0];
    return NAME;
}
"list" {
    return LIST;
}
"clear" {
    return CLEAR;
}
"quit" {
    exit(0);
}
. {
	fprintf(stderr, "'%s' is ignored.\n", yytext);
}
%%
