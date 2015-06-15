D			[0-9]
L			[a-zA-Z_]
H			[a-fA-F0-9]
E			[Ee][+-]?{D}+
FS			(f|F|l|L)
IS			(u|U|l|L)*
ADDOP                   [+|-]
COMMENTS1               (\/\/.*)
COMMENTS2               ("/*"([^/]|([^\*][/]))*"*/")
COMMENTS                {COMMENTS1}|{COMMENTS2}

%{
#include <cstdio>
#include <cstring>
#include "../include/AstHead.h"
#include "yacc.tab.h"
#include <string>

using namespace std;


void count();
void comment(void);
int check_type(void);
void inityylval(char *yytext);


extern "C"{
int yylex(void);
int yywrap(void);
extern int yyerror(const char *msg);
}
%}

%option yylineno

%%
{COMMENTS}		{  }

"auto"			{ count(); inityylval(yytext); return(AUTO); }
"break"			{ count(); inityylval(yytext); return(BREAK); }
"case"			{ count(); inityylval(yytext); return(CASE); }
"char"			{ count(); inityylval(yytext); return(CHAR); }
"const"			{ count(); inityylval(yytext); return(CONST); }
"continue"		{ count(); inityylval(yytext); return(CONTINUE); }
"default"		{ count(); inityylval(yytext); return(DEFAULT); }
"do"			{ count(); inityylval(yytext); return(DO); }
"double"		{ count(); inityylval(yytext); return(DOUBLE); }
"else"			{ count(); inityylval(yytext); return(ELSE); }
"enum"			{ count(); inityylval(yytext); return(ENUM); }
"extern"		{ count(); inityylval(yytext); return(EXTERN); }
"float"			{ count(); inityylval(yytext); return(FLOAT); }
"for"			{ count(); inityylval(yytext); return(FOR); }
"goto"			{ count(); inityylval(yytext); return(GOTO); }
"if"			{ count(); inityylval(yytext); return(IF); }
"int"			{ count(); inityylval(yytext); return(INT); }
"long"			{ count(); inityylval(yytext); return(LONG); }
"register"		{ count(); inityylval(yytext); return(REGISTER); }
"return"		{ count(); inityylval(yytext); return(RETURN); }
"short"			{ count(); inityylval(yytext); return(SHORT); }
"signed"		{ count(); inityylval(yytext); return(SIGNED); }
"sizeof"		{ count(); inityylval(yytext); return(SIZEOF); }
"static"		{ count(); inityylval(yytext); return(STATIC); }
"struct"		{ count(); inityylval(yytext); return(STRUCT); }
"class"                 { count(); inityylval(yytext); return(CLASS); }
"switch"		{ count(); inityylval(yytext); return(SWITCH); }
"typedef"		{ count(); inityylval(yytext); return(TYPEDEF); }
"union"			{ count(); inityylval(yytext); return(UNION); }
"unsigned"		{ count(); inityylval(yytext); return(UNSIGNED); }
"void"			{ count(); inityylval(yytext); return(VOID); }
"volatile"		{ count(); inityylval(yytext); return(VOLATILE); }
"while"			{ count(); inityylval(yytext); return(WHILE); }
"new"                   { count(); inityylval(yytext); return(NEW_OP); }
"delete"                { count(); inityylval(yytext); return(DELETE_OP); }

(_|{L})(_|{L}|{D})*	{ count(); inityylval(yytext); return(IDENTIFIER); }

0[xX]{H}+{IS}?		{ count(); inityylval(yytext); return(INTEGER_CONSTANT); }
0{D}+{IS}?		{ count(); inityylval(yytext); return(INTEGER_CONSTANT); }
{D}+{IS}?		{ count(); inityylval(yytext); return(INTEGER_CONSTANT); }
L?'(\\.|[^\\'])+'	{ count(); inityylval(yytext); return(CHARACTER_CONSTANT); }

{D}+{E}{FS}?		{ count(); inityylval(yytext); return(FLOATING_CONSTANT); }
{D}*"."{D}+({E})?{FS}?	{ count(); inityylval(yytext); return(FLOATING_CONSTANT); }
{D}+"."{D}*({E})?{FS}?	{ count(); inityylval(yytext); return(FLOATING_CONSTANT); }

L?\"(\\.|[^\\"])*\"	{ count(); inityylval(yytext); return(STRING_LITERAL); }

"..."			{ count(); inityylval(yytext); return(ELLIPSIS); }
">>="			{ count(); inityylval(yytext); return(RIGHT_ASSIGN); }
"<<="			{ count(); inityylval(yytext); return(LEFT_ASSIGN); }
"+="			{ count(); inityylval(yytext); return(ADD_ASSIGN); }
"-="			{ count(); inityylval(yytext); return(SUB_ASSIGN); }
"*="			{ count(); inityylval(yytext); return(MUL_ASSIGN); }
"/="			{ count(); inityylval(yytext); return(DIV_ASSIGN); }
"%="			{ count(); inityylval(yytext); return(MOD_ASSIGN); }
"&="			{ count(); inityylval(yytext); return(AND_ASSIGN); }
"^="			{ count(); inityylval(yytext); return(XOR_ASSIGN); }
"|="			{ count(); inityylval(yytext); return(OR_ASSIGN); }
">>"			{ count(); inityylval(yytext); return(RIGHT_OP); }
"<<"			{ count(); inityylval(yytext); return(LEFT_OP); }
"++"			{ count(); inityylval(yytext); return(INC_OP); }
"--"			{ count(); inityylval(yytext); return(DEC_OP); }
"->"			{ count(); inityylval(yytext); return(PTR_OP); }
"&&"			{ count(); inityylval(yytext); return(AND_OP); }
"||"			{ count(); inityylval(yytext); return(OR_OP); }
"<="			{ count(); inityylval(yytext); return(LE_OP); }
">="			{ count(); inityylval(yytext); return(GE_OP); }
"=="			{ count(); inityylval(yytext); return(EQ_OP); }
"!="			{ count(); inityylval(yytext); return(NE_OP); }
";"			{ count(); return(';'); }
("{"|"<%")		{ count(); return('{'); }
("}"|"%>")		{ count(); return('}'); }
","			{ count(); return(','); }
":"			{ count(); return(':'); }
"="			{ count(); return('='); }
"("			{ count(); return('('); }
")"			{ count(); return(')'); }
("["|"<:")		{ count(); return('['); }
("]"|":>")		{ count(); return(']'); }
"."			{ count(); return('.'); }
"&"			{ count(); return('&'); }
"!"			{ count(); return('!'); }
"~"			{ count(); return('~'); }
"-"			{ count(); return('-'); }
"+"			{ count(); return('+'); }
"*"			{ count(); return('*'); }
"/"			{ count(); return('/'); }
"%"			{ count(); return('%'); }
"<"			{ count(); return('<'); }
">"			{ count(); return('>'); }
"^"			{ count(); return('^'); }
"|"			{ count(); return('|'); }
"?"			{ count(); return('?'); }

[ \t\v\n\f]		{ count(); }
.			{ string s(yytext); s = "error: lex errror at " + s; yyerror(s.c_str()); }

%%

void inityylval(char *yytext) {
    yylval.yystring = new string(yytext);
}

int yywrap()
{
	return(1);
}


void comment(void)
{
	char c, c1;

loop:
	while ((c = getchar()) != '*' && c != EOF)
		putchar(c);

	if ((c1 = getchar()) != '/' && c != EOF)
	{
		unput(c1);
		goto loop;
	}

	if (c != EOF)
		putchar(c1);
}


int yycolumn = 0;

void count()
{
	int i;

	for (i = 0; yytext[i] != '\0'; i++)
		if (yytext[i] == '\n')
			yycolumn = 0;
		else if (yytext[i] == '\t')
			yycolumn += 8 - (yycolumn % 8);
		else
			yycolumn++;

	ECHO;
}


int check_type(void)
{


	return(IDENTIFIER);
}

