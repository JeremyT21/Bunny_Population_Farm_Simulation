//3 questions where you have to modify pre-existing code - 5-6 points
//question 4 and 5 write all code yourself - 8-9 points
//understand vectors and pointers

#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <cstdlib>
#include <vector>

using namespace std;

class bunny{
	public:
		bunny(); //constructor is only method with no return data
		void incAge();
		int getAge();
		char getGender();
		string getName();
	
	private:
		char gender; //can be 'M' or 'F'
		int age; //from 1-10
		char color; //can be 'w' 'b' 'B' 's'
		string name;
		bool radioactive_mutant_vampire_bunny;
};

void bunny::incAge()
{
	this->age = (this->age)+1;
}

int bunny::getAge()
{
	return this->age;
}

char bunny::getGender()
{
	return this->gender;
}

string bunny::getName()
{
	return this->name;
}

bunny::bunny()
{
	int randNum = rand() % 2 + 1;
	if(randNum == 1)
		gender = 'M';
	else
		gender = 'F';
	
	age = rand() % 10 + 1;
	
	char colors[4] = {'w', 'b', 'B', 's'};
	randNum = ((rand() % 4 + 1) - 1);
	color = colors[randNum];
	
	string names[16] = {"Fred", "Jimmy", "Gibby", "Patty B.", "Semidoe", "Lutris", "Kayne", "Lula", "Marty", "Colt", "Jolyne", "Krungle", "Manton", "Sharugah", "Big Boy B. Bunny", "Humungo"};
	randNum = ((rand() % 16 + 1) - 1);
	name = names[randNum];
	
	randNum = rand() % 100 + 1;
	if(randNum <= 2)
		radioactive_mutant_vampire_bunny = true;
	else
		radioactive_mutant_vampire_bunny = false;
}

class Farm{
	public:
		Farm();
		void update();
		
	private:
		bunny b1;
		bunny b2;
		bunny b3;
		bunny b4;
		bunny b5;
		
		vector<bunny> vector_bunnies = {b1,b2,b3,b4,b5};
		vector<bunny>::iterator iter;
};

Farm::Farm()
{

}

void Farm::update()
{
	cout << endl << "-._.-._  A NEW BUNNY GENERATION BEGINS  -._.-._" << endl << endl;
	
	vector_bunnies = this->vector_bunnies;
	vector<bunny>::iterator iter;
	
	//checks Size
	if(vector_bunnies.size()>=20)
	{
		cout << "The half of bunnies with the most experience," << endl << "have become professional bunnies and left the farm!" << endl;
		
		iter = vector_bunnies.begin();
		
		for(int i=0; i<(vector_bunnies.size())/2; i++)
		{
			cout << "/    " << (*iter).getName() << " has left." << endl;
			
			vector_bunnies.erase(iter);
			iter++;
		}
		
		this->vector_bunnies = vector_bunnies;
		vector_bunnies = this->vector_bunnies;
	}
	
	//Male and female bunny numbers are checked
	int maleCount = 0;
	int femaleCount = 0;
	
	for(iter = vector_bunnies.begin(); iter != vector_bunnies.end(); iter++)
	{
		if(((*iter).getGender()) == 'M')
			maleCount++;
		
		else
			femaleCount++;
	}
	
	//New bunnies are added
	for(int i=0; i<(maleCount*femaleCount); i++)
	{
		bunny b_new;
		cout << "Welcome " << b_new.getName() << " to the farm!" << endl;
		
		vector_bunnies = this->vector_bunnies;
		vector_bunnies.push_back(b_new);
		this->vector_bunnies = vector_bunnies;
		vector_bunnies = this->vector_bunnies;
	}
	
	//Bunny growing information is displayed
	for(iter = vector_bunnies.begin(); iter != vector_bunnies.end(); iter++)
	{
		if(((*iter).getAge()) >= 10)
		{
			cout << "X    " << (*iter).getName() << " has died." << endl;
			vector_bunnies.erase(iter);
		}
		
		else
		{
			cout << "O    " << (*iter).getName() << " grew in age." << endl;
			(*iter).incAge();//use * since iter (an iterator) is a pointer
		}
	}
	
	this->vector_bunnies = vector_bunnies;
	cout << endl;
}


int main()
{
	Farm *f1 = new Farm();
	f1->update();
	f1->update();
	f1->update();
	
	return 0;
}