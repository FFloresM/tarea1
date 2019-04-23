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
void init(vector<int> &v, int len, int max){
	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
	default_random_engine generator(seed);
	uniform_int_distribution<int> dist(1,max);
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

void nlogn(vector<int> v, int x){
	int b,y;
	for (int i = 0; i < v.size(); ++i){
		b = v[i];
		y = x-b;
		_j = binarySearch(v,0,v.size()-1,y);
		if (_j != -1 && i!=_j){
			_i=i;
			break;
		}	
		else{
			_i=-1;_j=-1;
		}
	}
	
}

void ene(vector<int> v, int x){
	int l = 0;
	int r = v.size()-1;
	while(l < r){
		if (v[l]+v[r] == x){
			_i=l;_j=r;
			return;
		}else if(v[l]+v[r] < x)
			l++;
		else r--;
	}
	_i=-1;_j=-1;
}


int main(int argc, char const *argv[])
{
	int x = atoi(argv[1]);
	int n = atoi(argv[2]);
	int max = atoi(argv[3]);

	vector<int> v;

	int p = 1<<n;
  	init(v,p,max);
	show(v);
	

	auto s1 = chrono::high_resolution_clock::now();
	n2(v,x);	
	auto f1 = chrono::high_resolution_clock::now();

	if(_i>=0 && _j >=0 ){
		cout<<"n^2:"<<" A[" << _i<<"]" << " A[" << _j <<"]"<< endl;
		cout << v[_i] <<" + "<< v[_j] <<" = " << x << endl;
	}else cout << "valores no encontrados\n";
	auto d1 = chrono::duration_cast<chrono::nanoseconds> (f1 - s1).count();
	cout <<"total time "<< d1 << " [ns]" << " \n\n";

	auto s2 = chrono::high_resolution_clock::now();
	nlogn(v,x);
	auto f2 = chrono::high_resolution_clock::now();
	if(_i>=0 && _j >=0 ){
		cout<<"nlogn:"<<" A[" << _i<<"]" << " A[" << _j <<"]"<< endl;
		cout << v[_i] <<" + "<< v[_j] <<" = " << x << endl;
	}else cout << "valores no encontrados\n";
	auto d2 = chrono::duration_cast<chrono::nanoseconds> (f2 - s2).count();
	cout <<"total time "<< d2 << " [ns]" << " \n\n";

	auto s3 = chrono::high_resolution_clock::now();
	ene(v,x);
	auto f3 = chrono::high_resolution_clock::now();
	if(_i>=0 && _j >=0 ){
		cout<<"n:"<<" A[" << _i<<"]" << " A[" << _j <<"]"<< endl;
		cout << v[_i] <<" + "<< v[_j] <<" = " << x << endl;
	}else cout << "valores no encontrados\n";
	auto d3 = chrono::duration_cast<chrono::nanoseconds> (f3 - s3).count();
	cout <<"total time "<< d3 << " [ns]" << " \n\n";

		

	return 0;
}
