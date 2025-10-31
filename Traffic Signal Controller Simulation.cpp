#include<iostream>
#include<unistd.h>
using namespace std;
void redLight(int seconds)
{
	cout<<"Red Light ON - STOP"<<endl;
	for(int i=seconds; i>0; i--)
	{
		cout<<"Time remaining: "<<i<<" seconds"<<endl;
		sleep(1);
		
	}
}
void yellowLight(int seconds){
	cout<<"Yellow Light ON - GET READY"<<endl;
	for(int i=seconds; i>0; i--)
	{
		cout<<"Time Remaining: "<<i<<" seconds"<<endl;
		sleep(1);
	}
}
void greenLight(int seconds){
	cout<<"Green Light ON - GO"<<endl;
	
	for(int i=seconds; i>0; i--){
		cout<<"Time Remaining: "<<i<<" seconds"<<endl;
		sleep(1);
	}
}


int main()
{
	while(true){
		redLight(5);
		greenLight(2);
		yellowLight(5);
		cout<<"----------------------------------------"<<endl;
	}
	return 0;
}
