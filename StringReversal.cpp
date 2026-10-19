//Initial Template for C++
#include<iostream>
using namespace std;

string reverseWord(string str);                        				 // method to reverse string

int main() {
	int t;
	cout<<"Enter the number of strings to reverse: ";
	cin>>t;															// accepting number of string to reverse
	while(t--){
        string s;
        cout<<"Enter string: ";         cin>>s;						// taking input string
        cout<<"Reversed word is: "<<reverseWord(s)<<endl;			// printing reversed string
	}
	return 0;
}
// } Driver Code Ends
//User function Template for C++

string reverseWord(string str){										// driver method
  //Your code here
  string out= "";													// stores reversed string
  char arr[str.length()];											// array to store characters of array
  int itr=0;
  for(char i:str){													// traverse through the string characters
      arr[itr]= i;
      itr++;
  }
  for(int o=str.length();o>0;o--){									// traversing array in reverse order
      out= out + arr[o-1];											// concatenating characters to string
  }
  return out;
}
