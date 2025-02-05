all:derle bagla calistir
derle:
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
	g++ -c -I "./include" ./src/IAA_Dugum.cpp -o ./lib/IAA_Dugum.o
	g++ -c -I "./include" ./src/IkiliAramaAgaci.cpp -o ./lib/IkiliAramaAgaci.o
	g++ -c -I "./include" ./src/BagliListe.cpp -o ./lib/BagliListe.o
	g++ -c -I "./include" ./src/BL_Dugum.cpp -o ./lib/BL_Dugum.o
	g++ -c -I "./include" ./src/Dosya.cpp -o ./lib/Dosya.o
bagla:
	g++ ./lib/IAA_Dugum.o ./lib/IkiliAramaAgaci.o  ./lib/BagliListe.o ./lib/BL_Dugum.o ./lib/Dosya.o ./lib/main.o -o ./bin/program
calistir:
	./bin/program