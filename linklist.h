//#include"node.h"
#include"node.cpp"
template <class T>
class Linklist{
	Node<T>* start;
	public:
		Linklist();
//		void insertBeg(int);
//		void insertEnd(int);
		void insertPos(T&,int);
//		void deleteBeg();
//		void deleteEnd();
		void deletePos(int);
//		void deleteByData(int);
		void display();
		//search player
		Node<T>* searchPlayer(int);
		//Update Player
		bool updatePlayer(int);
		//MaxRuns 
		Node<T>* maxRuns();
		//MaxWickets
		Node<T>* maxWickets();
		//TopTwoRuns
		void topTwoRuns();
		//TopTwoWickets
		void topTwoWickets();
		//Destructor
		~Linklist();
};
