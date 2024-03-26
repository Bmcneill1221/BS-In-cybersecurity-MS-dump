#include <iostream>
#include <map>
#include <utility>
#include <algorithm>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

void displayMap(const map<string, string>& m)
{
	//cout << "MAP CONTENTS..." << endl;
	for (auto aMapValue : m)
	{
		cout << aMapValue.first <<endl;
			
	}
	
}

void displayFirst(const map<string, string>& m, string find) {

	for (auto aMapValue : m) {

		if (aMapValue.first == find)
			cout << aMapValue.first;
	}

	return;
}


//take txt file data into a map till "END" DONE// sweetsCalories.txt
int main() {

	string food,cal,filename;
	map<string, string>foodCal;
	cin >> filename;
	string out = "END\r";
	
	fstream myFile;
	myFile.open(filename, ios::in);

	if (myFile.is_open()) {

		getline(myFile, food);

		while (food != out /*|| cal != "END"*/) {

			getline(myFile, cal);
			//cout << food << endl;
			foodCal.emplace(food, cal);
			getline(myFile, food);

		}
	}

	displayMap(foodCal);
	//cout << food << endl;
	//remove an item specified from the txt file DONE
	string remove;
	getline(myFile, remove);
	
	while (remove != out) {

		if (foodCal.count(remove)) {

			foodCal.erase(remove);
			//displayFirst(foodCal, remove);
			cout << remove.substr(0, remove.size() - 1)<<" REMOVED" << endl;

		}
		else {
			cout << remove.substr(0, remove.size() - 1) << " NOT REMOVED...DOES NOT EXIST" << endl;
		}

		getline(myFile, remove);

	}
		//cout << remove;
	// print cur list DONE
	displayMap(foodCal);

	//print key for item from txt file req

	string dataReq;
	getline(myFile, dataReq);

	while (dataReq != out) {

		if(foodCal.count(dataReq)){

			cout << "KEY: "<< dataReq.substr(0, dataReq.size() - 1) << "  VALUE: " << foodCal.at(dataReq) << endl;
		getline(myFile, dataReq);

		}

		else
		{
			cout<< dataReq.substr(0, dataReq.size() - 1) <<" DOES NOT EXIST...NO VALUE RETRIEVED"<<endl;
			getline(myFile, dataReq);
		}

	}






}