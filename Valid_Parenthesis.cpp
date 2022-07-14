#include<bits/stdc++.h>
using namespace std;

/*
Basically what's happening here is that, 
1) When we encounter opening bracket, we push it into stack
2) IF nest element is another opening bracket, then PUSH it onto stack
3) As soon as we get a closing bracket, we POP the previous element (input)
4) We have, [[]()]
    a) first PUSH '['
    b) then PUSH '['
    c) then POP ']'
    d) then PUSH '('
    e) then  POP ')'
    f) then POP ']'
    
5) If stack is empty then return TRUE
6) Else if stack is not empty(i.e. there is some bracket opening which doenst have bracket closing), return FALSE
*/


bool isValid(string s) 
{
    stack<char> input; //creating a stack namesd 'input'
    for (char& c : s)  //having an iterator 'c' to iterate in string s
    {
        cout<<"\nc : "<<c;
        switch (c) 
        {
            case '(': 
                input.push(c); 
                cout<<"\n\n\tAfter Push '(' \n\tc : "<<c<<"\n\n";
                break;
                
            case '{': 
                input.push(c); 
                cout<<"\n\n\tAfter Push '{' \n\tc : "<<c<<"\n\n";
                break;
                
            case '[': 
                input.push(c); 
                cout<<"\n\n\tAfter Push '[' \n\tc : "<<c<<"\n\n";
                break;
            
            
            case ')': 
                if (input.empty() || input.top()!='(') 
                    return false; 
                else 
                    input.pop(); 
                    cout<<"\n\tAfter POP ')' \n\t c : "<<c<<"\n\n";
                break;
                        
            case '}': 
                if (input.empty() || input.top()!='{')
                    return false; 
                else 
                    input.pop(); 
                    cout<<"\n\tAfter POP '}' \n\t c : "<<c<<"\n\n";
                break;
                        
            case ']':  
                if (input.empty() || input.top()!='[') 
                    return false; 
                else
                    input.pop(); 
                    cout<<"\n\tAfter POP ']' \n\t c : "<<c<<"\n\n";
                break;
                        
            default: ;
        }
    }
    return input.empty();
}


int main()
{
    string s = "[[]{}]()";
    bool check = isValid(s);
    
    if(check)
    {
        cout<<"\n\nThe given string contains valid parentheses.";
    }
    
    else
    {
        cout<<"\n\nThe given string contains invalid parentheses.";
    }
}
