#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int binaryones(int n);
void permute(const string &str);
void permute(const string &str, int low, int high);
void closest(pair<double, double> coords, vector<pair<double, double>> vector, int choice);
double d_eucl(double x, double y, double a, double b);
double d_man(double x, double y, double a, double b);

int main()
{
	int choice, n;
	double house_x, house_y;
	bool running = true, entering;
	string input;

	vector<pair<double, double>> coords;
	pair<double, double> house_coords;

	while (running) {
		cout << "Homework Client V1.0" << endl;
		cout << "1. Get number of binary ones from integer" << endl;
		cout << "2. Get permutations for string" << endl;
		cout << "3. Compute nearest neighbour using vector of points" << endl;
		cout << "4. Exit" << endl;
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "Input an integer: " << endl;
			cin >> input;
			n = stoi(input);
			cout << binaryones(n) << endl;
			break;

		case 2:
			cout << "Input a string: " << endl;
			cin >> input;
			permute(input);
			break;

		case 3:
			entering = true;

			cout << "Enter x coordinate of house" << endl;
			cin >> input;
			house_x = stod(input);

			cout << "Enter y coordinate of house" << endl;
			cin >> input;
			house_y = stod(input);

			house_coords = make_pair(house_x, house_y);

			while (entering) {
				cout << "Enter a x coordinate: " << endl;
				cin >> input;
				double x = stod(input);

				cout << "Enter a y coordinate: " << endl;
				cin >> input;
				double y = stod(input);

				coords.push_back(make_pair(x, y));
				cout << "Done? (Y/N)" << endl;
				cin >> input;
				(input == "Y" || input == "y") ? entering = false : entering = true;
			}

			cout << "Enter 1 for Euclidean or 0 for Manhattan " << endl;
			cin >> n;

			closest(house_coords, coords, n);
			vector<pair<double, double>>().swap(coords);
			break;

		case 4: 
			running = false;
			break;

		default: cout << "Invalid Input..." << endl;
		}

	}
	return 0;
}

int binaryones(int n) {
	if (n == 0) {
		return 0;
	}
	else if(n == 1) {
		return 1;
	}
	else {
		return (n % 2) + binaryones(n / 2);
	}
}

void permute(const string &str) {
	int low = 0;
	int high = str.length();
	permute(str, low, high);
}

void permute(const string &str, int low, int high) {
	if (low == high) {
		cout << str << endl;
	}
	else {
		string temp = str;
		for (int i = low; i < high; i++) {
			swap(temp[low], temp[i]);
			permute(temp, low + 1, high);
		}
	}
}

void closest(pair<double, double> coords, vector<pair<double,double>> vector, int choice) {

	int size = vector.size();
	double distance;
	std::vector<double> distances;

		for (int i = 0; i < size; i++) {
				if (choice == 1) {
					distance = d_eucl(coords.first, coords.second, vector[i].first, vector[i].second);
					//cout << distance << endl;
					distances.push_back(distance);
				}
				else {
					distance = d_man(coords.first, coords.second, vector[i].first, vector[i].second);
					//cout << distance << endl;
					distances.push_back(distance);
				}
		}
		int max = distances.size();
		double match;
		auto result = min_element(distances.begin(), distances.end());
		for (int i = 0; i < max; i++) {
			if (choice == 1) {
				match = d_eucl(coords.first, coords.second, vector[i].first, vector[i].second);
				if (match == *result) {
					cout << "Nearest neighbour is: (" << vector[i].first << "," << vector[i].second << ") at " << match << " euclidean distance" << endl;
				}
			}
			else {
				match = d_man(coords.first, coords.second, vector[i].first, vector[i].second);
				if (match == *result) {
					cout << "Nearest neighbour is: (" << vector[i].first << "," << vector[i].second << ") at " << match << " manhattan distance" << endl;
				}
			}
		}
		std::vector<double>().swap(distances);
}

double d_eucl(double x, double y, double a, double b) {
	return sqrt(pow(a - x, 2) + pow(b - y, 2));
}

double d_man(double x, double y, double a, double b) {
	return abs(a - x) + abs(b - y);
}