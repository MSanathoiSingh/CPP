/* Recursive Depth First Traversal by M Sanathoi Singh */

#include<iostream>
#include<vector>
#include<stack>
#define SIZE 50
using namespace std;
class DFS{														// DFS class container
    public:
    int src,des;												// variable to store source and destination nodes
    int itr= 0;
    int visited[SIZE];											// array for visited nodes
    stack<int> stk;												// stack to store nodes
    vector<int> tree[SIZE];										// vector to store initial tree
    DFS(){														// constructor of class
        for(int i=0;i<SIZE;i++){	
            visited[i]= -1;										// initializing the visited array
        }	
    }
    bool present(int var){										// method to check node is visited or not
        bool rtn= false;
        for(int chk=0;chk<SIZE;chk++){ 
            if(visited[chk]==var){rtn=true;}					// checking presence
        }
        return rtn;
    }
    void add_edge(int ed){                                      // add edge to tree
        for(int i=0;i<ed;i++){
            cout<<"Enter the source and destination node: ";    cin>>src>>des;  cout<<endl;
            tree[src].push_back(des);							// enter the edge to the tree
            tree[des].push_back(src);							// enter the unidirectional edge
        }
    }
    void dfs(int root){											// method for DFS traversal
        bool flag= false;
        if(!present(root)){                                     // check whether node is visited or not
            stk.push(root);										// if not visited, push node into stack
            visited[itr]= root;    								// if not visited, mark as visited
            itr+= 1;
        }
        for(auto t= tree[root].begin();t!=tree[root].end();++t){ // if present, traverse through its neighbours
            if(!present(*t)){									// if neighbour, is not visited
                dfs(*t);										// then, enter DFS recursively with neighbour as parameter
            }
            else{flag= true;}
        }
        if(!stk.empty()){										// if stack is not empty
            if(flag==true){
                cout<<stk.top()<<" ";							// print top of stack
                stk.pop();                                      // pop the top of stack
                dfs(stk.top());									// enter DFS recursively with new node as root node
            }
        }
    }
};
int main()
{
    int ned,strt;
    cout<<"Number of edges in the tree: ";  cin>>ned;   cout<<endl;	// accept number of edges from user
    DFS recursive;												 // create object of DFS class
    recursive.add_edge(ned);									 // accept edge from user
    cout<<"The root node is: "; cin>>strt;  cout<<endl;			 // accept root node to start with
    recursive.dfs(strt);                              			 // do DFS traversal
    return 0;
}
