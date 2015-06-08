#include <iostream>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <stack>

using namespace std;
#define MAXNUM 100
bool isJollyFunc(int *number, int n)
{
   stack<int> s;
   for(int i=0; i<n-1; i++){
      s.push(abs(number[i+1] - number[i]));
   }
   int dif;
   for(int i=0; i<n-1; i++){
      dif = s.top();
      s.pop();
      if(dif != i+1){
         break;
      }
   }

   if(s.empty()){
      return false;
   }

   return true;
}
int main (int ac, char *av[])
{
   string inputNum;
   int number[MAXNUM];
   bool isJolly = false;
   while(getline(cin, inputNum)){
      if(inputNum[0] == '0'){
         break;
      }
      int n, i;
      istringstream stm(inputNum);
      stm >> n;
      for(i=1; i<=n; i++){
         stm >> number[i-1];
      }

      if(n == 1 && number[0] == 1){
         isJolly == true;
         continue;
      }

      isJolly = isJollyFunc(number, n);
      cout << inputNum << " " << isJolly << endl;

   }
   return 0;
}