#include <iostream>
#include <string>
using namespace std;
struct Node
{
    int value;
    Node *prev;
    Node *next;
};

class BinaryNumber
{

public:
    Node *head;
    Node *tail;
    BinaryNumber(string number);
    void display();
    BinaryNumber *onesComplement();
    BinaryNumber *twosComplement();
    BinaryNumber *plus(BinaryNumber &secondNumber);
};

BinaryNumber::BinaryNumber(string number)
{
    head = new Node;
    Node *current = head;
    Node *previous = NULL;
    for (int i = 0; i < number.length(); i++)
    {
        current->value = (int)number[i] - 48;
        current->prev = previous;
        current->next = NULL;
        if (i != number.length() - 1)
        {
            previous = current;
            current->next = new Node;
            current = current->next;
        }
        else
        {
            tail = current;
        }
    }
}

void BinaryNumber::display()
{
    Node *current = head;
    cout << "[ ";
    while (true)
    {
        if (current == NULL)
            break;
        cout << current->value;
        if (current->next != NULL)
            cout << ", ";

        current = current->next;
    }
    cout << " ]" << endl;
}

BinaryNumber *BinaryNumber::plus(BinaryNumber &secondNumber)
{
    Node *current1 = tail;
    Node *current2 = secondNumber.tail;
    int val1 = 0;
    int val2 = 0;
    string ans = "";
    int carry = 0;
    int total = 0;
    int sum = 0;
    while (current1 != NULL || current2 != NULL)
    {
        if (current1 != NULL)
        {
            val1 = current1->value;
            current1 = current1->prev;
        }
        else
            val1 = 0;
        if (current2 != NULL)
        {
            val2 = current2->value;
            current2 = current2->prev;
        }
        else
            val2 = 0;
        total = val1 + val2 + carry;
        carry = total / 2;
        sum = total % 2;
        ans += (char)(sum + 48);
    }
    if (carry)
        ans += (char)(carry + 48);
    string newAns = "";
    for (int i = ans.length() - 1; i >= 0; i--)
    {
        newAns += ans[i];
    }
    return new BinaryNumber(newAns);
}

BinaryNumber *BinaryNumber::onesComplement()
{
    Node *current = head;
    string onesAns = "";
    while (true)
    {
        if (current == NULL)
            break;
        if (current->value == 1)
            onesAns += '0';
        else
            onesAns += '1';
        current = current->next;
    }
    return new BinaryNumber(onesAns);
}

BinaryNumber *BinaryNumber::twosComplement()
{
    BinaryNumber onesComp = *onesComplement();
    BinaryNumber unity("1");
    BinaryNumber *ans = onesComp.plus(unity);
    return ans;
}

int main(void)
{
    cout<<"Code by MSanathoi"<<endl;
    BinaryNumber n1("111");
    BinaryNumber n2("001");
    n1.display();
    n2.display();
    BinaryNumber addition = *n1.plus(n2);
    addition.display();
    BinaryNumber onesComp = *n1.onesComplement();
    onesComp.display();
    BinaryNumber twosComp = *n1.twosComplement();
    twosComp.display();
    return 0;
}
