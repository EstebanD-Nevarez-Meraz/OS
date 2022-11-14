output: Main.o myProcess.o myReadyQueue.o Scheduler.o
	g++ Main.o myProcess.o myReadyQueue.o Scheduler.o -o output
	
Main.o: Main.cpp
	g++ -c Main.cpp

myProcess.o: myProcess.cpp myProcess.h
	g++ -c	myProcess.cpp
	
myReadyQueue.o: myReadyQueue.cpp myReadyQueue.h
	g++ -c myReadyQueue.cpp
	
Scheduler.o: Scheduler.cpp Scheduler.h
	g++ -c	Scheduler.cpp
	
clean:
	rm *.o output