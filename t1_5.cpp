#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int _i,_j;

void n2(vector<int> v, int x){
	for (int i = 0; i < v.size(); ++i){
		for (int j = 0; j < v.size() && i!=j; ++j){
			if (v[i]+v[j]==x){
				_i=i;_j=j;
				//cout << i << " "<< j << endl;
				return;
			}
		}
	}
}

void nlogn(vector<int> v, int x){
	/* code here */
}

void ene(vector<int> v, int x){
	/* code here */
}

int main(int argc, char const *argv[])
{
	//int n = atoi(argv[1]);
	int myints[] = {1,2,3,4,5};
  	vector<int> v (myints, myints + sizeof(myints) / sizeof(int) );

	int x = 5;
	ene2(v,x);
	cout << _i << " " << _j << endl;
	

	return 0;
}