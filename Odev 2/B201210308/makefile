all:derle calistir
derle:
	g++ -I ./include/ -o ./lib/main.o -c ./src/main.cpp 
	g++ -I ./include/ -o ./lib/Kordinant.o -c ./src/Kordinant.cpp 
	g++ -I ./include/ -o ./lib/DogruKuyrugu.o -c ./src/DogruKuyrugu.cpp 
	g++ -I ./include/ -o ./lib/KuyrukDugum.o -c ./src/KuyrukDugum.cpp 
	g++ -I ./include/ -o ./lib/Dosya.o -c ./src/Dosya.cpp
	g++ -I ./include/ -o ./lib/AVLDugum.o -c ./src/AVLDugum.cpp
	g++ -I ./include/ -o ./lib/AVLAgaci.o -c ./src/AVLAgaci.cpp 
	
	
	g++ -I ./include/ -o ./bin/program ./lib/KuyrukDugum.o ./lib/AVLDugum.o ./lib/AVLAgaci.o ./lib/Dosya.o ./lib/DogruKuyrugu.o ./lib/Kordinant.o ./src/main.cpp
calistir:
	./bin/program