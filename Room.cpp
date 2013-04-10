#include "Room.h"

void Room::set_near(Room *pt, int posi){
    nearpt[posi] = pt;
}

Room* Room::get_near(int posi){
	return nearpt[posi];
}

void Room::messg(){
	cout << "you are in " << type << posi_rank << posi_file << "\nchoose where to go" << endl;
	for (int i = 0; i < MAXPOSI; i++){
		if (nearpt[i]) cout << "door" << i << endl;
	}
}

class lobbyRoom : public Room{
public:
	lobbyRoom(const int rank, const int file): Room(rank, file), type("Lobby"){printf("rank%dfile%d", posi_rank, posi_file);}
private:
	string type;
};

class prinRoom : public Room{
public:
	prinRoom(const int rank, const int file): Room(rank, file), type("Princess Room "){}
private:
	string type;
};

class monsRoom : public Room{
public:
	monsRoom(const int rank, const int file): Room(rank, file), type("Monster Room"){}
private:
	string type;
};

class wallRoom : public Room{
public:
	wallRoom(const int rank, const int file): Room(rank, file), type("Wall Room"){}
private:
	string type;
};

