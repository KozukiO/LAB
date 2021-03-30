#include <iostream>
#include <ctime>
#include <cstdlib> 
#include <vector>
using namespace std;

vector<pair<int,int>> IntegerPairs;
vector<pair<int,int>> ValidEntries;
int arr[101][101];
void populate(int N)
{
    int d=101;
    int m,k;
    int count = 1;
    for(m=0; m<d; m++){
        for(k=0; k<d; k++) 
        {
            arr[m][k]=count;
        }}
    int counter = 0;
    int number1,number2;
 while (counter < N){
          number1 = rand()%d;
          number2 = rand()%d;
          pair <int,int> v1;
          v1.first=number1;
          v1.second=number2;
          IntegerPairs.push_back(v1);
          counter++; 
      }
      for (auto row_obj : IntegerPairs){
              if (arr[row_obj.first][row_obj.second] >=1 ){
                  arr[row_obj.first][row_obj.second] = arr[row_obj.first][row_obj.second] + 1;
         }
         }
         std::cout << "Array A" <<endl;
    for (int i = 0; i < d; ++i)
    {
        for (int j = 0; j < d; ++j)
        {
            std::cout << arr[i][j] << ' ';
        }
        std::cout << std::endl;
    }     
    }
    
void print_vector(const vector<pair<int,int>> Vect){
    for(int i = 0; i < Vect.size(); i++)
{
     cout << Vect[i].first << ", " << Vect[i].second  << "; " << arr[Vect[i].first][Vect[i].second] << endl;
}};
void searchValidEntries(int a,int b,int c, int d){
    pair <int,int> Pair1;
    pair <int,int> Pair2;
    Pair1.first = a;
    Pair1. second = b;
    Pair2.first = c;
    Pair2. second = d;
    int m,n;
     for (m=Pair1.first; m<=Pair2.first;m++){
         for (n = Pair1.second; n <=Pair2.second;n++){
             if( arr[m][n]>=2){
                 pair<int,int>e1;
                 e1.first=m;
                 e1.second=n;
                 ValidEntries.push_back(e1);
             }
         }
     }
     print_vector(ValidEntries);
}


int main()
{
    populate(2000);
    //searchValidEntries(80,1,100,10);
    //searchValidEntries(10,20,40,79);
    //searchValidEntries(1,90,100,100);
    //searchValidEntries(40,30,70,60);
    //searchValidEntries(50,50,70,70);
}

