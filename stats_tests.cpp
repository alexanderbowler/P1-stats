/* stats_tests.cpp
 *
 * Unit tests for the simple statistics library
 * Project UID 5366c7e2b77742d5b2142097e51561a5
 *
 * EECS 280 Project 1
 *
 * Protip #1: Write tests for the functions BEFORE you implement them!  For
 * example, write tests for median() first, and then write median().  It sounds
 * like a pain, but it helps make sure that you are never under the illusion
 * that your code works when it's actually full of bugs.
 *
 * Protip #2: Instead of putting all your tests in main(),  put each test case
 * in a function!
 */


#include "stats.h"
#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>
using namespace std;

void test_sum_small_data_set();
void test_summarize();
void test_count();
void test_mean();
void test_median();
void test_mode();
void test_min();
void test_max();
void test_stdev();
void test_percentile();

// Add prototypes for you test functions here.

int main() {
  test_sum_small_data_set();
  test_summarize();
  test_count();
  test_mean();
  test_median();
  test_mode();
  test_min();
  test_max();
  test_stdev();
  test_percentile();
  return 0;
}

void test_sum_small_data_set() {
  cout << "test_sum_small_data_set" << endl;
  vector<double> data;
  data.push_back(1);
  data.push_back(2);
  data.push_back(3);
  assert(sum(data) == 6);
  vector<double> test0{1.2,2.3};
  assert(sum(test0)==3.5);
  vector<double> test1{1.3,-3.5,.0001};
  assert(sum(test1)==-2.1999);
  vector<double> test2{2.345,345,-9876,.5678,3,7.0};
  assert(sum(test2)==-9518.0872);

  vector<double> ErrorTest; //tests the assert error throw 
  //sum(ErrorTest);

  cout << "PASS!" << endl;
}

void test_summarize() {
  cout<<"Test_Summarize"<<endl;
    vector<double> test0{-1,0,0,1,2};
   // vector<pair<double,int>> output = summarize(test0);
    vector<pair<double,int>> solution0{make_pair(-1,1),make_pair(0,2),make_pair(1,1),make_pair(2,1)};
    //for(int i=0;i<output.size();i++)
   // cout<<output[i].first<<", "<<output[i].second<<endl;
    assert(summarize(test0)==solution0);

    vector<double> test1{0,-1,1,2,0};
    assert(summarize(test1)==solution0);

    vector<double> test2{-.998,-.999,-35,37,-35,-70};
    vector<pair<double,int>> solution2{make_pair(-70,1),make_pair(-35,2),make_pair(-.999,1),make_pair(-.998,1),make_pair(37,1)};
    assert(summarize(test2)==solution2);

    vector<double> test3{-3.5,5,-3.5,5,5,5,-2,-3.5,-3.5};
    vector<pair<double,int>> solution3{make_pair(-3.5,4),make_pair(-2,1),make_pair(5,4)};
    assert(summarize(test3)==solution3);
  

  cout << "PASS!" << endl;
}

void test_count(){
  cout<<"Test_Count"<<endl;
    vector<double> test0{-1,0,0,1,2};
    assert(count(test0)==5);

    vector<double> test1{0,-1,1,2,0,.987,4};
    assert(count(test1)==7);

    vector<double> test2{-.998,-.999,-35,37,-35,-70};
    assert(count(test2)==6);

    vector<double> test3;
    assert(count(test3)==0);

  cout << "PASS!" << endl;
}

void test_mean(){
  cout<<"Test_Mean"<<endl;
    vector<double> test0{-1,0,0,1,2};
    assert(mean(test0)==0.4);

    vector<double> test1{0,-1,1,2,0,.987,4};
    assert(mean(test1)==(6.987/7));

    vector<double> test2{-.998,-.999,-35,37,-35,-70};
    assert(mean(test2)==-17.4995);

    vector<double> test3{0,0,0};
    assert(mean(test3)==0);

  cout << "PASS!" << endl;
}

void test_median(){
  cout<<"Test_Median"<<endl;
    vector<double> test0{-1,0,0,1,2};//basic median test
    assert(median(test0)==0);

    vector<double> test1{0,-1,1,2,0,.987,4};//decimal test
    assert(median(test1)==.987);

    vector<double> test2{-.998,-.999,-35,37,-35,-70};//even count data set test, should find average of two middle terms
    assert(median(test2)==-17.9995);

    vector<double> test3{0,0,0};//sum 0 set test
    assert(median(test3)==0);

    vector<double> test4{3};//single digit set test
    assert(median(test4)==3);

  cout << "PASS!" << endl;
}

void test_mode(){
  cout<<"Test_Mode"<<endl;
    vector<double> test0{-1,0,0,1,2};//generic mode test
    assert(mode(test0)==0);

    vector<double> test1{0,-1,1,2,0,.987,4,-1};//tests two numbers both of same count, smaller should be reproted (-1)
    assert(mode(test1)==-1);

    vector<double> test2{-.998,-.999,-35,37,-70};//no repeated numbers should report smallest number (-70)
    assert(mode(test2)==-70);

    vector<double> test3{0,0,0,5,5,5,5,4.432,3.34,2.123};//larger set, and mode goes to end of sorted array
    assert(mode(test3)==5);

    vector<double> test4{3};//single digit set
    assert(mode(test4)==3);

    vector<double> test5{5.3,6.0,5.4,5.3,5.3,-2};//mode is of decimals to test rounding errors
    assert(mode(test5)==5.3);

  cout << "PASS!" << endl;
}

void test_min(){
  cout<<"Test_Min"<<endl;
    vector<double> test0{-1,0,0,1,2};//generic min test
    assert(min(test0)==-1);

    vector<double> test1{0,-1,1,2,0,.987,4,-1};//min test with negatives
    assert(min(test1)==-1);

    vector<double> test2{-.998,-.999,-35,37,-99999999999};//large negative number
    assert(min(test2)==-99999999999);

    vector<double> test3{0,0,0,5,5,5,5,4.432,3.34,2.123};//larger set
    assert(min(test3)==0);

    vector<double> test4{3};//single digit set
    assert(min(test4)==3);

  cout << "PASS!" << endl;
}

void test_max(){
  cout<<"Test_Max"<<endl;
    vector<double> test0{-1,0,0,1,2};//generic min test
    assert(max(test0)==2);

    vector<double> test1{0,-1,1,2,0,.987,4,-1};//min test with negatives
    assert(max(test1)==4);

    vector<double> test2{-.998,-.999,-35,37,9999999999};//large negative number
    assert(max(test2)==9999999999);

    vector<double> test3{0,0,0,5,5,5,5,4.432,3.34,2.123};//larger set
    assert(max(test3)==5);

    vector<double> test4{3};//single digit set
    assert(max(test4)==3);

  cout << "PASS!" << endl;
}

void test_stdev(){
  cout<<"Test_Standard_Deviation"<<endl;
    vector<double> test0{10, 12, 23, 23, 16, 23, 21, 16};//generic stdev test
    assert(abs(stdev(test0)-5.2372293656638)<.0001);

    vector<double> test1{1,2};//smallest # entries
    assert(abs(stdev(test1)-0.70710678118655)<.0001);

    vector<double> test2{-.998,-.999,-35,37,9999999999};//large negative number
    assert(abs(stdev(test2)-4472135954.552)<.0001);

    vector<double> test3{0,0,0,5,5,5,5,4.432,3.34,2.123};//larger set
    assert(abs(stdev(test3)-2.2591603774657)<.0001);

    vector<double> test4{0,0,0,0,0};//all zero digit set
    assert(abs(stdev(test4))==0);

  cout << "PASS!" << endl;
}

void test_percentile(){
  cout<<"Test_Percentile"<<endl;
    vector<double> test0{15, 20, 35, 40, 50};//generic percentile test
    assert(percentile(test0,.4)==29);

    vector<double> test1{5};//smallest # entries
    assert(percentile(test1,.5)==5);

    vector<double> test2{-.998,-.999,-35,37,999999};//large negative number
    assert(abs(percentile(test2,0.6)-14.2012)<.00001);

    vector<double> test4{0,0,0,0,0};//all zero digit set
    assert(percentile(test4,1)==0);

  cout << "PASS!" << endl;
}