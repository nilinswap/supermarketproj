
class Itemgroup : public Item{
	public:
		unsigned int num;
		Itemgroup(Item tem,unsigned int number=1) : Item(tem){ num=number;}
		Itemgroup():Item(){num=0;}
		unsigned int find_num();
		double find_grpprice();
		double find_grpwt();
		void printwhole();

};
void Itemgroup::printwhole(){
		Item::printwhole();
		cout<<num<<endl;
	}
double Itemgroup::find_grpprice(){
	return num*cp;
}
double Itemgroup::find_grpwt(){
	return num*wt;
}

unsigned int  Itemgroup::find_num(){
	return num;
}
