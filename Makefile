G = g++
INCDIR = include
INC = -I ${INCDIR}
OBJ = build
SRC = source

EXEC = bin/wordle

OBJFILS = ${OBJ}/main.o ${OBJ}/wordleGame.o ${OBJ}/utility.o ${OBJ}/letter.o
CPPFILS = ${SRC}/main.cpp ${OBJ}/wordleGame.o ${OBJ}/utility.o ${OBJ}/letter.cpp

${EXEC} : ${OBJFILS}
	${G} -ggdb ${INC} $^ -o $@ -O0

.Phony: run
run :
	${EXEC} /resources/wordle-answers-alphabetical.txt

${OBJ}/%.o : ${SRC}/%.cpp
	${G} -ggdb ${INC} -c $^ -o $@

.Phony: clean
clean : 
	rm ${OBJFILS} ${EXEC}

.Phony: debug
debug :
	gdb ${EXEC}
