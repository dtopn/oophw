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

