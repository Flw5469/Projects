#include <algorithm> 
#include <iostream> 
#include <vector> 
using namespace std;

int signcost;
int increased=0;



/*void display(vector <vector <pair<int, int>>*> array) {
for (int i = 0; i < array.size(); i++) {
for (int j = 0; j < array[i]->size(); j++)
{
cout << i << get <0> (array[i]->at(j))<< get <1>(array[i]->at(j));

}

cout << endl;



}







}



int main() {

int a,i1=0,i2=0,i3=0, n, m;



vector <vector <pair<int,int>>*> array(0);

cin >> a;//>> n >> m;







for (int i = 0; i < a; i++) {



cin >> i1>>i2>>i3;

i1--; i2--;



/*if ((i1 > array.size()) || (i2 > array.size())) {



int great=max(i1,i2);

cout << great;

int current = array.size();

array.resize(great);

for (int k = current; k < great; k++) {

array[k] = (vector <pair<int, int>>*)malloc(sizeof(pair<int,int>));

}



array[i1]->push_back(make_pair(i2,i3));

array[i2]->push_back(make_pair(i1, i3));

}







cout << i1<< i2<< i3;



}





display(array);





}*/



void display(pair <int, int>** array, int* size, int a) {
for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < size[i] ; j++)
		{
			cout << i + 1 << " " << (array[i])[j].first + 1 << " AND " << (array[i])[j].second <<" SIZE IS " << size[i] << endl;
		}
	}
}
//given a node and previous line(use data in that node), check whether set/upgrade better, return upgrade cost(return -1 if sign)
/*int process(pair <int, int>** array, int* size, int a, int nodenum, pair <int, int> previous, int preprecost) {
	cout << "NODE " << nodenum<<" pretend is " <<preprecost<<" previous is"<<previous.first<<previous.second << endl;
	if (size[nodenum] == 1) { cout << "end at " << nodenum<<endl; return 0; }
	int max = 0;

	if (preprecost >= previous.second)		//check pretend previous
	{
		increased = preprecost - previous.second;
		max += increased;
		for (int j = 0; j < size[nodenum]; j++) {
			if ((array[nodenum])[j].first != previous.first)
			{
				max += process(array, size, a, (array[nodenum])[j].first, make_pair(nodenum, (array[nodenum])[j].second), preprecost);
				cout <<endl<<endl<<nodenum <<"'s pretend max is " << max<<endl<<endl;
			}
		}
	}

	for (int i = 0; i < size[nodenum]; i++) {		//check all adj greater
		int total = 0;
		if ( (array[nodenum])[i].second>previous.second)
		{
		total += ((array[nodenum])[i].second-previous.second);
		for (int j = 0; j < size[nodenum]; j++) {
			if ((array[nodenum])[j].first != previous.first)
			total += process(array, size, a, (array[nodenum])[j].first, make_pair(nodenum, (array[nodenum])[j].second), (array[nodenum])[i].second);
		}
		if (total < max) { max = total; increased = (array[nodenum])[i].second - previous.second; }
		}
	}

	int setup = 0;
	cout << endl<<"                         checking setup cost of "<<nodenum<<endl;
	for (int j = 0; j < size[nodenum]; j++) {
		if ((array[nodenum])[j].first != previous.first)
		{
			setup += process(array, size, a, (array[nodenum])[j].first, make_pair(nodenum, (array[nodenum])[j].second), previous.second);
			
		}
	}
	setup += signcost * size[nodenum];
	cout <<nodenum <<" original max is " << max << " pretend set up cost is " << setup<<" as size is "<<size[nodenum];
	if (setup < max) {  max = setup; increased = 0; }
	cout <<"                                          NODE " <<nodenum<< " RETURN " << max << endl;
	return max;
}
*/

pair<int, int> process(pair <int, int>** array, int* size, int a, int nodenum, pair <int, int> previous, int preprecost) {
	if (size[nodenum] == 1) return make_pair(0, previous.second);
	cout << endl << "                                      visiting " << nodenum <<" cost "<<preprecost << endl;
	

	int tempsize = 2+size[nodenum];
	int* temp = (int*)malloc(sizeof(int) * (tempsize));
	pair <int, int> result;
	pair <int, int> tempresult=make_pair(-1,-1);
	//set up temp pointer
	temp[0] = previous.second;
	temp[1] = preprecost;
	for (int i = 0; i < size[nodenum]; i++) {
		temp[i + 2] = (array[nodenum])[i].second;
	}


	int loop = 0;
	while (loop < tempsize) {
		int sum;
		int returnedvalue;
		int nodedifferent;
		if (temp[loop] >= previous.second){

			sum = 0;

			sum += temp[loop] - previous.second;
			cout << "difference is " << sum;
			
			int returnedvalue=0;
			int nodedifferent=0;
			for (int i = 0; i < size[nodenum]; i++){		//loop one time adj
					if ((array[nodenum])[i].first != previous.first){	//dont go back
						
						tempresult = process(array, size, a, (array[nodenum])[i].first, make_pair(nodenum, (array[nodenum])[i].second), temp[loop]);
						
						sum += tempresult.first;
						
						if (i == 0)	returnedvalue = tempresult.second;//check returned value same (not same need setup)
						else if (returnedvalue != tempresult.second) nodedifferent = 1;


						if (tempresult.second > previous.second) {//add templist for each returned value
							int inputed = 0;
							for (int j = 0; j < tempsize; j++)	if (tempresult.second == temp[j]) inputed = 1;
							if (inputed == 0)
							{
								tempsize++;
								temp = (int*)realloc(temp, sizeof(int) * (tempsize));
								temp[tempsize - 1] = tempresult.second;
							}
						}
					}
			
			}
			if (nodedifferent == 1) {							//setup if have difference
				sum += signcost * size[nodenum];
			}

			if ((sum < result.first) || (result.first == -1)) {	//this use is smaller
				result.first = sum;
				result.second = temp[loop];
			}
		cout << "this loop's sum is "<<sum<<endl;
		}
		loop++;
	}




	cout << "                          return as node " << nodenum << " cost " << result.first << " newcost " << result.second << endl;
	return result;
}

//input a line, process(function to determine and change) its adj nodes , recursion on adj lines, after each process set increase as 0
void doing(pair <int, int>** array, int* size, int a) {







}

int main() {

	int a, b, c, d, e;
	pair <int, int>** array;
	int* size;
	cin >> a>>signcost;
	size = (int*)malloc(sizeof(int) * (a));
	array = (pair <int, int>**)malloc(sizeof(pair <int, int>*) * (a));
	for (int i = 0; i < a; i++) {
		pair <int, int>* temp;
		temp = (pair <int, int>*)malloc(sizeof(pair <int, int>));
		array[i] = temp;
		size[i] = 0;
	}



	cin >> b;
	for (int i = 0; i < b; i++) {
		cin >> c >> d >> e;
		c--; d--;
		//cout << "     " << size[c]; 
		(array[c])[size[c]] = make_pair(d, e);
		size[c]++;
		array[c] = (pair <int, int>*)realloc(array[c], sizeof(pair <int, int>) * (size[c])+1);
		//cout << "     " << size[d]; 
		(array[d])[size[d]] = make_pair(c, e);
		size[d]++;
		cout << "fine here!" << endl;
		array[d] = (pair <int, int>*)realloc(array[d], sizeof(pair <int, int>) * (size[d]+1));
	}

	display(array, size, a);
	cout<<endl<<" COST USED IS "<<process(array, size, a, 6 - 1, make_pair(7 - 1, 10), 10).first;
	cin >> a;
	return 69;

}