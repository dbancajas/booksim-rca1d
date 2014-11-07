#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;


void getRCA_RouterList(vector<int>& xlist, vector<int>& ylist, int rID, int dest){

  assert(rID != dest); //no sense in calling this when flit has arrived
  xlist.clear();
  ylist.clear();

  int radix = 8;
  int dim = 2;


  int xcol_dest = dest % radix;
  int xcol_src = rID % radix;

  if (xcol_dest > xcol_src){//dest is at the right of src
        for (int i = 1; i <= xcol_dest - xcol_src; i++){
                xlist.push_back(rID + i);
                assert((rID + i) % radix > xcol_src);
        }
  }
  else {
        for (int i = 1; i <= xcol_src - xcol_dest; i++){
                xlist.push_back(rID - i);
                assert(((rID - i) % radix) < xcol_src);
        }
  }

  int ycol_dest = dest / radix;
  int ycol_src = rID / radix;

  if (ycol_dest > ycol_src){ //dest is above source
        for(int i=1; i<= ycol_dest - ycol_src; i++){
                ylist.push_back(rID + radix * i);
                assert((rID + radix * i)/radix > ycol_src );
        }
  }
  else {        
        for(int i=1; i<= ycol_src - ycol_dest; i++){
                ylist.push_back(rID - radix * i);
                assert((rID - radix * i)/radix < ycol_src );
        }
  }

}

void printVec(const vector<int>& v){
	cout<<"vec:";
	for (int i=0; i < v.size(); i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
}

int main(void){

	vector<int> x;
	vector<int> y;	

	getRCA_RouterList(x,y,40,15);

	printVec(x);
	printVec(y);

}
