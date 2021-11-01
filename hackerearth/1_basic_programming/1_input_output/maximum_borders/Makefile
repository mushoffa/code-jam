NAME=$(shell basename ${PWD})

clean:
	rm ${NAME}

build:
	g++ -std=c++17 -Wshadow -Wall -o $(NAME) $(NAME).cpp

run:
	./${NAME} < in

check:
	$(shell diff <(./${NAME} < in) out)