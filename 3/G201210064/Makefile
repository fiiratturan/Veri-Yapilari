all:derle bagla calistir
derle:
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
	g++ -c -I "./include" ./src/Liste.cpp -o ./lib/Liste.o
	g++ -c -I "./include" ./src/ListeDugum.cpp -o ./lib/ListeDugum.o
	g++ -c -I "./include" ./src/Dugum.cpp -o ./lib/Dugum.o
	g++ -c -I "./include" ./src/Kromozom.cpp -o ./lib/Kromozom.o
	g++ -c -I "./include" ./src/Dosya.cpp -o ./lib/Dosya.o
bagla:
	g++ ./lib/Liste.o ./lib/ListeDugum.o  ./lib/Dugum.o ./lib/Kromozom.o ./lib/Dosya.o ./lib/main.o -o ./bin/program
calistir:
	./bin/program