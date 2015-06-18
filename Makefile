cc=clang++
astdir=$(./src/astimp)
argu=
vpath %.o ./output
vpath %.c ./src
vpath %.cpp ./src/astimp
vpath %.h ./include/ast
vpath %.h ./src
vpath %.l ./src
vpath %.y ./src

astimpobj=AbsDectorAst.o \
AddExpAst.o \
ArgExpListAst.o \
AssignExpAst.o \
AssignOpAst.o \
CastExpAst.o \
ClassDectionAst.o \
ClassDectionListAst.o \
ClassDectorAst.o \
ClassDectorListAst.o \
ClassSpecifierAst.o \
CompoundStmAst.o \
ConditionalExpAst.o \
ConstantExpAst.o \
ConstantValueAst.o \
Coordinate.o \
DectionAst.o \
DectionListAst.o \
DectionSpecifiersAst.o \
DectorAst.o \
DirAbsDectorAst.o \
DirDectorAst.o \
EqualExpAst.o \
ExpAst.o \
ExpStmAst.o \
ExtDectionAst.o \
FuncDefAst.o \
IdentifierListAst.o \
InitDectorAst.o \
InitDectorListAst.o \
InitzerAst.o \
InitzerListAst.o \
IterationStmAst.o \
JumpStmAst.o \
LabeledStmAst.o \
LogicalAndExpAst.o \
LogicalOrExpAst.o \
MulExpAst.o \
NodeAst.o \
ParamDectionAst.o \
ParamListAst.o \
ParamTypeListAst.o \
PointerAst.o \
PostfixExpAst.o \
PrimaryExpAst.o \
ProgramStartAst.o \
RelationExpAst.o \
SelectionStmAst.o \
SpeciQualiFierListAst.o \
StmAst.o \
StmListAst.o \
StorageClassSpecifierAst.o \
TerminateAst.o \
TranslationUnitAst.o \
TypeNameAst.o \
TypeQualifierAst.o \
TypeQualifierListAst.o \
TypeSpecifierAst.o \
UnaryExpAst.o \
UnaryOpAst.o 

.PHONY: release
release: 		complier.out

.PHONY: debug
debug: 		argu+=-ggdb3
debug: 		 	complier.out

complier.out:  			lex.yy.c yacc.tab.c yacc.tab.h $(astimpobj)
				$(cc) -o complier.out $(argu) $(addprefix ./src/,lex.yy.c yacc.tab.c)  $(addprefix ./output/, $(astimpobj)) -ll

lex.yy.c: 		lex.l yacc.tab.h
				flex ./src/lex.l
				mv lex.yy.c ./src

yacc.tab.c yacc.tab.h: 	yacc.y
				bison -dv ./src/yacc.y
				mv yacc.tab.c yacc.tab.h ./src
				rm yacc.output

$(astimpobj):%.o:%.cpp %.h
				$(cc) -c $(argu) $(addprefix $(astdir), $<) -o $@
				mv $@ ./output


