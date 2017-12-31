play: Room.o tree.o Girl.o main.cpp
	g++ -std=c++11 Room.o tree.o Girl.o main.cpp -o play
Room.o: Room.cpp
	g++ -c Room.cpp
tree.o: tree.cpp
	g++ -c tree.cpp
Girl.o: Girl.cpp
	g++ -c Girl.cpp
clean:
	rm -rf play *.o
