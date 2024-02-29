
class Player{
	
	int jersyno;
	char name[20];
	int runs;
	int wickets;
	int noofmatches;
	
	public:
	
	//Constructor
	
	Player();
	Player(int ,char* ,int ,int ,int );
	
	//setters
	
	void setJersyNo(int );
	void setName(char* );
	void setRuns(int );
	void setWickets(int );
	void setNoOfMatches(int );
	
	//getters---->
	
	int getJersyNo();
	char* getName();
	int getRuns();
	int getWickets();
	int getNoOfMatches();
	
	//Functions
	
	void display();
};
