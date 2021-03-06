//Given a graph, design an algorithm and implement it using a program to find if a graph is bipartite or not. (Hint: use BFS)

#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main()
{
	cout << "AJAY GOSWAMI --> F --> 20011502" << endl;
    cout << "Question 17" << endl;
	int adjmat[8][7]={
	{0,1,0,0,0,1,0},
	{0,0,1,1,0,0,0},
	{0,0,0,1,0,0,0},
	{0,0,0,0,0,0,1},
	{0,1,0,1,0,0,1},
	{0,0,0,0,1,0,1},
	{0,1,0,0,0,0,0},
	{0,0,0,0,0,0,0}};
	int traversal[6]={0,0,0,0,0,0};
	int color[6]={0,0,0,0,0,0};
	vector<int> tlist;
	queue<int> q;
	q.push(0);
	traversal[0]=1;
	color[0]=1;
	while(!q.empty())
	{
		int temp = q.front();
		tlist.push_back(temp);
		q.pop();
		for(int i=0;i<6;i++)
		{
			if(adjmat[temp][i]==1 && color[temp]==color[i])
			{
				cout<<"Graph is not a Bipartite \n";
				return 0;
			}
			if(adjmat[temp][i]==1 && traversal[i]==0)
			{
				q.push(i);
				traversal[i]=1;
				if(color[temp]==1)
				{
					color[i]=2;
				}
				else if(color[temp]==1)
				{
					color[i]=1;
				}
}		}
			
	}
	for(int i=0;i<tlist.size();i++)
	{
		cout<<tlist[i]<<", ";
	}
	cout<<"\nGraph is Bipartite \n";
	return 0;
}