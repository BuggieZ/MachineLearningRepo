#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;



int main( int argc, char ** argv)
{


    ifstream inFS;
    string line;
    string id_in, pclass_in,survived_in,sex_in, age_in;
    const int MAX_LEN= 2000;

    vector <double> testSexV (MAX_LEN);
     vector <double> testSurV (MAX_LEN);
    vector <double> trainSexV (MAX_LEN);
    vector <double> trainSurV (MAX_LEN);

    vector<vector<double>> m;
    vector<vector<double>> m2;

    cout<<"Openning file titanic_project.csv. "<<endl;

    inFS.open("titanic_project.csv");
    if(!inFS.is_open()) {
        cout<<" Could not open file."<<endl;
        return 1;
    }


    cout<<"Reading line 1" <<endl;
    getline(inFS,line);

    cout<<"heading: "<<line<<endl;
    int numObservations= 0;
    int i = 0;

    while(inFS.good()) { 



        getline(inFS,id_in, ',');
        getline(inFS,pclass_in, ','); 
        getline(inFS,survived_in, ',');
        getline(inFS,sex_in, ','); 
        getline(inFS,age_in, '\n');


      //Take the first 800 to be in test vector
      if ( numObservations < 800)
        {
            trainSurV.at(numObservations) = stof(sex_in);
            trainSexV.at(numObservations) = stof(sex_in);
        }

        // take the rest of the observations in as testV
       if ( (numObservations >= 800) && (numObservations < 1046)&& i <246 )
        {
          testSexV.at(i) = stof(sex_in); 
          testSurV.at(i) = stof(sex_in);
          i++;
        }


           numObservations++;

        
        if(numObservations ==1046)
        {
            break;
        } 
    }


    trainSexV.resize(800);
    trainSurV.resize(800);
    testSexV.resize(246);
    testSurV.resize(246);
    




    cout<<"Closing file Boston.csv. "<<endl;


    cout<<"Number of records: " <<numObservations<<endl;

    cout<<"\nProgram terminaed.";



    return 0;
}