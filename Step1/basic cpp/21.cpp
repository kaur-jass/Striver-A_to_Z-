#include<bits/stdc++.h>
using namespace std;
// Functions are the set of code which performs something for you
// Functions are used to modularise the code 
// Functions are used to increase readibilty 
// Functions are used to use same code multiple times
// 1. void  -> Which doesnot return anything 
// 2. return 
// 3. parameterised
// 4. non - parameterised

void printname(string name)
{
    cout << "Hey " << name << endl;
}
int main()
{
   string name1;
   cin >> name1;
   printname(name1);

   string name2;
   cin >> name2;
   printname(name2);
   return 0;
}