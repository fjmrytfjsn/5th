/* ???????????? */
%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define STACKSIZE  256

double S[STACKSIZE], x;         /* ?????���??????????���? */
int P = -1;                     /* ?????���?????? */
struct stab {
    double val;
    char name[10];
} stab[100];
int count=0;

void printStack();              /* ?????���????????????????? */
void listing();
%}

%option noyywrap
DIGIT	[0-9]
ALPHA   [A-Z]

%%
[ \t\r]+        { /* ignored */ }
\n              { printStack(); }
"-"?{DIGIT}+("."{DIGIT}*)?      { sscanf(yytext, "%lf", &S[++P]); }
"-"?"."{DIGIT}+ { sscanf(yytext, "%lf", &S[++P]); }
"+"             { if (P>0) { S[P-1] += S[P]; --P; } }
"-"             { if (P>0) { S[P-1] -= S[P]; --P; } }
"*"             { if (P>0) { S[P-1] *= S[P]; --P; } }
"/"             { if (P>0) { S[P-1] /= S[P]; --P; } }
"+-"            { if (P>-1) S[P] = -S[P]; }
"?"             { puts("p スタックの先頭を除去する．(droP or Pop)");
                  puts("d スタックの先頭を複製する．(Dupricate)");
                  puts("o スタックの２番目の要素を複製する．(Over)");
                  puts("s スタックの先頭と２番目を入れ替える．(Swap)");
                  puts("r スタック冒頭の３要素を順に入れ替える．(Rotate)");
                  puts("c スタックを全てクリアして，空にする．(Clear)");
                  puts("q プログラムを終了する．(Quit)"); }
{ALPHA}=        { printf("%s\n", yytext[0]);}
{ALPHA}         { printf("%f\n", stab[yytext[0]].val); }
v               { listing(); }
p               { if (P>-1) --P; }
d               { if (P>-1) { ++P; S[P] = S[P-1]; } }
o               { if (P>0) { ++P; S[P] = S[P-2]; } }
s               { if (P>0) { x=S[P-1]; S[P-1]=S[P]; S[P]=x; } }
r               { if (P>1) { x=S[P-2]; S[P-2]=S[P-1]; S[P-1]=S[P]; S[P]=x; } }
c               { P=-1; }
q               { return; }
[^ \t\r\n]+     { fprintf(stderr, "unknown token (%s)\n", yytext); }
%%

main() {
    printf("*** Reverse Polish Calculator \n");
    printf("> ");
    yylex();
}

void printStack() {
    int i;
    for(i=0; i<=P; i++) printf("%.8g ", S[i]);
    printf("> ");
}

void listing() {
    int i;
    for(i=0;i<count; i++)
        printf("%s = %f\n", stab[i].name, stab[i].val);
}
