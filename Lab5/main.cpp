#include <iostream>
#include <functional>
#include <queue>
#include <vector>
#include <exception>
#include <string>
using namespace std;

class Exception : public exception {
private:
	string _msg;
public:
	Exception(string msg)
	{
		_msg = "Empty on " + msg;
	}

	virtual const char* what() const noexcept override {
		return _msg.c_str();
	}
};

class PriorityQueue2Min {
private:
	priority_queue < int_least64_t, vector<int_least64_t>, greater < int_least64_t >> queue;
public:
	PriorityQueue2Min() {

	}

	int_least64_t insert(int_least64_t value) {
		queue.push(value);
		return value;
	}

	int_least64_t extractMin() {
		if (queue.empty()) {
			throw Exception("extractMin()");
		}
		int_least64_t tmp = queue.top();
		queue.pop();
		return tmp;
	}

	int_least64_t firstMin() {
		if (queue.empty()) {
			throw Exception("firstMin()");
		}
		return queue.top();
	}

	int_least64_t secondMin() {
		if (queue.empty() || queue.size() == 1) {
			throw Exception("secondMin()");
		}
		int_least64_t tmp = queue.top();
		queue.pop();
		int_least64_t tmp2 = queue.top();
		queue.push(tmp);
		return tmp2;
	}
};



int main() {
	char c;
	int_least64_t v;
	cin >> c;
	PriorityQueue2Min mpq;
	while (cin >> c) {
		try {
			switch (c) {
			case 'f':
				cout << mpq.firstMin() << "\n";
				break;
			case 's':
				cout << mpq.secondMin() << "\n";
				break;
			case 'a':
				cin >> v;
				mpq.insert(v);
				break;
			case 'p':
				cout << mpq.extractMin() << "\n";
				break;
			}
		}
		catch (const exception& e) {
			cout << e.what() << "\n";
		}
		catch (...) {
			cout << "Dead case\n";
		}
	}
	return 0;
}