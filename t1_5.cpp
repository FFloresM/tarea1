#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>

using namespace std;

int _i,_j;

void show(vector<int> v){
	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout<<endl;
	
}

//crea elementos aleatorios y los ordena
void init(vector<int> &v, int len){
	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
	default_random_engine generator(seed);
	uniform_int_distribution<int> dist(1,100);
	for (int i = 0; i < len; ++i){
		v.push_back (dist(generator));
	}
	sort(v.begin(), v.end());
}

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
		if (_j == -1)
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
  	vector<int> v;// (myints, myints + sizeof(myints) / sizeof(int) );
  	//vector<int> v (myints.begin(), myints.end());
/*
	int x = 7;
	n2(v,x);
	cout <<"n2: " << _i << " " << _j << endl;

	nlogn(v,x);
	cout<<"nlogn: " << _i << " " << _j << endl;
*/
  	init(v,20);
  	show(v);
  	
//	cout << binarySearch(v, 0, 4,x) << endl;	

	return 0;
}