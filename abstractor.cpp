#include <iostream>
using namespace std;

class LandAnimal {

public:
   public:
	virtual void legs() =0;
	virtual void avg_age() =0;
	void blood_color()
	{
		cout<<"Found to be RBC+WBC\n";
	}
	virtual ~LandAnimal() {};
};

class Human: public LandAnimal {

	public:
	void legs() {
		cout<<"Two legs\n";
	}
	void avg_age(){
		cout <<"55 or 75\n";
	}
	void cunning() {
		cout<<"ohhhhhh, am cunning";
	}
};

class Elephant: public LandAnimal {

	public:
	void legs() {
		cout<<"four legs\n";
	}
	void avg_age(){
		cout <<"african 65 or 75\n";
	}
};

class Robot {
	public:
	virtual void retena_profile_scanner() = 0;
	virtual void command_to_action() = 0;
};
class Cyborg: public Human, public Robot
{
	public:
	void retena_profile_scanner() {
		cout<<"Scanning suspects profile\n";
	}
	void command_to_action()
	{
		cout<<"Waiting for command to bash.... \n";
	}
	void avg_age(){
		cout <<"3 days untile recharge\n";
	}
	void blood_color()
	{
		cout<<"Holy used green placide to show coolent for body temp\n";
	}

};
void encyclo(LandAnimal *ola)
{
	ola->legs();
	ola->avg_age();
	ola->blood_color();
        if (typeid(*ola) == typeid(Human)){
		cout<<"Found Humans in system\n";
		Human *hu = dynamic_cast<Human *>(ola);
		if (hu) hu->cunning();
	}
        if (typeid(*ola) == typeid(Cyborg)){
		cout<<"Found Cyborg in system\n";
		Cyborg *hu = dynamic_cast<Cyborg*>(ola);
		if (hu) hu->retena_profile_scanner();
	}	
}

void encyclo_demo()
{
	while(1)
	{
	int ch=0;
	LandAnimal *la;
	cout<<"Enter ch value...1. Human, ...2. Elephan.\n";
	cin >> ch;
		switch(ch)
		{
			case 1:
			la = new Human;
			encyclo(la);
			delete la;
			break;
			case 2:
			la = new Elephant;
			encyclo(la);
			break;
			case 3:
			la = new Cyborg;
			encyclo(la);
			break;
		}

	}

}

int main()
{

	encyclo_demo();
}
