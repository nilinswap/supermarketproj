
class Itemgroup : public Item{
	public:
	    int num;
		Itemgroup(Item tem, int number=1) : Item(tem){ num=number;}
		Itemgroup():Item(){num=0;}
	    int find_num();
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

 int  Itemgroup::find_num(){
	return num;
}
