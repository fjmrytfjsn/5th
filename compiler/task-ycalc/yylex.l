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
    yylval.dval = yytext[0] - 'A';
    return NAME;
}
"list" {
    return LIST;
}
. {
	fprintf(stderr, "'%s' is ignored.\n", yytext);
}
%%
