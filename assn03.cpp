#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <algorithm>

#define MAXPOSI 7

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Room{
public:
	Room(const int rank, const int file):posi_rank(rank), posi_file(file), type("normal room"){printf("rank%dfile%d", posi_rank, posi_file);}
	//TODO assert(file >=2);
	void set_near(Room *pt, int posi);
	void messg();
	Room* get_near(int posi);
private:
	Room *nearpt[MAXPOSI];//max 7 adjacent rooms
	//regard 0 as left 1 as right 2 as up 3 as down
	//more directions to be added 
	string type;
protected:
	int posi_rank, posi_file; 
	//TODO constrcutor nearpt[]= {0 0 0 0 0 0 0} 
};

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

Room* createLabyrinth(int rank, int file){
	Room *nowpt, *lobbypt, *prvpt, *uppt;
	lobbypt = new lobbyRoom(0, 0);std::cout << "\n";
	prvpt = lobbypt;
	for(int i = 1; i < rank; i++ ){ // create first file
		nowpt = new Room(i, 0);
		nowpt->set_near(prvpt, 2);
		prvpt->set_near(nowpt, 3);
		prvpt = nowpt;
		//pt->set_up(
		//pt->set_right(
		//pt->set_down(
		std::cout << "\n"; //1st file ok
		//TODO change cursor posi
	}
		//change pt for rank
	prvpt = lobbypt;
    for (int j = 1; j < file; j++) {
        nowpt = new Room(0 ,j);
        nowpt->set_near(prvpt, 0);
		prvpt->set_near(nowpt, 1);
		prvpt = nowpt;
    }
    
	for(int i = 1; i < rank; i++ ){ // create by file first
		int down = i;
        uppt = lobbypt->get_near(1);
		while(--down) uppt->get_near(3);
        down = i;
        prvpt = lobbypt;
        while (down--) prvpt = prvpt->get_near(3);
		for (int j = 1; j < file; j++){
			nowpt = new Room(i, j);
			nowpt->set_near(prvpt, 0);prvpt->set_near(nowpt, 1);
//            if (j == 0   ) nowpt->set_near(0, 0);
//            if (j == rank) nowpt->set_near(0, 1);
//            if (i == 0   ) nowpt->set_near(0, 2);
//            if (i == rank) nowpt->set_near(0, 3);
            nowpt->set_near(uppt, 2);uppt->set_near(nowpt, 3);
            prvpt = prvpt->get_near(1);
			uppt = uppt->get_near(1);
			std::cout << "\n"; //1 rank ok
		}
		//change pt for rank
	}
	return lobbypt;
}

struct settings{
	int rank[3], file[3];//0 is size, 1 is monster, 2 is princess
	Room *lobby, *monsroom, *prinroom;
	bool gameover, success, foundprin;
}sett;

Room* go_room(int rank, int file){
	Room *pt = sett.lobby;
	for(int i = 0; i < rank; i++ ){ // create by file first
		for (int j = 0; j < file; j++){
			pt = pt->get_near(1);
		}
		pt = pt->get_near(3);
	}
	return pt;
}

Room* go_room(Room* nowpt, int direction){
	return nowpt->get_near(direction);
}

int main(int argc, char* argv[])
{
	sett.file[0] = sett.rank[0] = 3;


	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(1,time(0));
	int dice_roll = distribution(generator);
	while(sett.file[1] == 0 && sett.rank[1] == 0)
		sett.file[1] = distribution(generator) % sett.file[0];sett.rank[1] = distribution(generator) % sett.rank[0];
	while((sett.file[2] == sett.file[1] && sett.rank[2] == sett.rank[1]) 
					|| (sett.file[2] == 0 && sett.rank[2] == 0))
		sett.file[2] = distribution(generator) % sett.file[0];sett.rank[2] = distribution(generator) % sett.rank[0];


	Room *nowpt = sett.lobby = createLabyrinth(sett.rank[0], sett.file[0]);
    nowpt->messg();
	while(sett.gameover == 0){
		cout << "Choose a door\n";
        int buff; cin >> buff;
        nowpt = go_room(nowpt, buff);
        nowpt->messg();
	}
	if (sett.success == 0) {
        cout << "Princess is saved, and live with her white horse prince happily forever. How are about you my poor son? You've got nothing, go back to lab and brush your test tube." << endl;
    }
    else{
        cout << "Dumbass, you failed, how impotent you are." << endl;
    }
	return 0;
}


