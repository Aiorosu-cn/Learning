#include <fstream>

int main(){
	using namespace std;
	ofstream outfime,outfime2;
	outfime.open("ex.md");
	outfime << "[toc]\n# 1.car\n- this is a car\n- this is a driver# 2.you\n1. ok\n2. not ok" << endl;
	outfime.close();

	outfime2.open("ex.txt");
	outfime2 << "[toc]\n# 1.car\n- this is a car\n- this is a driver# 2.you\n1. ok\n2. not ok" << endl;
	outfime2.close();

}
