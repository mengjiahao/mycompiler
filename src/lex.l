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
#include "node.h"
#include "y.tab.h"
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

"auto"			{ count(); return(AUTO); }
"break"			{ count(); return(BREAK); }
"case"			{ count(); return(CASE); }
"char"			{ count(); return(CHAR); }
"const"			{ count(); return(CONST); }
"continue"		{ count(); return(CONTINUE); }
"default"		{ count(); return(DEFAULT); }
"do"			{ count(); return(DO); }
"double"		{ count(); return(DOUBLE); }
"else"			{ count(); return(ELSE); }
"enum"			{ count(); return(ENUM); }
"extern"		{ count(); return(EXTERN); }
"float"			{ count(); return(FLOAT); }
"for"			{ count(); return(FOR); }
"goto"			{ count(); return(GOTO); }
"if"			{ count(); return(IF); }
"int"			{ count(); return(INT); }
"long"			{ count(); return(LONG); }
"register"		{ count(); return(REGISTER); }
"return"		{ count(); return(RETURN); }
"short"			{ count(); return(SHORT); }
"signed"		{ count(); return(SIGNED); }
"sizeof"		{ count(); return(SIZEOF); }
"static"		{ count(); return(STATIC); }
"struct"		{ count(); return(STRUCT); }
"class"                 { count(); return(CLASS); }
"switch"		{ count(); return(SWITCH); }
"typedef"		{ count(); return(TYPEDEF); }
"union"			{ count(); return(UNION); }
"unsigned"		{ count(); return(UNSIGNED); }
"void"			{ count(); return(VOID); }
"volatile"		{ count(); return(VOLATILE); }
"while"			{ count(); return(WHILE); }
"new"                   { count(); return(NEW_OP); }
"delete"                { count(); return(DELETE_OP); }

(_|{L})(_|{L}|{D})*	{ count(); inityylval(yytext); return(IDENTIFIER); }

0[xX]{H}+{IS}?		{ count(); inityylval(yytext); return(INTEGER_CONSTANT); }
0{D}+{IS}?		{ count(); inityylval(yytext); return(INTEGER_CONSTANT); }
{D}+{IS}?		{ count(); inityylval(yytext); return(INTEGER_CONSTANT); }
L?'(\\.|[^\\'])+'	{ count(); inityylval(yytext); return(CHARACTER_CONSTANT); }

{D}+{E}{FS}?		{ count(); inityylval(yytext); return(FLOATING_CONSTANT); }
{D}*"."{D}+({E})?{FS}?	{ count(); inityylval(yytext); return(FLOATING_CONSTANT); }
{D}+"."{D}*({E})?{FS}?	{ count(); inityylval(yytext); return(FLOATING_CONSTANT); }

L?\"(\\.|[^\\"])*\"	{ count(); inityylval(yytext); return(STRING_LITERAL); }

"..."			{ count(); return(ELLIPSIS); }
">>="			{ count(); return(RIGHT_ASSIGN); }
"<<="			{ count(); return(LEFT_ASSIGN); }
"+="			{ count(); return(ADD_ASSIGN); }
"-="			{ count(); return(SUB_ASSIGN); }
"*="			{ count(); return(MUL_ASSIGN); }
"/="			{ count(); return(DIV_ASSIGN); }
"%="			{ count(); return(MOD_ASSIGN); }
"&="			{ count(); return(AND_ASSIGN); }
"^="			{ count(); return(XOR_ASSIGN); }
"|="			{ count(); return(OR_ASSIGN); }
">>"			{ count(); return(RIGHT_OP); }
"<<"			{ count(); return(LEFT_OP); }
"++"			{ count(); return(INC_OP); }
"--"			{ count(); return(DEC_OP); }
"->"			{ count(); return(PTR_OP); }
"&&"			{ count(); return(AND_OP); }
"||"			{ count(); return(OR_OP); }
"<="			{ count(); return(LE_OP); }
">="			{ count(); return(GE_OP); }
"=="			{ count(); return(EQ_OP); }
"!="			{ count(); return(NE_OP); }
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
    yylval.yystring = NodeTag::cloneString(yytext);
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

