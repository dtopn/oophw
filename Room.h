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
    void set_type(string type);
	Room* get_near(int posi);
    void replace(Room *rppt, Room *now);
private:
protected:
    Room *nearpt[MAXPOSI];//max 7 adjacent rooms
	//regard 0 as left 1 as right 2 as up 3 as down
	//more directions to be added
	int posi_rank, posi_file; 
	//TODO constrcutor nearpt[]= {0 0 0 0 0 0 0}
    string type;
};

class replaceRoom: public Room{
public:
    replaceRoom(const int rank, const int file): Room(rank, file){};
    //TODO ASK QUES?
    void replace();
};

class lobbyRoom : public replaceRoom{
public:
    using replaceRoom::replace;
	lobbyRoom(const int rank, const int file): replaceRoom(rank, file){set_type("Lobby");}
    void messg();
private:
	string type;
};

class prinRoom : public replaceRoom{
public:
    prinRoom(const int rank, const int file): replaceRoom(rank, file){set_type("Princess Room");}
private:
	string type;
};

class monsRoom : public replaceRoom{
public:
	monsRoom(const int rank, const int file): replaceRoom(rank, file){set_type("Monster Room");}
private:
	string type;
};

class wallRoom : public replaceRoom{
public:
	wallRoom(const int rank, const int file): replaceRoom(rank, file), type("Wall Room"){}
private:
	string type;
};
