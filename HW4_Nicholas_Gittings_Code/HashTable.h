#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

int inihash(const string &);
int nextPrime(int);

//Using hash table given from blackboard

class HashTable
{
	public:
		explicit HashTable(int size = 10) :
				currentSize(0)
		{
			theLists.resize(size);
			cout << "The Hash Table size is " << theLists.size() << endl;
		}

		bool insert(const string & x)
		{
			list<string> &whichList = theLists[myhash(x)];
			if (find(whichList.begin(), whichList.end(), x) != whichList.end())
			{
				return false;
			}
			whichList.push_back(x);
			cout << "Inserted " << x << endl;
			if (++currentSize > theLists.size()/2)
			{
				printList();
				rehash();
			}
			return true;
		}

		void makeEmpty()
		{
			for (unsigned i = 0; i < theLists.size(); i++)
				theLists[i].clear();
		}

		bool contains(const string & x) const
		{
			const list<string> & whichList = theLists[myhash(x)];
			return find(whichList.begin(), whichList.end(), x) != whichList.end();
		}

		bool remove(const string & x)
		{
			list<string> &whichList = theLists[myhash(x)];
			list<string>::iterator itr = find(whichList.begin(), whichList.end(), x);

			if (itr == whichList.end())
				return false;

			whichList.erase(itr);
			--currentSize;
			return true;
		}
		void rehash()
		{
			cout << "I am rehashing" << endl;
			vector<list<string> > oldLists = theLists;

			theLists.resize(nextPrime(2 * theLists.size()));
			for (unsigned j = 0; j < theLists.size(); j++)
				theLists[j].clear();

			currentSize = 0;
			for (unsigned i = 0; i < oldLists.size(); i++)
			{
				list<string>::iterator itr = oldLists[i].begin();
				while (itr != oldLists[i].end())
					insert(*itr++);
			}
		}

		void printList()
		{
			for (unsigned i = 0; i < theLists.size(); i++)
			{
				list<string> &whichList = theLists[i];
				if (theLists.size() != 0)
				{
					list<string>::iterator itr = whichList.begin();
					cout << i;
					while (itr != whichList.end())
					{
						cout << ",\t" << *itr << "\t";
						itr++;
					}
					cout << endl;
				}

			}
		}

	private:
		vector<list<string> > theLists;
		unsigned currentSize;

		int myhash(const string & x) const
		{
			int hashVal = inihash(x);

			hashVal %= theLists.size();
			if (hashVal < 0)
				hashVal += theLists.size();

			return hashVal;
		}
};

int inihash(const string & key)
{
	int hashVal = 0;

	for (unsigned i = 0; i < key.length(); i++)
	{
		hashVal = 41 * hashVal + key[i];
	} // end for

	return hashVal;
}

bool isPrime(int n)
{
	if (n == 2 || n == 3)
		return true;

	if (n == 1 || n % 2 == 0)
		return false;

	for (int i = 3; i * i <= n; i += 2)
		if (n % i == 0)
			return false;

	return true;
}

int nextPrime(int n)
{
	if (n % 2 == 0)
		n++;

	for (; !isPrime(n); n += 2)
		;

	return n;
}
