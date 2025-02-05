all:derle calistir
derle:
	g++ -I ./include/ -o ./lib/main.o -c ./src/main.cpp 
	g++ -I ./include/ -o ./lib/Liste.o -c ./src/Liste.cpp 
	g++ -I ./include/ -o ./lib/Dugum.o -c ./src/Dugum.cpp
	g++ -I ./include/ -o ./lib/Dosya.o -c ./src/Dosya.cpp  
	
	g++ -I ./include/ -o ./bin/program ./lib/Liste.o ./lib/Dugum.o ./lib/Dosya.o ./src/main.cpp
calistir:
	./bin/program