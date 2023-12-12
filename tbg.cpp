#include <Windows.h>
#include <iostream>
using namespace std;


//function declarations
int monstergen();
void BattleSystem();
void shop();
void NPC();
void pockets();
void Bossbattle(); 

//global variables
string inventory[10];
int potatos = 100;
int playerhealth = 100;

int main() {

	//setting each slot equal to " "
	for (int i = 0; i < 10; i++)
		inventory[i] = " ";
	cout << "you wake up tied to a chair at a large table " << endl;
	cout << "you can't remember how you got there or what your doing there at all" << endl;
	cout << "you stand up out of the chair because whoever tied you up did a vary poor job" << endl;
	cout << "you look around the room and see some doors" << endl;

	//local variables to main
	int room = 0;
	char input = 'a';
	bool hasWon = false;
	bool chest1 = false;
	bool chest2 = false;

	while (hasWon == false && input != 'q' && playerhealth >0) { //game loop ---------------------------------------------------------

		cout << "your inventory:" << endl;
		for (int i = 0; i < 10; i++)
			cout << inventory[i] << " ";
		cout << endl;

		switch (room) {
		case 0:
			Beep(523, 500);
			cout << "you are in the dining room (n)orth or (s)outh" << endl;
			if (inventory[0] != "key")
				cout << "you see a shiny (k)ey on the other side of the table" << endl;
			cin >> input;
			if (input == 'n' || input == 'N')
				room = 1;
			else if (input == 's' || input == 'S')
				room = 2;
			else if (input == 'k' || input == 'K')
				inventory[0] = "key";
			else if (input == 'c')
				room = 17;
         	else
				cout << "na man try somthin else" << endl;
			break;
		case 1:
			system("color F2");
			cout << "you are in a bedroom its old and dusty (e)ast or (s)outh" << endl;
			cin >> input;
			if (input == 's' || input == 'S')
				room = 0;
			if (input == 'e' || input == 'E')
				if (inventory[0] == "key") {
					cout << "you unlocked the door with the key" << endl;
					inventory[0] = " ";
					room = 3;
				}
				else
					cout << "the door is locked" << endl;
			break;
		case 2:
			BattleSystem();
			system("color 1B");
			cout << "you are in kitchen there is pots and pans all over the place (n)orth or (e)ast" << endl;
			cout << "there's a (c)hest in the corner" << endl;
			cin >> input;
			if (input == 'n' || input == 'N')
				room = 0;
			else if (input == 'e' || input == 'E')
				room = 4;
			else if (input == 'c' || input == 'C') {
				if (chest1 == false) {
					inventory[8] = "garbage!";
					cout << "you got some garbage, yay!" << endl;
					chest1 = true;
				}
				else {
					cout << "the chest is empty, sorry" << endl;
				}
			}

			else
				cout << "no no no no" << endl;
			break;
		case 3:
			cout << "you are in a mess of a room" << endl;
			cout << "it kinda looks like a party gone wrong with chairs all over the floor and confetti everywhere" << endl;
			cout << "you can go (e)ast or (w)est" << endl;
			cout << "there is also a guy in the corner with a sigh that seys sho(p)" << endl;
			cout << "you can (t)alk to the shop guy if youd like" << endl; 
			cin >> input;
			if (input == 'e' || input == 'E')
				room = 5;
			else if (input == 'w' || input == 'W')
				room = 1;
			else if (input == 'p' || input == 'P')
				shop();
			else if (input == 't')
				NPC();
			else
				cout << "no sir e thats not and option " << endl;
			break;
		case 4:
			cout << "the room looks like a forest with a door just standing in the middle of it" << endl;
			cout << "that makes no sense!" << endl;
			cout << "you can go (n)orth or (w)est" << endl;
			cin >> input;
			if (input == 'n' || input == 'N')
				room = 6;
			else if (input == 'w' || input == 'W')
				room = 2;
			else
				cout << "i dont think so bub" << endl;
			break;
		case 6:
			system("color 8E");
			cout << "you are in a white room with nothing but a party hat sitting in the middal of the room" << endl;
			cout << "you can go (e)ast or (s)outh" << endl;
			cin >> input;
			if (input == 'e' || input == 'E')
				room = 7;
			else if (input == 's' || input == 'S')
				room = 4;
			else
				cout << "not ganna happen bud sorry" << endl;
			break;
		case 7:
			cout << "you are in a room with a small model of what you assume is the house you are in right now" << endl;
			cout << "it is really well done it must have taken ages" << endl;
			cout << "also if it is the house you are in then dang! this is a big house" << endl;
			cout << "you can go (e)ast or (w)est" << endl;
			cin >> input;
			if (input == 'e' || input == 'E')
				room = 8;
			else if (input == 'w' || input == 'W')
				room = 6;
			else
				cout << "no way man" << endl;
			break;
		case 5:
			system("color 1B");
			cout << "you are in a room that seems to be made of cardboard and held together with scotch tape" << endl;
			cout << "even the doors are made out of cardboard" << endl;
			cout << "you can go (e)ast or (w)est or (n)orth" << endl;
			cin >> input;
			if (input == 'e' || input == 'E')
				room = 9;
			else if (input == 'n' || input == 'N')
				room = 10;
			else if (input == 'w' || input == 'W')
				if (inventory[0] == "key") {
					cout << "you unlocked the door with the key" << endl;
					inventory[0] = " ";
					room = 3;

				}
				else
					cout << "the door is locked" << endl;
			break;
		case 8:
			cout << "the room is dark and only lit by candals there is a skylight it seems to be raining outside" << endl;
			cout << "the room is bilt from old gray wood and looks a lot older than the rest of the house" << endl;
			cout << "you can go (n)orth  (w)est  (s)outh or (e)ast man so many choices" << endl;
			
			cin >> input;
			if (input == 'n' || input == 'N')
				room = 9;
			else if (input == 'w' || input == 'W')
				room = 7;
			else if (input == 's' || input == 'S')
				room = 11;
			else if (input == 'e' || input == 'E')
				room = 16;
			else 
				cout << "hay pal thats not an option" << endl;
			break;
		case 9:
			cout << "you are in a room with a tone of cats on the floor and dogs somehow on the ceiling" << endl;
			cout << "you would think that it would be a cute overload but actually they wont stop meowing and barking and its really annoying" << endl;
			cout << "you can go (s)outh or (w)est" << endl;
			cin >> input;
			if (input == 's' || input == 'S')
				room = 8;
			else if (input == 'w' || input == 'W')
				room = 5;
			else
				cout << "no just ... no" << endl;
			break;
		case 11:
			system("color F2");
			cout << "AAAAAAAAAAAAAAAAAAAAHHH" << endl;
			cout << "you step out of the door and all hell breaks loose" << endl;
			cout << "the room itself has somehow become the middle section of a highway" << endl;
			cout << "you are standing on the Median barriers to avoid the oncoming traffic and you scream THIS PLACE SUCKS!!! as you spit on one of the passing cars in anger" << endl;
			cout << "before he is completely gone you see the random drivers face he looks unamused you see a door in the distance" << endl;
			cout << "you can run (s)outh or (n)orth" << endl;
			cin >> input;
			if (input == 'n' || input == 'N')
				room = 8;
			else if (input == 's' || input == 'S')
				room = 12;
			else
				cout << "nu uh" << endl;
			break;
		case 12:
			cout << "you are in... outer space?" << endl;
			cout << "man this is getting kinda old" << endl;
			cout << "you can go (e)ast or (n)orth" << endl;
			cin >> input;
			if (input == 'n' || input == 'N')
				room = 11;
			else if (input == 'e' || input == 'E')
				if (inventory[3] == "room13key") {
					cout << "you unlocked the door with the key" << endl;
					inventory[3] = " ";
					room = 13;
				}
				else
					cout << "the door is locked" << endl;
			break;
		case 13:
			cout << "you are in a vary nice room like the room is literally sparkling it's kinda hurting your eyes" << endl;
			cout << "you see a glowing piece of broken (g)lass on the floor" << endl;
			cout << "there is also see a (b)edside table that lookes real fishy" << endl;
			cout << "you can go (w)est" << endl;
			cin >> input;
			if (input == 'w' || input == 'W')
				room = 12;
			if (input == 'g') {
				inventory[4] = "glass_shard";
				cout << "you got the glass shard" << endl;
			}

            else if (input == 'b' || input == 'B') {
				if (chest2 == false) {
					inventory[6] = "room15key";
					cout << "you got the room15key!" << endl;
					chest2 = true;
				}
				else {
					cout << "the chest is empty, sorry" << endl;
				}

			}
				cout << "cant do it wont do it " << endl;
			break;
		case 10:
			cout << "hay this room actually looks norma- oh wait no nevermind half of the room is covered in frogs " << endl;
			cout << "you can go (s)outh or (e)ast" << endl;
			cin >> input;
			if (input == 's' || input == 'S')
				room = 5;
			else if (input == 'e' || input == 'E')
				room = 14;
			else
				cout << "NOPE" << endl;
		case 14:
			cout << "you are in room 14 you can go (w)est or (n)orth" << endl;
			cin >> input;
			if (input == 'w' || input == 'W')
				room = 10;
			else if (input == 'n' || input == 'N')
				if (inventory[6] == "room15key") {
					cout << "you unlocked the door with the key" << endl;
					inventory[6] = " ";
					room = 15;
				}
				else
					cout << "the door is locked" << endl;
			   break;
		case 15:
			cout << "you are in a room wraped in tin foil" << endl;
			cout << "there is another piece of g(l)ass on the ground" << endl;
			cout << "and a (k)ey" << endl; 
			cout << "you can go (s)outh" << endl;
			cin >> input;
			if (input == 's' || input == 'S')
				room = 14;
			if (input == 'l') {
				inventory[5] = "glass_shard2";
				cout << "you got the glass shard" << endl;
			}
            else if (input == 'k') {
				inventory[7] = "room16key";
				cout << "you got the room16key" << endl;
		    }
            else
				cout << "thats not ganna work on me pal" << endl;
			break;
		case 16:
			Bossbattle();   
			if (playerhealth < 0)
				cout << "you suck" << endl;
			else {
				cout << "you did it you beat pockets and used the orb to repear the house by useing the shards you got in the other rooms" << endl; 
				cout << "don't worry you didint kill pockets he's just passed out on the floor" << endl; 
				cout << "i guess he really was bad at being a villan" << endl;
				cout << "you leave the house and laugh about the entire ordeal" << endl; 
				cout << "the end" << endl;
				hasWon = true;
			}
			break;
		case 17:
			cout << "well would you look at that you made it to the secret room" << endl;
			cout << "have a spooky cat pic" << endl;
			cout << "-----:-====----------:..............................:::..........:::::--::::.....:::::::::--=-----=+" << endl;
			cout << "-::::::::-----------:::...+*++-:...................................:----=+=-::....::::....::=*+----=" << endl;
			cout << "::::::::::::---::::::::::-*+==++-.........:::::----::....:..........-++=++*#=::.....:---:::::===--::" << endl;
			cout << "::::::::::::::::::::::.:::#+-==+++-::---==+==#=-++=-+*=++===---:::=+++===+*#:::::::..::::::::-=*++--" << endl; 
			cout << "::::::::::::..::::::::::::==--=+++=--:-=**-:-+*=*++++---+#+=::-=--=======+#=:..:::::::..::::::=++**+" << endl; 
			cout << "--:::::::....:::::::::..:.:+--==--=+=::=#+---++++++-=---=*#-:-=+=----=++=+=::::::-::---:::::::-=+++*" << endl;
			cout << "::::::::::::........::.....-=------+*+=-+===++==++==**+=+*+==++=-:----==++..:::...::---------::=-==+" << endl;
			cout << "--:::::::::.:........::::.::----=#@@@@@@#=-:-+==++++*=--=+%@%%%@%*=----==.......:.::::-----==-======" << endl; 
			cout << "%#+-::-:::::::............::-==+%*-:-=+#%%-::+-===++*-:-#@%#+++=+%%+=---:....:.::::::::-----=====++=" << endl;
			cout << "+++==++-:-:::::+=+:......:---==*=-=+**#++#=::---==---::=%**++*##==*#*+==--:...:::...::::::::::----=+" << endl; 
			cout << "#%%**=+=-=====*@%=.....:-+*#+--+-=%@@@%+-**+++==---=+++##**%@@@%+-=#=+*+**=-::::......:::::::::::---" << endl; 
			cout << "*####*=---==++%@*::.:.:-+=--::=#=-*%@%+=+#++*===--=+**+*%+=*%@@#+=*#=::--=*=:...:......:::::::::::-:" << endl; 
			cout << "****#@%@%*+*##@%=--::::===-=-::=#*-==-=+=-=+#+=====+*#*+==+---=+=#*-:--===**-............::::-::::::" << endl; 
			cout << "=-=+++*%@@@#@@@#=--====+===+++=--------:::-##%%****@%%#-:::--=-----====++++#+:............::...:::::" << endl;
			cout << "#*+--=+++++***#%#*=-#=+=-=+=++====-++=+-:..::=%#%###+-::.:-=-----==++****+=+*-................::::::" << endl;
			cout << "+#**+=---=*++***===--==--+*+==++=::::---::::::=%@%+:::::::-*+*+=-==+++++====+-............::::::::::" << endl;
			cout << "##@%**++=----=+#%#====----+++++-:-=*++--::::--+%@#+----::--==-::---=+**#*+==+:................::::::" << endl; 
			cout << "#@@@%******+=--==++====-=+###*-::::-===---===+#%@%#+===----==**+-::=+*#%#*==-:........-::::-::::::::" << endl; 
			cout << "####*******++++=----=---=*%%#*+--+++-----==+*#%@@@%#++====++=---==-==+*###*+:........:-:::+-::::::::" << endl;
			cout << "**++**+++=+===++*+==-:--+#*+**+=::-++*++++*#@@@@@@@@@#*+++==+**=:-=+=**=+*#+--:-=+====--:-=:.:::::::" << endl; 
			cout << "####*********++++=+++++--=*#-=+#**--+=++*#@@@@@@@@@@@@@#**+*=-==++-+**++**=::----:..:===+=---:::::=%" << endl; 
			cout << "##***+*+++++***+**++++++==-=**##*-=*+#*%@@@@@@%@@@@@%%@%%#**+*-++**+-*#*+-+***+=++--+++++-----=+*%%*" << endl;
			cout << "###*****##****+++++++++-===+*##+-+*+**#@@@@@@%%%@@@%%#%@@%@@#++-*+***=-++===#%#%*=======-----=#@@@@@" << endl; 
			cout << "######****++++++**+++-=++==+=+==***+++*#@@@%*###%%%%%##@@%%%+++==+****==-====-=========*++===+#@@@@%" << endl;
			cout << "%######**+++*++***+==+++==++=-=+*#**+=+*%@%%**###%###*#%%%%*+==+-++*++++=--====-=======++**#*#@@%%%#" << endl;
			cout << "##***************+***++**++-+=--=*#**+=+%@%*=*+*###**+=#%%%+=++*==*****+=---=======+++++++++*%%%*#%@" << endl;
			cout << "###***++*******+***+***+++=+==--=+****+=+%@%++=*###*++*%@%+=+***#*+*##*+==---==+++=++++++++%%%%****#" << endl;
			cout << "%%%%%##*****************=++*+==--+*####*+*%@@@%%%%@@%%@%%**##%%%#*###*+++=-=====++++++++**%#%%***#@@" << endl; 
			cout << "%%%%%###*###*****+****==+***=-====**#%%###*++**#%%%##*++#%%%@%%%%#%***+*+=++=+++++++++**********#%@@" << endl;
			cout << "%%%######**##**********+++**+--*#+++**#%%####+++*+++=+#%%@%%%%%@%*#*****+##=--===++*********####%@@#" << endl; 
			cout << "%#%%##%%###*****+**+********===+*%%#+**###%#%%%#####%%%%%%%%%%###*#**#*#%%+===++=----==+**####%@@%%#" << endl;
			cout << "%%%#####%%%%#*************+=--=*#%%%%****##%####%%%%%%%%%%#%###***#*##%@%***+=--=+****#*+=====+*####" << endl; 
			cout << "%%%%###########**#********=--=*#%#***********#*##%%%%%%%#####*####%#%@@%###*+=====+****####***++++++" << endl;
			cout << "%%%%%%%%%#*#######%##***+=-=-=*%#***#####*#****##############*****##@@@%@%##*++==++*###############%" << endl; 
			cout << "%%%%%%%%%%####%%%%%%%#+-====+*##########*#%################%%%##########%%##***++==+*#####%%%%%%%%%%" << endl; 
			cout << "its a bit messed up sorry " << endl;
			cout << "once you leave the room you will teliported to the final room" << endl; 
				
			cin >> input;
			if (input == 'e' || input == 'E')
				room = 16;
			else
				cout << "thats not ganna work on me pal" << endl;








		}
		if (hasWon == true) {
			cout << "win" << endl;
		}

	}

}


void shop() {
	int input;
	cout << "-----------------------------------------------" << endl;
	cout << "hello there welcome to the shop" << endl;
	cout << "items for sale:" << endl;
	cout << "1) cupcake 5$" << endl;
	cout << "2) sock 20$" << endl;
	cout << "3) room 13 key 90$" << endl;

	cout << "your inventory" << endl;
	for (int i = 0; i < 10; i++)
		cout << inventory[i] << " ";
	cout << endl << endl;
	cout << "-----------------------------------------------" << endl;
	cout << "whould you like to buy somthin" << endl;

	cin >> input;
	if (input == 1) {
		
		if (potatos >= 5) {
			cout << "good choice. here's the cupcake." << endl;
			inventory[1] = "cupcake";
			potatos -= 5;
		}
		else {
			cout << "sorry, you don't have enough potatoes!" << endl;
		}
	}
	else if (input == 2) {

		if (potatos >= 20) {
			cout << "you bought the sock" << endl;
			inventory[2] = "sock";
			potatos -= 20; 
		}
		else {
			cout << "sorry, you dont have the funds bud" << endl;
		}
		
	}
	else if (input == 3) {

		if (potatos >= 90) {
			cout << "you bought the sock" << endl;
			inventory[3] = "room13key";
			potatos -= 90;
		}
		else {
			cout << "sorry, you dont have the funds bud" << endl;
		}

	}
	


}

void BattleSystem() {
	int monster = monstergen();
	int monsterhealth = 20;
	int monsterdmg;
	int playerdmg;

	if (monster == 10) {
		monsterhealth = 20;
		monsterdmg = rand() % 20 + 10;
	}
	else if  (monster == 15) {
		monsterhealth = 35;
		monsterdmg = rand() % 30 + 20;
	}
	else if (monster == 12) {
		monsterhealth = 35;
		monsterdmg = rand() % 30 + 20;
	}
	else if (monster == 15) {
		monsterhealth = 35;
		monsterdmg = rand() % 30 + 20;
	}
	else if (monster == 0) {
		monsterhealth = 0;
		monsterdmg = 0;
	}

	int num;
	cout << "-------------------------------------------------------------------" << endl;
	while (playerhealth > 0 && monsterhealth > 0) {

		if (monster == 10) { //chair
			monsterhealth = 20;
			monsterdmg = rand() % 20 + 10;
		}
		else if (monster == 15) { //tea kettle
			monsterhealth = 35;
			monsterdmg = rand() % 30 + 20;
		}
		else
			monsterdmg = rand() % 10; //bear


		playerhealth -= monsterdmg;
		cout << endl << endl << "the monster bites you for " << monsterdmg << " damage." << endl;
		
		//player fights back
		playerdmg = rand() % 50 + 50;
		
		monsterhealth -= playerdmg;
		cout << "you hit the monster for " << playerdmg << " damage." << endl;
		cout << "your health is " << playerhealth << ", and the monsters health is " << monsterhealth << endl;
		system("pause");
	}
	cout << "--------------------------------------------------------------------------" << endl;
}

void Bossbattle() {
	int bosshealth = 20; 
	int num;
	pockets();
	cout << "-------------------------------------------------------------------" << endl;
	while (playerhealth > 0 && bosshealth > 0) {

		num = rand() % 10;
		playerhealth -= num;
		cout << endl << endl << "pockets stabs you for " << num << " damage." << endl;

		num = rand() % 10 + 10;
		bosshealth -= num;
		cout << "you hit pockets for"<< num <<"damage" << endl;
		cout << "your health is"<< playerhealth << ", and pockets health is"<< bosshealth << endl;

		system("pause");
	}
	cout << "--------------------------------------------------------------------------" << endl;
}


int monstergen() {
	int num = rand() % 100;
	if (num < 30) {
		cout << "a Stickley Brothers Signed Antique Maple Windsor Chair With Seat and Back Cushions appears" << endl;
		return 10;

	}
	else if (num < 50) {
		cout << "a antique miniature brass vintage indian 1960s tea kettle attacks" << endl;
		return 15;

	}
	else if (num < 50) {
		cout << "a teddy bear attacks" << endl;
		return 12;

	}
	else {
		cout << "no monsterz here" << endl;
		return 0;
	}
}

void NPC() {
	int input = 2354;
	while (input != 0) {
		cout << "1) hello?." << endl;
		cout << "2) ask where to go." << endl; 
		cout << "3) what is going on here?" << endl;
		cout << "4) what are you doing here why are you selling stuff?" << endl;
		cout << "5) what is your name how long have you been here?" << endl; 
		cout << "6) do you know how to stop whatever is happing here?" << endl; 
		cout << "7) why are the objects in the house trying to hurt me" << endl;
		cout << "enter (0) if you are done talking " << endl;
		cin >> input;
		switch (input)
		{
		case 1:
			cout << "hi how you doin" << endl;
			cout << "-----------------------------------------------------------------------" << endl;
			break;
		case 2:
			cout << " i dont know do i look like a map?" << endl;
			cout << "-----------------------------------------------------------------------" << endl;
			break;
		case 3:
			cout << "some guy came and used some magic orb thingy on the house messing it all up changing the rooms and stuff" << endl;
			cout << "i think he sed his name was pockets what a stupid name i mean the guy could have picked anything and he chose THAT!!" << endl; 
			cout << " geez talk about crazy" << endl; 
			cout << "-----------------------------------------------------------------------" << endl;
			break;
		case 4:
			cout << "first of all this is my house second i dont know why i am selling stuff i just got a weird urge all of the suddien i think that orb messed my head up" << endl;
			cout << "eather that or the maker of this game is trying to find a sloppy reason for having a shop" << endl; 
			cout << "-----------------------------------------------------------------------" << endl;
			break;
		case 5:
			cout << "my name is velly i think i cant really remember things have been pretty twisted and strange ever since that guy got here" << endl; 
			cout << "i have been here for like 3 hours... i think" << endl;
			cout << "-----------------------------------------------------------------------" << endl;
			break;
		case 6:
			cout << "not really no" << endl;
			break;
		case 7:
			cout << "i think that they are posesed by magic or something like that" << endl;
			cout << "lets just go with that because i cant really think of anything else right now" << endl;
			cout << "----------------------------------------------------------------------------------" << endl;
			break;
		}
         
	}

}

void pockets() {
	int input = 2354;
	while (input != 0) {
		cout << "1) you did all this!?" << endl;
		cout << "2) what is wrong with you?" << endl;
		cout << "3)what did you do to this place?" << endl;
		cout << "4) you are really bad at being a villan!" << endl;
		cout << "5)why did you tie me up at a table?" << endl;
		cout << "6) why this house?" << endl;
		cout << "-------------------------------------------------------------------------" << endl; 
		cout << "enter (0) if you are ready to fight the one and only pockets" << endl;
		cin >> input;
		switch (input)
		{
		case 1:
			cout << "yep i sure did! :D" << endl;
			cout << "-----------------------------------------------------------------------" << endl; 
			break;
		case 2:
			cout << "nothing is wrong with me jerk whats wrong with you!? >:(" << endl;
			cout << "----------------------------------------------------------------------------------------------" << endl; 
			break;
		case 3:
			cout << "nothing mutch i just used a ancient orb artifact from a 1000 year old wizard called stardust the great to change the" << endl;
			cout << "entirety of the house and morph it into madness :)" << endl;
			cout << "------------------------------------------------------------------------------------------------------" << endl; 
			break;
		case 4:
			cout << "what...no im not how rude of you >:O" << endl;
			cout << "nevertheless i will snuff you out soon Enough punk x-x" << endl;
			cout << "---------------------------------------------------------------------------" << endl; 
			break;
		case 5:
			cout << "oh yah that i forgot about that well i was going to have a celebratory dinner party to celebrate my great plan but i got distracted and forgot...heh well i guess i can still have a dinner party" << endl;
			cout << "AFTER I KILL YOU!!! muh ah ah ah >:D" << endl;
			cout << "evil bad guy noises" << endl;
			cout << "----------------------------------------------------------------------" << endl;
			break;
		case 6:
			cout << "that is a good question i chose this house BECAUSE" << endl;
			cout << "BIG REVEAL INCOMING!!!!!!!!!!!!!!!!!!!!!!!!!!!!! :O" << endl;
			cout << "THIS IS MY FATHERS HOUSE" << endl; 
			cout << "BUM BUM!! BUUUUUUUUMMM!!!!!" << endl;
			cout << "ok so mabey not that big of a reveal :/" << endl;
			cout << "you might have met him already for some reason hes acting like a loony selling stuff somewhere around here like some" << endl;
			cout << "kind of shop keeper or somthing" << endl;
			cout << "i dont think he remembers anything from the past twentyfour hours" << endl;
			cout << "------------------------------------------------------------------------------------------------------------------" << endl; 
			break;
		}

	}

}
