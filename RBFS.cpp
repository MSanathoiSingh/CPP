/* Recursive Breadth First Traversal be M Sanathoi Singh */

#include<iostream>
#include<vector>
#include<queue>
#define SIZE 50
using namespace std;
class BFS{
    public:
	int src,des;                      // variables to store source and destination nodes
	int arr_itr=0;
	int visited[SIZE];           	  // array to store visited nodes
	BFS(){						 	  // constructor function
	    for(int fl=0;fl<SIZE;fl++){
            visited[fl]= -1;     	  // initializing visited array
	    }
	}
	queue<int> que;					  // queue for traversing the tree
	vector<int> tr[SIZE];             // vector stores tree
	bool present(int var){            // method to check presence of node in visited array
		bool flag= false;
		for(int itr=0;itr<SIZE;itr++){					// iterates all the visited nodes to check for given nodes
			if(visited[itr]==var){flag=true;}           // return 1 if node is already visited
		}
		return flag;
	}
	void add_edge(int ed){            // method to add edges to tree
		for(int i=0;i<ed;i++){
			cout<<"Enter the source & destination node: ";		cin>>src>>des;	 cout<<endl;
			tr[src].push_back(des);  					// inserting undirected edges to the graph, i.e. from A->B and B->A
			tr[des].push_back(src);
		}
	}
	void bfs(int root){          	  // BFS function for traversal
		if(!present(root)){           				    // checking if given node is visited
            visited[arr_itr]= root;                     // if not visited, add node into visited nodes list
            arr_itr+=1;
		}
		for(auto i=tr[root].begin();i!=tr[root].end();++i){			// traverse through neighbours of given nodes
			if(!present(*i)){							// check if the neighbour node is visited or not
				que.push(*i); 							// if unvisited, push neighbour into queue
				visited[arr_itr]= *i;					// add neighbour to visited nodes list
				arr_itr+= 1;
			}
		}
		cout<<root<<" ";								// print the current node
		if(!que.empty()){								// check whether queue is empty or not
			int node= que.front();						// next node to  visit
			que.pop();									// popping the displayed node
			bfs(node);									// performing BFS on next node, hence involving recursion
		}
	}
};
int main(){
	int edg,init;
	cout<<"Enter number of edges: ";	cin>>edg;	cout<<endl; 	// take number of edges in tree from user
	BFS dvr;											// making object of BFS class to access methods and variables
	dvr.add_edge(edg);									// calling method to add edges into tree
	cout<<"The root node is: ";	cin>>init;	cout<<endl; 			// taking inital node for traversal from the user
	dvr.bfs(init);													// calling method for RBFS traversal
	return 0;
};
