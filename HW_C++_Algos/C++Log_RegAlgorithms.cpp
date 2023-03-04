#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;





double sigmoid ( double z, double e){
return 1/(1 + pow(e, (-1 * z)));
}


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

    vector<vector<double>> m1;
    vector<vector<double>> m2;


    
    vector <double> weight;
    weight.push_back(1);
    weight.push_back(1);
    double e = 2.711828;
    double w0, w1, err = 0;

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

    while(inFS.good()) { 



        getline(inFS,id_in, ',');
        getline(inFS,pclass_in, ','); 
        getline(inFS,survived_in, ',');
        getline(inFS,sex_in, ','); 
        getline(inFS,age_in, '\n');


      //Take the first 800 to be in test vector
      if ( numObservations < 800)
        {
            trainSurV.at(numObservations) = stof(survived_in);
            trainSexV.at(numObservations) = stof(sex_in);
        }

        // take the rest of the observations in as testV
          int i = 0;
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
    

// Push to matrices
// create temp vectors, w0
vector < double> temp1;

int j= 1.0;
for ( int i = 0; i< 800; i++)
{
    temp1.push_back(j);
}
m1.push_back(temp1);
m1.push_back(trainSexV);
m2.push_back(temp1);
m2.push_back(trainSurV);

/***************testing for matrices m1 m2***************/
/*
for ( int j = 0; j< 2;j++){
    for ( int i = 700; i< trainSexV.size(); i++)
    {
        cout<<m1[j][i]<<endl;
    }
}
 cout<<" m2 " <<endl;
 for ( int j = 700; j< 2; j++) {
    for ( int i = 0; i< trainSexV.size(); i++)
    {
        cout<<m2[j][i]<<endl;
    }
 }

*/

/***************************training***************3*/

    vector <double> probability;
    double time;
    time= 0;
    // tcalculating probability vectors
     while ( time < 5000){
     for ( int j = 0; j < 800; j++)
        {   int i;
            i = m1[j][0]*weight[0]+m1[j][1]*weight[1];
            probability.push_back(sigmoid (i, e));
        }
        time++;

     }
      
    for ( int i = 0; i < 800; i++)
    { cout<<probability[i]<<endl;}


    cout<<"Closing file Boston.csv. "<<endl;


    cout<<"Number of records: " <<numObservations<<endl;

    cout<<"\nProgram terminaed.";



    return 0;
}

