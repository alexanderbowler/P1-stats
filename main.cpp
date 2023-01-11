// main.cpp
// Project UID 5366c7e2b77742d5b2142097e51561a5
#include "stats.h"
#include "p1_library.h"
#include <iostream>

using namespace std;

int main() {
  string filename,columnName;
  cout<<"enter a filename"<<endl;
  cin>>filename;
  cout<<"enter a column name"<<endl;
  cin>>columnName;
  cout<<"reading column "<<columnName<<" from "<<filename<<endl;


  vector<double> data = extract_column(filename,columnName);

  cout<<"Summary (value: frequency)"<<endl;
  vector<pair<double,int>> summaryData = summarize(data);
  for(int i = 0; i<summaryData.size();i++)
    cout<<summaryData[i].first<<": "<<summaryData[i].second<<endl;//prints summary data

  cout<<"\ncount = "<<count(data)<<endl;//prints count
  cout<<"sum = "<<sum(data)<<endl;//prints sum
  cout<<"mean = "<<mean(data)<<endl;//prints mean
  cout<<"stdev = "<<stdev(data)<<endl;//prints standard deviation
  cout<<"median = "<<median(data)<<endl;//prints median
  cout<<"mode = "<<mode(data)<<endl;//prints mode
  cout<<"min = "<<min(data)<<endl;//prints min
  cout<<"max = "<<max(data)<<endl;//prints max

  cout<<"  0th percentile = "<<percentile(data,0)<<endl;//prints 0th percentile
  cout<<" 25th percentile = "<<percentile(data,.25)<<endl;//prints 25th percentile
  cout<<" 50th percentile = "<<percentile(data,.5)<<endl;//prints 50th percentile
  cout<<" 75th percentile = "<<percentile(data,.75)<<endl;//prints 75th percentile
  cout<<"100th percentile = "<<percentile(data,1)<<endl;//prints 100th percentile

}