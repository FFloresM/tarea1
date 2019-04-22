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
	uniform_int_distribution<int> dist(1,10);
	for (int i = 0; i < len; ++i){
		v.push_back (dist(generator));
	}
	sort(v.begin(), v.end());
}

int binarySearch(vector<int> v, int l, int r, int x){
	int mid;
	if(r>=l)
		mid = (l+r)/2;
	else 
		return -1;		//no encontrado
	if(v[mid]==x)
		return mid;
	if(v[mid]>x)
		return binarySearch(v,l,mid-1,x);
	
	return binarySearch(v,mid+1,r,x);
}

void n2(vector<int> v, int x){
	for (int i = 0; i < v.size(); ++i){
		for (int j = 0; j < v.size() ; ++j){
			if (v[i]+v[j]==x && i!=j){
				_i=i;_j=j;
				return;
			}
		}
	}
	_i=-1;_j=-1;
}

//fix it
void nlogn(vector<int> v, int x){
	int b,y;
	for (int i = 0; i < v.size(); ++i){
		b = v[i];
		y = x-b;
		_j = binarySearch(v,0,v.size()-1,y);
		if (_j == -1 || i==_j){
			_i=-1;_j=-1;
			continue;
		}	
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
  	vector<int> v;

  	init(v,20);
	int x = 20;
	show(v);

	n2(v,x);
	if(_i>=0 && _j >=0 ){
		cout<<"nlogn:"<<" A[" << _i<<"]" << " A[" << _j <<"]"<< endl;
		cout << v[_i] <<" + "<< v[_j] <<" = " << x << endl;
	}else cout << "valores no encontrados\n";

	nlogn(v,x);
	if(_i>=0 && _j >=0 ){
		cout<<"nlogn:"<<" A[" << _i<<"]" << " A[" << _j <<"]"<< endl;
		cout << v[_i] <<" + "<< v[_j] <<" = " << x << endl;
	}else cout << "valores no encontrados\n";
	
/*
  	init(v,20);
  	show(v);
*/  		

	return 0;
}