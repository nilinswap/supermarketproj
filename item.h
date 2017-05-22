
#include <string>
using namespace std;
class Item{
	
	public:
		int id;
		string name;
		double cp;
		double sp;
		double wt;
		double dis;//discount if any
		Item(int id, string name,double cp, double sp, double wt, double dis=0){
			this->id=id;
			this->cp=cp;
			this->sp=sp;
			this->name=name;
			this->dis=dis;
			this->wt=wt;

		}	
		Item(){
			id=cp=sp=dis=wt=0;
			name="NULL";
		}
		double find_cp();
	    int find_id();
		string find_name();
		void printwhole();
		void addtodb();

};
void Item::printwhole(){
	cout<<id<<endl;
	cout<<name<<endl;
	cout<<cp<<endl;
	cout<<sp<<endl;
	cout<<wt<<endl;
	cout<<dis<<endl;
}
	
double Item::find_cp(){
	return cp;
}
 int  Item::find_id(){
	return id;
}
string Item::find_name(){
	return name;
}
void Item::addtodb(){
	//it will first open

}