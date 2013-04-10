#include "Room.h"

void Room::set_near(Room *pt, int posi){
    nearpt[posi] = pt;
}

Room* Room::get_near(int posi){
	return nearpt[posi];
}

void Room::messg(){
	cout << "In room " << posi_rank << posi_file << type << "\nChoose where to go" << endl;
	for (int i = 0; i < MAXPOSI; i++){
		if (nearpt[i]) cout << "door" << i << endl;
	}
}

void Room::set_type(std::__1::string a){
    type = a;
}

void Room::replace(Room *rppt, Room *now){
    if (rppt->nearpt[0]) nearpt[0] = rppt->nearpt[0], rppt->get_near(0)->nearpt[1] = now;
    if (rppt->nearpt[1]) nearpt[1] = rppt->nearpt[1], rppt->get_near(1)->nearpt[0] = now;
    if (rppt->nearpt[2]) nearpt[2] = rppt->nearpt[2], rppt->get_near(2)->nearpt[3] = now;
    if (rppt->nearpt[3]) nearpt[3] = rppt->nearpt[3], rppt->get_near(3)->nearpt[2] = now;
    delete rppt;
}
