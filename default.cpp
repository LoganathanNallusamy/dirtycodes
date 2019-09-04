#include <iostream>
using namespace std;

class sample {
	public:
	sample() = default;
//	sample() = delete;
	sample(int rhs) {
		data = rhs;
	}
#if 0
#endif
	private:
	int data;
};

int main()
{
	sample sa;
	sample sb(100);
	
}
