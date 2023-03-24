main: main.o funcs.o imageio.o
	g++ -o main main.o funcs.o imageio.o

sample: sample.o imageio.o
	g++ -o sample sample.o imageio.o

main.o: main.cpp funcs.h imageio.h

sample.o: sample.cpp imageio.h

imageio.o: imageio.cpp imageio.h

funcs.o: funcs.cpp funcs.h


clean:
	rm -f sample.o imageio.o main.o funcs.o taskA.pgm taskB.pgm taskC.pgm taskD.pgm taskE.pgm taskF.pgm main a.out