#
#  To sa opcje dla kompilacji
#
CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++0x

__start__: robot_2D
	./robot_2D

robot_2D: obj obj/main.o obj/Przeszkoda.o obj/Zbior_Wierzch.o obj/Scena.o obj/Trasa.o obj/Macierz2x2.o obj/Wektor2D.o\
           obj/lacze_do_gnuplota.o obj/Obiekt_Graf.o obj/Robot.o obj/Fabryka_Ob.o
	g++ -Wall -pedantic -std=c++0x -o robot_2D obj/main.o obj/Wektor2D.o\
                        obj/Macierz2x2.o obj/Przeszkoda.o obj/lacze_do_gnuplota.o obj/Zbior_Wierzch.o obj/Scena.o obj/Trasa.o obj/Obiekt_Graf.o obj/Robot.o obj/Fabryka_Ob.o

obj:
	mkdir obj

obj/lacze_do_gnuplota.o: inc/lacze_do_gnuplota.hh src/lacze_do_gnuplota.cpp
	g++ -c ${CXXFLAGS} -o obj/lacze_do_gnuplota.o src/lacze_do_gnuplota.cpp

obj/main.o: src/main.cpp inc/Przeszkoda.hh inc/Macierz2x2.hh inc/Wektor2D.hh inc/Zbior_Wierzch.hh inc/Scena.hh inc/Trasa.hh inc/Obiekt_Graf.hh inc/lacze_do_gnuplota.hh inc/Robot.hh inc/Fabryka_Ob.hh
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

obj/Przeszkoda.o: src/Przeszkoda.cpp inc/Przeszkoda.hh
	g++ -c ${CXXFLAGS} -o obj/Przeszkoda.o src/Przeszkoda.cpp

obj/Macierz2x2.o: src/Macierz2x2.cpp inc/Macierz2x2.hh 
	g++ -c ${CXXFLAGS} -o obj/Macierz2x2.o src/Macierz2x2.cpp

obj/Wektor2D.o: src/Wektor2D.cpp inc/Wektor2D.hh
	g++ -c ${CXXFLAGS} -o obj/Wektor2D.o src/Wektor2D.cpp

obj/Zbior_Wierzch.o: src/Zbior_Wierzch.cpp inc/Zbior_Wierzch.hh
	g++ -c ${CXXFLAGS} -o obj/Zbior_Wierzch.o src/Zbior_Wierzch.cpp

obj/Scena.o: src/Scena.cpp inc/Scena.hh
	g++ -c ${CXXFLAGS} -o obj/Scena.o src/Scena.cpp

obj/Trasa.o: src/Trasa.cpp inc/Trasa.hh
	g++ -c ${CXXFLAGS} -o obj/Trasa.o src/Trasa.cpp

obj/Obiekt_Graf.o: src/Obiekt_Graf.cpp inc/Obiekt_Graf.hh
	g++ -c ${CXXFLAGS} -o obj/Obiekt_Graf.o src/Obiekt_Graf.cpp

obj/Robot.o: src/Robot.cpp inc/Robot.hh
	g++ -c ${CXXFLAGS} -o obj/Robot.o src/Robot.cpp

obj/Fabryka_Ob.o: src/Fabryka_Ob.cpp inc/Fabryka_Ob.hh
	g++ -c ${CXXFLAGS} -o obj/Fabryka_Ob.o src/Fabryka_Ob.cpp

clean:
	rm -f obj/*.o robot_2D