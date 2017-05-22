

template <class T>
void resize(T **arr,int size,int newSize) {
    
    T* newArr = new T[newSize];

    memcpy( newArr, *arr, size * sizeof(T) );

    
    delete [] *arr;
    *arr = newArr;
}
class List{
	public:
		 int numofgrps;
		Itemgroup *grpar;
		List(){
			numofgrps=0;
			grpar=NULL;
		}
		void listadd(Itemgroup grp);
		void listremove_at_index(int ind);
		void listedit_at_index(int ind,int num);

};
void List::listadd(Itemgroup grp){
	resize <Itemgroup>(&grpar,numofgrps,numofgrps+1);
	if(not grpar)
	{ cout<<"locked up ... they won't let me out\n";
		return ;
	}
	numofgrps++;
	grpar[numofgrps-1]=grp;

		

}
void List::listedit_at_index(int ind, int number){
	grpar[ind].num=number;
	}
void List::listremove_at_index(int ind){
	listedit_at_index( ind,0);
}

