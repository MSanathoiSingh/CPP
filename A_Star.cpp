#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    //cout << "Hello world!" << endl;
    cout<<"Enter the number of Nodes: ";
    int n;
    cin>>n;
    int arrh[n];
    for(int i=0; i<n; i++)
    {
        cout<<"Enter H value for "<<i<<":";
        cin>>arrh[i];
    }
    cout<<"Enter the number of Edges: ";
    int edg;
    cin>>edg;
    int n1,n2,wt;
    int edgwt[n][n];
    fill(edgwt[0],edgwt[0]+n*n,0);

    for(int i=0; i<edg; i++)
    {
        cout<<"Enter 1st, 2nd node & weight : ";    cin>>n1>>n2>>wt;
        edgwt[n1][n2] = wt;
        edgwt[n2][n1] = wt;
        //cout<<edgwt[n1][n2]<<endl;
    }

    cout<<"Enter start node: ";
    int strt;
    cin>>strt;

    cout<<"Enter goal node: ";
    int goal;
    cin>>goal;

    int visited[n] = {0};

    int mini = 1000;
    int nexp = strt;
    int sum = 0;
    vector<int>path;
    path.push_back(strt);
    int br1 = 0;
    while(nexp != goal)
    {
        int br = 0;
        visited[strt] = 1;

        for(int i=0; i<n; i++)
        {

            if(edgwt[strt][i]!=0 && visited[i]==0)
            {
                int f =  sum + arrh[i] + edgwt[strt][i];

                if(f<mini)
                {
                    mini = f;
                    nexp = i;
                }
                br = 1;
            }

        }
        if(br==0)
        {
            cout<<"No Optimal Path Found"<<endl;
            br1 = 1;
            break;
        }
        sum += edgwt[strt][nexp];
        strt = nexp;
        path.push_back(strt);
        mini = 1000;
    }

    if(br1!=1)
    {
        cout<<"Path found is: ";
        for(int i=0; i<path.size(); i++)
        {
            cout<<path[i]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
