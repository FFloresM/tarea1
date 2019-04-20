#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int _i,_j;

int binarySearch(vector<int> v, int l, int r, int x){
	int mid;
	if(r>=l)
		mid = (l+r)/2;
	if(v[mid]==x)
		return mid;
	if(v[mid]>x)
		return binarySearch(v,l,mid-1,x);
	else 
		return -1;		//no encontrado
	return binarySearch(v,mid+1,r,x);
}

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

//fix it
void nlogn(vector<int> v, int x){
	int b,y;
	for (int i = 0; i < v.size(); ++i){
		b = v[i];
		y = x-b;
		_j = binarySearch(v,0,v.size()-1,y);
		if (_j != -1)
			continue;
		else{
			_i=i;
			break;
		}
	}
}

void ene(vector<int> v, int x){
	/* code here */
}

int main(int argc, char const *argv[])
{
	//int n = atoi(argv[1]);
	int myints[] = {1,2,3,4,5};
  	vector<int> v (myints, myints + sizeof(myints) / sizeof(int) );
  	//vector<int> v (myints.begin(), myints.end());

	int x = 7;
	nlogn(v,x);
	cout << _i << " " << _j << endl;

//	cout << binarySearch(v, 0, 4,x) << endl;	

	return 0;
}