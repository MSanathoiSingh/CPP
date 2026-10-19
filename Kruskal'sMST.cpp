/* Minimum Spanning Tree via Kruskal's algorithm by M Sanathoi Singh */

#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
#define SIZE 50
using namespace std;
class kruskal{														// class for Kruskal MST 
    public:
    int cost= 0;	int itr= 0;		int visit_itr=0;		int shw_itr= 0;
    int visited[SIZE];												// array to store visited nodes
	int show[SIZE];													// array to store nodes of MST	
    kruskal(){														// constructor 
        fill(visited,visited+SIZE,-1);								// initializing array
        fill(show,show+SIZE,-1);
    }
    vector<int> grph[SIZE];											// vector to store initial graph
    vector<int> min_cst[SIZE];										// vector to store minimum spaning tree
    tuple<int,int,int> edge[SIZE];									// tuple to relate edges with its nodes
    void add_edge(int n){											// method to add edges to the graph
        int src,des,wht;
        for(int i=0;i<n;i++){										
            cout<<"Enter WEIGHT along with SOURCE-DESTINATION of the edge: ";      cin>>wht>>src>>des;     cout<<endl;
            edge[i]= make_tuple(wht,src,des);						// adding edge's weight
            grph[src].push_back(des);       grph[des].push_back(src);			// adding unidirectional edges to initial vector
        }
    }
    void display(int root){											// method to display MST 
        cout<<root<<" ";											// printing the nodes
        show[shw_itr]= root;    shw_itr++;							// adding current node to visited list
        for(auto shw=min_cst[root].begin();shw!=min_cst[root].end();++shw){		// iterates over neighbours of current node	
            if(!present(*shw,show,SIZE)){							// if neighbour of current node is not printed
                display(*shw);										// then, precursively call 'display()' with nieghbour as node
            }
        }
    }
    bool present(int v1,int v2){									// method to check visited status of node (for parent check)
        bool flag= false;		int cntr= 0;
        for(int i=0;i<SIZE;i++){
            if(cntr==3){break;}										// if 2 nodes of parameter are visited then break out of loop
            else{if(visited[i]==v1 || visited[i]==v2){cntr++;}}		// increment counter if given node is present
        }
        if(cntr==2){flag=true;}
        return flag;												// returns status TRUE or FALSE
    }
    bool present(int one,int arr[],int len){						// method to check membership in any passed array
        bool flag1= false;
        for(int w=0;w<len;w++){
            if(arr[w]==one){flag1=true;     break;}					// condition check for membership
        }
        return flag1;												// returning status TRUE or FALSE
    }
    bool ancst(int c1,int c2){										// method to check cycle formation
        int common[grph[c1].size()];    fill(common,common+grph[c1].size(),-1);	    // array initialization 
		// graph to store neighbour of 1st node, and check for presence of common neighbour with 2nd node
        int common_itr= 0;				bool flag2= false;
        if(min_cst[c1].size()==1 && min_cst[c2].size()==1 && (*min_cst[c1].begin())==c2){flag2= false;}
		// check for presence of independent tree, i.e. not part of main tree
        else{														// if edge is already a part of main tree
            for(auto i=grph[c1].begin();i!=grph[c1].end();++i){		// iterate through neighbour of 1st node
                if(c2!=(*i)){										// check whether current neighbour is 2nd node itself
                    common[common_itr]= *i;							// if not, then add current neighbour to list of neighbours
                    common_itr++;
                }
            }
            cout<<endl;
            for(auto sec= grph[c2].begin();sec!=grph[c2].end();++sec){			// iterate neighbours of 2nd node
                if(*sec!=c1){										// avoid counting 1st node as its neighbour
                    if(grph[c1].size()==2 && grph[c2].size()==2){flag2= ancst(common[0],*sec);}
					// if no common neighbours, then do heirarchial check, i.e. check neighbour of neighbour for cycle(s)
                    else{
                        if(present(*sec,common,grph[c1].size())){	// if common neighbours
							// then, check in MST that whether 1st or 2nd node are connected with that common neighbour
                            for(auto mem= min_cst[c1].begin();mem!=min_cst[c1].end();++mem){if(*sec==*mem){flag2=true;  break;}}
                            for(auto mem1= min_cst[c2].begin();mem1!=min_cst[c2].end();++mem1){if(*sec==*mem1){flag2=true;  break;}}
							// if 1st or 2nd node is connected, then return true
                        }
                        if(flag2==true){break;}
                    }
                }
            }
        }
        return flag2;												// return the staus, i.e. TRUE or FALSE
    }
    void MST(int ed_wht,int itr_cnt){								// method to find minimum cost spanning tree
        if(itr!=itr_cnt){											// iterates for the number of edges present
            if(itr<3){												// check whether edge is one of the initial 3 edge or not
                cost+= ed_wht;										// if yes, than add its weight to final cost of tree
                if(!present(get<1>(edge[itr]),visited,SIZE)){		// check if source node is visited earlier
                    visited[visit_itr]= get<1>(edge[itr]);      visit_itr++;	// if unvisited, then marks it visited
                }
                min_cst[get<1>(edge[itr])].push_back(get<2>(edge[itr]));		// adding the edge to the MST
                if(!present(get<2>(edge[itr]),visited,SIZE)){		// check if source node is visited earlier
                    visited[visit_itr]= get<2>(edge[itr]);      visit_itr++;	// if unvisited, then marks it visited
                }
                min_cst[get<2>(edge[itr])].push_back(get<1>(edge[itr]));		// adding the edge to the MST
                ++itr;
                MST(get<0>(edge[itr]),itr_cnt);						// takes next edge in sorted weight list for recursion
            }
            else{													// if not the initial 3 edges, then
                if(!present(get<1>(edge[itr]),get<2>(edge[itr]))){  // check whether 1st & 2nd node are visited
                    cost+= ed_wht;									// if not visited, add edge weight to final cost of MST
                    if(!present(get<1>(edge[itr]),visited,SIZE)){   // check if source node is visited earlier
                        visited[visit_itr]= get<1>(edge[itr]);    visit_itr++;   // if unvisited, then marks it visited
                    }
                    min_cst[get<1>(edge[itr])].push_back(get<2>(edge[itr]));     // adding the edge to the MST
                    if(!present(get<2>(edge[itr]),visited,SIZE)){	// check if source node is visited earlier
                        visited[visit_itr]= get<2>(edge[itr]);    visit_itr++;   // if unvisited, then marks it visited
                    }
                    min_cst[get<2>(edge[itr])].push_back(get<1>(edge[itr]));	 // check if source node is visited earlier
                    ++itr;
                    MST(get<0>(edge[itr]),itr_cnt);					// takes next edge in sorted weight list for recursion
                }
                else{												// if 1st & 2nd node are visited
                    if(!ancst(get<1>(edge[itr]),get<2>(edge[itr]))){			// check whether 1st and 2nd forms cyle
                        cost+= ed_wht;								// if no cycle formed, add edge weight to final cost of MST
                        if(!present(get<1>(edge[itr]),visited,SIZE)){
                            visited[visit_itr]= get<1>(edge[itr]);      visit_itr++;
                        }
                        min_cst[get<1>(edge[itr])].push_back(get<2>(edge[itr]));
                        if(!present(get<2>(edge[itr]),visited,SIZE)){
                            visited[visit_itr]= get<2>(edge[itr]);      visit_itr++;
                        }
                        min_cst[get<2>(edge[itr])].push_back(get<1>(edge[itr])); 
                        ++itr;
                        MST(get<0>(edge[itr]),itr_cnt);				// takes next edge in sorted weight list for recursion
                    }
                    else{											// if cycle is formed, the edge is rejected
                        ++itr;
                        MST(get<0>(edge[itr]),itr_cnt);				// takes next edge in sorted weight list for recursion
                    }
                }
            }
        }
    }
};
int main()
{
    int ed,root;
    cout<<"Enter number of edges: ";    cin>>ed;    cout<<endl;	    // accept number of edges from user
    kruskal MST;													// create object of KRUSKAL class
    MST.add_edge(ed);												// adding edges to the graph
    sort(MST.edge,MST.edge+ed);										// sort the edges via weight
    cout<<"Sorted edges are: "<<endl;
    for(int i=0;i<ed;i++){											// printing the sorted edges of graph
        cout<<"\t"<<get<0>(MST.edge[i])<<" "<<get<1>(MST.edge[i])<<" "<<get<2>(MST.edge[i])<<endl;
    }
    MST.MST(get<0>(MST.edge[0]),ed);								// calling method for Kruskal's Algorithm
    cout<<"Minimum cost of the graph is "<<MST.cost<<endl;			// printing the cost of MST
    cout<<"Enter initial state of graph: ";     cin>>root;      cout<<endl;
    cout<<"Minimum Spanning Tree is: "<<endl;	
    MST.display(root);												// printing the MST hence formed
    return 0;	
}
