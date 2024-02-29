#include"linklist.h"
#include<fstream>
#include<string.h>
template <class T>
Linklist<T>::Linklist()
{
	start = NULL;
}
///////////////////////////////
//void Linklist::insertBeg(int d)
//{
//	//1.Create a new Node
//	Node* temp = new Node(d);
//	//2.Attach the new Node First
//	temp->setNext(start);
//	//Modify Start
//	start = temp;
//}
////////////////////////////////
//void Linklist:: insertEnd(int data)
//{
//	Node* temp = new Node(data);
//	if(start==NULL)
//	{
//		start=temp;
//		return;
//	}
//	else{
//		//traverse till end
//		Node* p = start;
//		while(p->getNext()!=NULL)
//		{
//			p=p->getNext();
//		}
//		//attach node
//		p->setNext(temp);
//	}
//}
/////////////////////////////
template <class T>
void Linklist<T>::insertPos(T& data,int pos)
{
	Node<T>* temp = new Node<T>(data);
	if(start==NULL)
	{
		start=temp;
		return;
	}
	if(pos==1)
	{
		temp->setNext(start);
		start=temp;
	}else{
		Node<T>* p = start;
		int i=1;
		while(i<pos-1&&p->getNext()!=NULL)
		{
			p=p->getNext();
			i++;
		}
		temp->setNext(p->getNext());
		p->setNext(temp);
		
	}
}

////////////////////////////
template <class T>
void Linklist<T>::display()
{
	if(start == NULL)
	{
		cout<<"\nno Nodes to display";
		return;
	}else{
		//Traversal
		
		Node<T>* p = start;
		while(p!=NULL)
		{
//			cout<<"\t"<<p->getData();
			p->getData().display();
			p = p->getNext();
		}
	}
}
/////////////////////////////
//void Linklist::deleteBeg()
//{
//	if(start==NULL)
//	{
//		cout<<"\nNo nodes to delete...";
//		return;
//	}
//	Node* p = start;
//	start = start->getNext();
//	cout<<"\n"<<p->getData()<<" is deleted ...";
//	delete p;
//	
//}
//////////////////////////////
//void Linklist::deleteEnd()
//{
//	
//	
//	
//}
////////////////////////////
template <class T>
void Linklist<T>:: deletePos(int pos)
{
	if(start==NULL)
	{
		cout<<"\nno nodes to delete..";
		return;
	}
	//if their is only one node then delete first node
	Node<T>* p = start;
	if(pos==1)
	{
//		start = NULL;
		start = start->getNext();
//		cout<<"\n"<<p->getData()<<" is deleted..";
		cout<<"\n"<<p->getData().getName()<<" is deleted..";
		delete p;
		return;	
	}
	int i=1;
	while(i<pos-1 && p->getNext()!=NULL)
	{
		i++;
		p=p->getNext();
	}
	if(i==pos-1)//if user enters some invalid position like 40 then the last node should not be deleted
	{
		Node<T>* q = p->getNext();
		p->setNext(q->getNext());
//		cout<<"\n"<<q->getData()<<" is deleted..";
		cout<<"\n"<<q->getData().getJersyNo()<<" is deleted..";
		delete q;
	}
	else{
		cout<<"\nInvalid position..";
	}
	
}
/////////////////////////////////////////////////////
//void Linklist::deleteByData(int data)
//{
//	if(start==NULL)
//	{
//		cout<<"No node to delete..";
//		return;
//	}
//	Node* p = start;
//	if(start->getData()==data)
//	{
//		start = start->getNext();
//		cout<<"\n"<<p->getData()<<" is deleted.. ";
//		delete p;
//		return;
//	}
//	
//	while(p->getNext()!=NULL)
//	{
//		if(p->getNext()->getData()==data)
//		{
//			break;
//			
//		}
//		p=p->getNext();
//	}
//	Node* q = p->getNext();
//	p->setNext(q->getNext());
//	cout<<"\n"<<q->getData()<<" is deleted..";
//	delete q;	
//}
////////////////////////////////////////////////////
template <class T>
Node<T>* Linklist<T>::searchPlayer(int jersyNo)
{
	Node<T>* p = start;
	while(p!=NULL)
	{
		if(p->getData().getJersyNo()==jersyNo)
		{
			
			return p;
			
		}
		p=p->getNext();
	}
	
	return NULL;
}

///////////////////////////////////////////////////
template <class T>
bool Linklist<T>::updatePlayer(int jersyNo)
{
	Node<T>* p = searchPlayer(jersyNo);

	int choice;	
	
	if(p!=NULL)
	{
		while(choice!=5)
		{
			cout<<"\t1->Update Name\n\t2->Update Runs\n\t3->Update Wickets\n\t4->Update NoOfMatches Played\n\t5->Exit Updation\n";
			cout<<"\tEnter your choice : ";
			cin>>choice;
			switch(choice)
			{
				case 1:
					{
						//Update Name
						cout<<"Enter Player Name : ";
						char name[20];
						fflush(stdin);
						gets(name);
						fflush(stdin);
						p->getData().setName(name);
						cout<<"name Updated successfully...\n";
						break;
					}
					case 2:
					{
						//Update Runs
						cout<<"Enter Player runs : ";
						int runs;
						cin>>runs;
						p->getData().setRuns(runs);
						cout<<"Runs Updated Successfully...\n";
						break;
					}
					case 3:
					{
						//Update Wickets
						cout<<"Enter Player Wickets : ";
						int wickets;
						cin>>wickets;
						p->getData().setWickets(wickets);
						cout<<"Wickets updated successfully...\n";
						break;
					}
					case 4:
					{
						//Update No of Matches
						cout<<"Enter Player No of matches : ";
						int noOfMatches;
						cin>>noOfMatches;
						p->getData().setNoOfMatches(noOfMatches);
						cout<<"No of Matches Updated Successfully...\n";
						break;        	
					}
					case 5:
						{
							//Exit Updation
							cout<<"Saving your Updation..\n";
//							cout<<"Successfully Updated \n";
							return true;
							
							break;
						}
			}
		}
		
		
	}else{
		return false;
	}
}
////////////////////////////////////////////////////
template <class T>
Node<T>* Linklist<T>::maxRuns()
{
	Node<T>* iterator = start;
	Node<T>* maxRunsNode=start;//this will hold the address of the node in which the player with max runs is present
	int max=iterator->getData().getRuns();
	while(iterator!=NULL)
	{
		if(iterator->getData().getRuns()>max)
		{
			max = iterator->getData().getRuns();
			maxRunsNode = iterator;//giving the current node address to the maxRunsNode
			
		}
		iterator = iterator->getNext();//here iterator will be updated by giving the address of next node which is present in the current node 
	}
	
	return maxRunsNode;
}
////////////////////////////////////////////////////
template <class T>
Node<T>* Linklist<T>:: maxWickets()
{
	Node<T>* iterator = start;
	Node<T>* maxWicketsNode=start;//this will hold the address of the node in which the player with max runs is present
	int max=iterator->getData().getWickets();
	while(iterator!=NULL)
	{
		if(iterator->getData().getWickets()>max)
		{
			max = iterator->getData().getWickets();
			maxWicketsNode = iterator;//giving the current node address to the maxRunsNode
			
		}
		iterator = iterator->getNext();//here iterator will be updated by giving the address of next node which is present in the current node 
	}
	
	return maxWicketsNode;
}
////////////////////////////////////////////////////
//TopTwoRuns
template <class T>
void Linklist<T>::topTwoRuns()
{
	Node<T>* iterator = start;
	Node<T>* maxRunsNode=start;//this will hold the address of the node in which the player with max runs is present
	int max=iterator->getData().getRuns();
	while(iterator!=NULL)
	{
		if(iterator->getData().getRuns()>max)
		{
			max = iterator->getData().getRuns();
			maxRunsNode = iterator;//giving the current node address to the maxRunsNode
			
		}
		iterator = iterator->getNext();//here iterator will be updated by giving the address of next node which is present in the current node 
	}
	
	maxRunsNode->getData().display();
	
	int max2 = 0;
	iterator=start;
	Node<T>* maxRunsNode2=start;
	while(iterator!=NULL)
	{
		if(iterator->getData().getJersyNo()!=maxRunsNode->getData().getJersyNo())//here we will check that the address in iterator should not be equal to the address in the maxRunsNode i.e the node in which we have the player with max Runs
		{
			
			if(iterator->getData().getRuns()>max2)
			{
				max2 = iterator->getData().getRuns();
				maxRunsNode2 = iterator;//giving the current node address to the maxRunsNode2
				
			}	
		}
		iterator = iterator->getNext();
	}
	
	maxRunsNode2->getData().display();
}
////////////////////////////////////////////////////

////////////////////////////////////////////////////
//topTwoWickets
template <class T>
void Linklist<T>::topTwoWickets()
{
	Node<T>* iterator = start;
	Node<T>* maxWicketsNode=start;//this will hold the address of the node in which the player with max runs is present
	int max=iterator->getData().getWickets();
	while(iterator!=NULL)
	{
		if(iterator->getData().getWickets()>max)
		{
			max = iterator->getData().getWickets();
			maxWicketsNode = iterator;//giving the current node address to the maxRunsNode
			
		}
		iterator = iterator->getNext();//here iterator will be updated by giving the address of next node which is present in the current node 
	}
	
	maxWicketsNode->getData().display();
	
	int max2 = 0;
	iterator=start;
	Node<T>* maxWicketsNode2=start;
	while(iterator!=NULL)
	{
		if(iterator->getData().getJersyNo()!=maxWicketsNode->getData().getJersyNo())//here we will check that the address in iterator should not be equal to the address in the maxRunsNode i.e the node in which we have the player with max Runs
		{
			
			if(iterator->getData().getWickets()>max2)
			{
				max2 = iterator->getData().getWickets();
				maxWicketsNode2 = iterator;//giving the current node address to the maxRunsNode2
				
			}	
		}
		iterator = iterator->getNext();
	}
	
	maxWicketsNode2->getData().display();
}
////////////////////////////////////////////////////

template <class T>
Linklist<T>::~Linklist()
{
//	ofstream out("Test2.bin",ios_base::app);
	ofstream out("PlayersInfo.bin",ios_base::binary);
	
	Node<T>* p;
	while(start!=NULL)
	{
		p=start;
		
		out.write((char*)&start->getData(),sizeof(start->getData()));
		
//		int jersyNo = start->getData().getJersyNo();
//		char name[20];
//		strcpy(name,start->getData().getName());
//		
//		out<<jersyNo<<"  ";
//		out<<name<<"  ";
//		out<<p->getData().getRuns()<<"  ";
//		out<<p->getData().getWickets()<<"  ";
//		out<<p->getData().getNoOfMatches()<<"\n";
		start = start->getNext();
		delete p;
		
	}
}
///////////////////////////////////////////////////
