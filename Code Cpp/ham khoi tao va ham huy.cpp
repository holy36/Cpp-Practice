#include <iostream>
#include<cstring>
#include<string.h>
using namespace std;

class sinh_vien {
    private:
        int ID_sv;
    public:
        sinh_vien(int a) {
            ID_sv = a;
        }
        ~sinh_vien(){
            cout << "Doi tuong da bi huy" << endl;
        }
        void in_thong_tin(){
            cout << "ID sinh vien la: " << ID_sv << endl;
        }
};

int main() {
    sinh_vien sv(1);
    sv.in_thong_tin();
    sinh_vien sv2 = sv;
    sv2.in_thong_tin();
    string a= "adudu";
	string b= "adudu";
	if (a == b) cout << "A"<<endl;
    return 0;
}
