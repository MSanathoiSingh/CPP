/* Rail Fence Cipher */

#include <iostream>
#include <string>
#define SIZE 100
using namespace std;
class RailFence{                                                               // rail fence technique
	public:
    char tmatrix[SIZE][SIZE];                                                   // stores plain text in encrypted form
	int itr_col=0;      int itr_row=0;                                         // iterators for array
	RailFence(int key){                                                        // constructor function
		for(int r=0;r<key;r++){                                                // initializing array
            for(int c=0;c<SIZE;c++){
                tmatrix[r][c]= '1';
            }
		}
	}
	void RFTT(string text,int key){                                            // method for encryption
	    bool flag= false;                                                      // directional flag
	    int diff= 0;
		for(char i: text){                                                     // iterates characters of the string
		    if(int(i)!=32){                                                    // avoids blank spaces
		        if(flag==false){                                               // shows downhill iteration
		            tmatrix[itr_row][itr_col]= i;                              // inserting character at modified location
		            itr_row++;      itr_col++;                                 // incrementing pointers
		            if(itr_row==key){flag=true;}                               // setting flag for uphill iteration
		        }
		        else{
		            diff++;         itr_row= (key-1)-diff;                     // setting pointer indicating row index
		            tmatrix[itr_row][itr_col]= i;                              // encrypting character
		            itr_col++;
		            if(itr_row==0){                                            // setting flag for downhill iteration
                        flag=false;      itr_row++;      diff=0;
                    }
		        }
		    }
		}
	}
	void RFITd(int key,string text){
        char pt_arr[text.length()];
        int r1= key+(key-1)-2;
        int r1_f= text.lenght()/r1;         int cnt= r1_f;
        for(int i=0;i<cnt;i++){
            if(i==0){
                pt_arr[i]= text[i];
            }
            pt_arr[(r1*i)+i]= text[i];
        }

	}
	void display_e(int key,string text){                                         // method to display cipher text
	    int col= text.length();
	    for(int y=0;y<key;y++){                                                // iterates through cipher text
	        for(int c=0;c<col;c++){
                if(t_matrixt[y][c]!='1'){
                    cout<<t_matrix[y][c];                                        // printing the cipher text
                }
	        }
	    }
	}
};
int main(){
    int ky;         string pt;
    cout<<"Enter the key for encryption: ";     cin>>ky;                       // accepting key for encryption from user
    cin.ignore(1,'\n');
    cout<<"\nThe plain text to encrypt: ";      getline(cin,pt);               // taking plain text from user
    cout<<endl;
    RailFence encrypt(ky);                                                     // class instantiation
    encrypt.RFTT(pt,ky);                                                       // encrypting the plain text
    cout<<"The encrypted text will be: ";
    encrypt.display(ky,pt);                                                    // cipher text
    cout<<"\n\nCode by M Sanathoi Singh";
    return 0;
}
