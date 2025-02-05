all:derle calistir
derle:
	g++ -I ./include/ -o ./lib/main.o -c ./src/main.cpp
	g++ -I ./include/ -o ./lib/Dosya.o -c ./src/Dosya.cpp
	g++ -I ./include/ -o ./lib/Basamak.o -c ./src/Basamak.cpp  
	g++ -I ./include/ -o ./lib/Sayi.o -c ./src/Sayi.cpp
	g++ -I ./include/ -o ./lib/Dugum.o -c ./src/Dugum.cpp
	g++ -I ./include/ -o ./lib/SayilarListesi.o -c ./src/SayilarListesi.cpp
	
	g++ -I ./include/ -o ./bin/program ./lib/Dosya.o ./lib/Basamak.o ./lib/Sayi.o ./lib/Dugum.o ./lib/SayilarListesi.o ./src/main.cpp 
calistir:
	./bin/program