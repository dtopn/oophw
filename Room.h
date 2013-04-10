#include <iostream>
#include <string>

#define MAXPOSI 7

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Room{
public:
	Room(const int rank, const int file):posi_rank(rank), posi_file(file){printf("rank%dfile%d", posi_rank, posi_file);}
	//TODO assert(file >=2);
	void set_near(Room *pt, int posi);
	void messg();
	Room* get_near(int posi);
    void set_type();
private:
	Room *nearpt[MAXPOSI];//max 7 adjacent rooms
	//regard 0 as left 1 as right 2 as up 3 as down
	//more directions to be added 
	string type;
protected:
	int posi_rank, posi_file; 
	//TODO constrcutor nearpt[]= {0 0 0 0 0 0 0} 
};

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
