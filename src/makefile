CPP=g++
RM=rm -f

projet : euler.o gradient.o matrix.o main.o
	$(CPP) $^ -o $@

%.o:%.cpp
	$(CPP) -o $@ -c $<

main.o :  main.cpp
gradient.o : gradient.cpp ../include/gradient.h
matrix.o : matrix.cpp ../include/matrix.h
euler.o : euler.cpp ../include/euler.h

clean:
	$(RM) main_snake.o keyboard-event.o snake
.PHONY: clean
