// stats.cpp
// Project UID 5366c7e2b77742d5b2142097e51561a5
#include "stats.h"
#include <cassert>
#include <vector>
#include <cmath>
#include "p1_library.h"

using namespace std;

vector<pair<double, int> > summarize(vector<double> v) {
  assert(!v.empty());
  sort(v);
  vector<pair<double, int>> summary;
  summary.push_back(make_pair(v[0],1));
  for(int i=1;i<v.size();i++)
  {
    while(i<v.size()&&summary[summary.size()-1].first==v[i])
    {
      summary[summary.size()-1].second++;
      i++;
    }
    if(i<v.size())
    {
      summary.push_back(make_pair(v[i],1));
    }
  }
  return summary;
}

int count(vector<double> v) {
  return v.size();
}

double sum(vector<double> v) {
  assert(!v.empty());
    double sum = 0;
    for(int i=0;i<v.size();i++)
        sum+=v[i];
    return sum;
}

double mean(vector<double> v) {
  assert(!v.empty());
    return sum(v)/count(v);
}

double median(vector<double> v) {
  assert(!v.empty());
    sort(v);
    if(v.size()%2==0)
        return (v[v.size()/2]+v[v.size()/2-1])/2;
    else
        return (v[(int)v.size()/2]);
}

double mode(vector<double> v) {
  assert(!v.empty());
  sort(v);
  double mode = v[0];
  int countOfMode = 1;
  int currentCount=1;
  for(int i=1;i<v.size();i++)
  {
    if(i<v.size()&&v[i] == v[i-1])
      currentCount++;
    else
      currentCount=1;
    if(currentCount>countOfMode)
    {
      countOfMode = currentCount;
      mode = v[i-1];
    }
  }
  return mode;
}

double min(vector<double> v) {
  assert(!v.empty());
  double min = v[0];
  for(int i=1;i<v.size();i++)
  {
    if(v[i]<min)
      min=v[i];
  }
  return min;
}

double max(vector<double> v) {
  assert(!v.empty());
  double max = v[0];
  for(int i=1;i<v.size();i++)
  {
    if(v[i]>max)
      max=v[i];
  }
  return max;
}

double stdev(vector<double> v) {
  assert(v.size()>=2);
  double m = mean(v);
  double sumDifSq =0;
  for(double value : v)
    sumDifSq += pow((value-m),2);
  return  sqrt(sumDifSq/(v.size()-1));
}

double percentile(vector<double> v, double p) {
  assert(!v.empty());
  assert(p<=1&&p>=0);//assert requirements
  //if(v.size()==1)//test edge case of single element vector
  //  return v[0];
  sort(v);
  double rank = p*(v.size()-1);
  double rankInt, rankDec;
  rankDec = modf(rank,&rankInt);
  if(rankDec==0)//edge case test if p=1 or size of v is 1
    return v[rankInt];
  return v[rankInt]+rankDec*(v[rankInt+1]-v[rankInt]);
}