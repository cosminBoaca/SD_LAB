                    /*Ciobanu Ovidiu~~~~~~~~Macovei Alexandra~~~~~~~~Tica Teodora */
                                                /* 312 CA */
#include<iostream>
#include"listCMT.h"
struct chestie   /*colega mea a ramas fara inspiratie */
{
    int a, b;
};
int main() {
	List<int> lst;
	// Initializarea cu o dimensiune n.
	int n;
	cout << "n = ";
	cin >> n;
    cout<<"Elementele: \n";
	for ( int i = 0; i < n; ++i ) {
		int x;
		cin >> x;
    //  lst.push_front(x);
        lst.push_back(x);
	}
	//  cout<<"Push front: ";
	cout<<"Push back: ";
    int sz = lst.get_size() - 1;
	for ( int i =0; i <= sz; ++i ) {
        cout<< lst.get_element(i) << "-" << i << " ";
	}
	cout<< "\n";
    List<int>::iterator itr1;
    List<int>::iterator itr2;
    itr1 = lst.begin();
    itr2 = lst.end();
    cout<< "Begin: " << *itr1;
    cout<< "\nEnd: " << *itr2;

    lst.remove(2);
    cout<< "\n";

    while( itr1 != itr2 )
    {
        cout<< *itr1 << " ";
        itr1++;
    }
    cout<< endl;
    List<chestie> y;
    List<chestie>::iterator itrC;
    y.push_back({19,96});
    itrC=y.end();
    cout<<itrC->a;

}
