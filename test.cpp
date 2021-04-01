#include <iostream>
#include <ctime>
#include <cstdlib> 
#include <vector>
using namespace std;

// Vector of Pairs to hold random Integer Pairs and Valid Entries
vector<pair<int,int>> IntegerPairs;
vector<pair<int,int>> ValidEntries;

// Array Square of 101*101 dimensions
int arr[101][101];

//populate function
void populate(int N)
{
    //Initialized 101 to variable d in the function to ease the writing of code
    //Initializing variables for array filling
    int d=101;
    int m,k;
    int count = 1;

    //Assigning all the array positions value of 1
    for(m=0; m<d; m++){
        for(k=0; k<d; k++) 
        {
            arr[m][k]=count;
        }
    }
    int counter = 0;
    int number1,number2;

    //while loop that uses int N to create number of random pairs
 while (counter <= N){
     //While counter is less than or equal to N:
     //Create intitialize number1,number2 to a random number less than 101
     //Create a pair<int,int> to store the two numbers together valled v1
     //Make v1.first and v1.second equal to number1 and 2 respectively
     //Add random integer pair to vector container IntegerPairs
     //Increase Counter
          number1 = rand()%d;
          number2 = rand()%d;
          pair <int,int> v1;
          v1.first=number1;
          v1.second=number2;
          IntegerPairs.push_back(v1);
          counter++; 
      }
      //For loop that traverses objects in vector container IntegerPairs
      //If the position in arr of the random vector pairs is greater than or equal to one
      //Increase the value of at that position by 1
      for (auto row_obj : IntegerPairs){
              if (arr[row_obj.first][row_obj.second] >=1 ){
                  arr[row_obj.first][row_obj.second] = arr[row_obj.first][row_obj.second] + 1;
         }
         }

        //Code to print out the array after populating
        //This is to show that the code is effective and works
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
    
    //Function to print items from a vector container of pairs that hold int,int values
    //Also prints out the value of the positoon of these pairs in arr 
    //Used in the searchValidEntries function 
void print_vector(const vector<pair<int,int>> Vect){
    for(int i = 0; i < Vect.size(); i++)
{
     cout << Vect[i].first << ", " << Vect[i].second  << "; " << arr[Vect[i].first][Vect[i].second] << endl;
}};

//searchValidEntries
void searchValidEntries(int a,int b,int c, int d){
    //Store pairs of the integers passed through the function  in pairs
    pair <int,int> Pair1;
    pair <int,int> Pair2;
    Pair1.first = a;
    Pair1. second = b;
    Pair2.first = c;
    Pair2. second = d;

    //For loop that:
    //Traverses through array for the positions stated in the pair
    //Checks whether the values at each position are greater than or equal to 2
    //Creates a pair of int,int called e1 and adds the value to it in each instance
    //Adds values to vector container called ValidEntries
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
     // Print function for the vector ValidEntries
     print_vector(ValidEntries);
}


int main()
{
    populate(2000);
    searchValidEntries(80,1,100,10);
    searchValidEntries(10,20,40,79);
    searchValidEntries(1,90,100,100);
    searchValidEntries(40,30,70,60);
    searchValidEntries(50,50,70,70);
}

