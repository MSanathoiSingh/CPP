#include<iostream>
#include<math.h>														/*header file for maths functions*/
#include<string.h>														/*header file for string operations*/
#include<stack>															/*header file for stack operations*/
using namespace std;
bool isoperator(char x){												/*function to check for operator presence*/
    return(x=='+'||x=='-'||x=='/'||x=='*')?1:0;							/*true if operator is found*/
}
bool isoperand(char y){													/*function to check for operand presence*/
    return (y>='a' && y<='z')?1:0;
    return (y>='A' && y<='Z')?1:0;
    return false;														/*false if no operand is found*/
}
int priority(char t){													/*function for ICP*/
    if(t=='*'||t=='/'){return 2;}
    if(t=='-'||t=='+'){return 1;}
    return -1;
}
float operation(float x, float y, char r){								/*function for operation with char_type*/
    if(r=='+'){return y+x;}
    else if(r=='-'){return y-x;}
    else if(r=='*'){return y*x;}
    else if(r=='/'){return y/x;}
    else return 0.0;
}
void intopost(string infix){											/*function to convert into postfix*/
    stack <char> st;													/*initializing char_type stack*/
    string post="";														/*initializing string for postfixexp*/
    char temp;
    st.push('(');														/*flag for start of postfixexp*/
    infix+=')';															/*flag for end of infixexp*/
    int l= infix.length();
    for(int i=0;i<l;i++){												/*iterates through infixexp*/
        temp= infix[i];
        if(isoperand(temp)){post+=temp;}								/*push operand into postfixexp*/
        else if(temp=='('){st.push(temp);}								/*push into postfixexp*/
        else if(temp==')'){												/*condition for parenthesis*/
            while(!st.empty() && st.top()!='('){						/*push to postfixexp til stack has element*/
                post+= st.top();
                st.pop();
            }
            st.pop();													/*pop ( from stack*/
        }
        else if(isoperator(temp)){
            while(!st.empty() && (priority(temp)<=priority(st.top()))){ /*check for ICP of operator*/
                post+=st.top();											/*pop to postfixexp till ISP>ICP*/
                st.pop();
            }
            st.push(temp);												/*push to stack if ISP<ICP*/
        }
    }
    cout<<"Postfix expression is: "<<post<<endl;						/*show the postfixexp*/
}
void evpost(string postfix){											/*function to evaluate postfixexp*/
    stack <float> st2;													/*initializing stack of float_type*/
    int l2=postfix.length();
    for (int k=0; k<l2; k++){											/*iterates through postfixexp*/
        char temp2= postfix[k];
        if(isoperand(temp2)){											/*checking for operand presence*/
            cout<<"Enter value of "<<temp2<<" ";						/*getting value of operand*/
            float val;
            cin>>val;
            st2.push(val);												/*pushing operand into stack*/
        }
        else if(isoperator(temp2)){										/*checking for operator presence*/
            float op1= st2.top();										/*getting first operand*/
            st2.pop();													/*popping first operand*/
            float op2= st2.top();										/*getting second operand*/
            st2.pop();													/*popping second operand*/
            st2.push(operation(op1,op2,temp2));							/*calculating op1(op)op2, then pushing into stack*/
        }
    }
    cout<<"Result is "<<st2.top()<<endl;								/*displaying the final result of exp*/
}
int main(){
	cout<<"Code by MSanathoi"<<endl;
    string infixexp, postfixexp;
    int lib;
    cout<<"Select your preference, please "<<endl;						/*displaying menu to users*/
    cout<<"1. Convert infix expression to postfix expression."<<endl;
    cout<<"2. Evaluate given postfix expression."<<endl;
    cout<<"NOTE: Only *,+,-,/ are excepted as operators."<<endl;
    cout<<"Press any other key to exit."<<endl;
    while(lib<3){														/*recursive switch cases*/
        cout<<"Give your choice: ";										/*getting user choice*/
        cin>>lib;
        switch(lib){
        case 1: cout<<"Enter infix expression for conversion: ";
        cin>>infixexp;
        intopost(infixexp);
        break;
        case 2: cout<<"Enter postfix expression to evaluate: ";
        cin>>postfixexp;
        evpost(postfixexp);
        break;
        }
    }
    return 0;
}
