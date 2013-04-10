#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#define MAXPOSI 7

#include "Room.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;


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
	for(int i = 0; i < rank; i++ ){
        pt = pt->get_near(3);
	}
    for (int j = 0; j < file; j++){
        pt = pt->get_near(1);
    }
	return pt;
}

Room* go_room(Room* nowpt, int direction){
	return nowpt->get_near(direction);
}


int main(int argc, char* argv[])
{
    cout << "Enter ranks>3 files>3 you want to play" << endl;
    cin >> sett.rank[0] >> sett.file[0];
    
    //C++ 11 #include <random>
    //And replace rand() with distribution(generator)
	//std::default_random_engine generator;
	//std::uniform_int_distribution<int> distribution(1,time(0));
	//int dice_roll = distribution(generator);
    
    srand ((int) time(NULL)); //concede for legacy compiler
	while(sett.file[1] == 0 && sett.rank[1] == 0)
		sett.file[1] = rand() % sett.file[0];sett.rank[1] = rand() % sett.rank[0];
	while((sett.file[2] == sett.file[1] && sett.rank[2] == sett.rank[1])
          || (sett.file[2] == 0 && sett.rank[2] == 0))
		sett.file[2] = rand() % sett.file[0];sett.rank[2] = rand() % sett.rank[0];
    
    Room *nowpt = sett.lobby = createLabyrinth(sett.rank[0], sett.file[0]);
    sett.lobby = new lobbyRoom(0, 0);
    sett.lobby->replace(nowpt, sett.lobby);
    sett.monsroom = new monsRoom(sett.rank[1], sett.file[1]);
    sett.monsroom->replace(go_room(sett.rank[1], sett.file[1]), sett.monsroom);
    sett.prinroom = new prinRoom(sett.rank[2], sett.file[2]);
    sett.prinroom->replace(go_room(sett.rank[2], sett.file[2]), sett.prinroom);
    //sett.prinroom->replace();

    sett.foundprin = sett.gameover = sett.success = 0;
    
    nowpt = sett.lobby;
    nowpt->messg();
	while(sett.gameover == 0){
		cout << "Choose a door\n";
        int buff; cin >> buff;
        nowpt = go_room(nowpt, buff);
        if (nowpt == sett.prinroom) sett.foundprin = 1;
        if (nowpt == sett.monsroom) sett.gameover  = 1;
        if ((nowpt == sett.lobby) && sett.foundprin) sett.gameover = sett.success = 1;
        nowpt->messg();
	}
	if (sett.success == 1) {
        cout << "Princess is saved, and live with her white horse prince happily forever. How are about you my poor son? You've got nothing, go back to lab and brush your test tube." << endl;
    }
    else{
        cout << "Dumbass, you failed, how impotent you are." << endl;
    }
	return 0;
}



