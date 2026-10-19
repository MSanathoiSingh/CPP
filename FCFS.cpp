/* First Come First Serve Job Scheduling by M Sanathoi Singh */

#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
#define SIZE 50
using namespace std;
class FCFS{
	public:
	int prcs_cmpl= 0;       	int tot_brst= 0;
	int avg_wait[SIZE];												// array to store wait time of processes executed
	int avg_tarnd[SIZE];											// array to store turnaround time of processes executed
	string prcs_name;			int arvl, brst;
	tuple<int,string,int> prcs[SIZE];								// tuple to store processes
	FCFS(int no_prc){												// constructor
		fill(avg_wait,avg_wait+no_prc,-1);							// initializing array
		fill(avg_tarnd,avg_tarnd+no_prc,-1);
	}
	void add_prcs(int ps){											// method to add processes
		for(int it=0;it<ps;it++){
			cout<<"Enter the process NAME with its ARRIVAL and BURST time: ";
			cin>>prcs_name>>arvl>>brst;	    cout<<endl;				// accepting arrival & burst time from user
			prcs[it]= make_tuple(arvl,prcs_name,brst);				// adding processes to queue
		}
	}
	void stats(int n_prcs){											// method to calculate average wait & turnaround time
		float wait= 0;			float tarn= 0;
		for(int i=0;i<n_prcs;i++){
			wait+= avg_wait[i];										
			tarn+= avg_tarnd[i];
		}
		cout<<"Average Wait time is: "<<wait/n_prcs<<endl;			// avergae wait time
		cout<<"Average Turnaround time is: "<<tarn/n_prcs<<endl;	// average turnaround time
	}
	void fcfs(int n_prcs){											// method to schedule job
		if(prcs_cmpl!=n_prcs){										// condition to terminate the scheduling
			if(prcs_cmpl==0){
				avg_wait[prcs_cmpl]= 0;								// wait time of first job is always '0'
				avg_tarnd[prcs_cmpl]= get<2>(prcs[prcs_cmpl]);		// turnaround time of first job
				tot_brst+= get<2>(prcs[prcs_cmpl]);					// variable to store total execution time
				prcs_cmpl++;
				fcfs(n_prcs);										// picking next job
			}
			else{
				avg_wait[prcs_cmpl]= tot_brst - get<0>(prcs[prcs_cmpl]);				// calculating wait time
				avg_tarnd[prcs_cmpl]= avg_wait[prcs_cmpl] + get<2>(prcs[prcs_cmpl]);	// calculating turnaround time
				tot_brst+= get<2>(prcs[prcs_cmpl]);					// storing total execution time
				prcs_cmpl++;
				fcfs(n_prcs);										// picking next job
			}
		}
	}
};
int main(){
	int no_prcs;
	cout<<"Enter number of processes to schedule ";		cin>>no_prcs;		cout<<endl;
	FCFS schd(no_prcs);												// creating object of class
	schd.add_prcs(no_prcs);											// adding processes to be scheduled
	sort(schd.prcs,schd.prcs+no_prcs);								// arranging jobs on first come basis
	cout<<"The processes are: "<<endl;
	for(int d=0;d<no_prcs;d++){										// displaying all jobs in ready queue
        cout<<"\t"<<get<0>(schd.prcs[d])<<"\t"<<get<2>(schd.prcs[d])<<endl;
	}
	cout<<endl;
	schd.fcfs(no_prcs);												// job scheduling
	cout<<"\t"<<"PROCESS"<<"\t\t"<<"WAIT TIME"<<"\t"<<"TURNAROUND TIME"<<endl;
	for(int tme=0;tme<no_prcs;tme++){								// wait time & turnaround time for each job
        cout<<"\t"<<get<1>(schd.prcs[tme])<<"\t\t"<<schd.avg_wait[tme]<<"\t\t"<<schd.avg_tarnd[tme]<<endl;
	}
	schd.stats(no_prcs);											// average wait & turnaround time of FCFS scheduling
	return 0;
};
