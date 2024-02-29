#include<iostream>
using namespace std;
//#include"linklist.h"
#include"linklist.cpp"
//#include"player.h"

int main()
{
	Linklist<Player> l;
	
	Player p;
	
	int jersyNo;
	char name[20];
	int runs;
	int wickets;
	int noOfMatches;
	
	
	ifstream in("PlayersInfo.bin");
	int i=1;
	while(!in.eof())
	{
		in.read((char*)&p,sizeof(p));
		if(!in.eof())
		l.insertPos(p,i);
		i++;
	}
	
	
//	l.display();
	
	
//	in>>jersyNo;
//	in>>name;
//	in>>runs;
//	in>>wickets;
//	in>>noOfMatches;
//	
//	cout<<"jersy NO is : "<<jersyNo;
//	cout<<"\nname : "<<name;
//	cout<<"\nruns : "<<runs;
//	cout<<"\nnoOfMatches : "<<noOfMatches<<endl;;
	
	
	in.close();	
	
	int ch;
	
	do{
		cout<<"\n\t1->Insert Player\n\t2->Display Player\n\t3->Delete Player by position\n\t4->Search Player\n\t5->Update Player\n\t6->Max Runs\n\t7->Max Wickets\n\t8->Top Two Runs\n\t9->Top Two Runs\n\t10->Exit\n";
		cout<<"\tEnter your choice : ";
		
		cin>>ch;
		
		switch(ch)
		{
			case 1:
				{//Store player into linklist
					cout<<"Enter the jersyNo : ";
					cin>>jersyNo;
					fflush(stdin);
					cout<<"Enter name : ";
					gets(name);
					fflush(stdin);
					cout<<"Enter runs : ";
					cin>>runs;
					cout<<"Enter wickets : ";
					cin>>wickets;
					cout<<"Enter no of matches : ";
					cin>>noOfMatches;
					
					Player p(jersyNo,name,runs,wickets,noOfMatches);
					
					cout<<"Enter the position at which you want to insert the Player : ";
					int pos;
					cin>>pos;
					
					l.insertPos(p,pos);
					break;
				}
			case 2:
				{
					//Display Player
					cout<<"-------------------------------------------------------------------------\n";
					cout<<"JersyNo\t|Name\t\t|Runs\t|Wickets\t|NoOfMatches\n";
					cout<<"-------------------------------------------------------------------------\n";
					l.display();
					break;
				}
			case 3:
				{
					//Delete Player
					cout<<"Enter the position at which the player you want to delete : ";
					int pos;
					cin>>pos;
					l.deletePos(pos);
					break;
				}
			case 4:
				{
					//Search Player
					cout<<"Enter the player jersyNo to search that player : ";
					cin>>jersyNo;
					Node<Player>* res =  l.searchPlayer(jersyNo);
					if(res==NULL)
					{
						cout<<"Player Not found....\n";
					}else{
						cout<<"-------------------------------------------------------------------------\n";
						cout<<"JersyNo\t|Name\t\t|Runs\t|Wickets\t|NoOfMatches\n";
						cout<<"-------------------------------------------------------------------------\n";
						res->getData().display();
					}
					
					break;
				}
			case 5:
				{
					//Update Player
					cout<<"Enter player  jersyNo to update that player : ";
					cin>>jersyNo;
					if(l.updatePlayer(jersyNo))
					{
						cout<<"Updated Successfully";
					}else{
						cout<<"Can't Update something went wrong...";
					}
					break;
				}
			case 6:
				{
					//Max Runs
					Node<Player>* NodeWithMaxRuns =l.maxRuns();
					cout<<"-------------------------------------------------------------------------\n";
					cout<<"JersyNo\t|Name\t\t|Runs\t|Wickets\t|NoOfMatches\n";
					cout<<"-------------------------------------------------------------------------\n";
					NodeWithMaxRuns->getData().display();
					break;
					
				}
			case 7:
				{
					//Max Wickets
					Node<Player>* NodeWithMaxWickets = l.maxWickets();
					cout<<"-------------------------------------------------------------------------\n";
					cout<<"JersyNo\t|Name\t\t|Runs\t|Wickets\t|NoOfMatches\n";
					cout<<"-------------------------------------------------------------------------\n";
					NodeWithMaxWickets->getData().display();
					break;
				}
			case 8:
				{
					//Max Two Runs
					cout<<"-------------------------------------------------------------------------\n";
					cout<<"JersyNo\t|Name\t\t|Runs\t|Wickets\t|NoOfMatches\n";
					cout<<"-------------------------------------------------------------------------\n";
					l.topTwoRuns();
//				
					
					break;
				}
			case 9:
				{
					//Max Two Wickets
					cout<<"-------------------------------------------------------------------------\n";
					cout<<"JersyNo\t|Name\t\t|Runs\t|Wickets\t|NoOfMatches\n";
					cout<<"-------------------------------------------------------------------------\n";
					l.topTwoWickets();
					break;
				}
			default:
				{
					cout<<"Invalid Input Enter Again : "<<endl;
					break;
				}
		}
		
		
		
	}while(ch!=10);
	
//	l.~Linklist();
}
