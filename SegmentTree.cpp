#include <iostream>
using namespace std;

class SegmentTree{
private:
	int segmenttree[100];
	int size;
public:
	SegmentTree(int n){
		this->size = n;
	}
	bool validIndex ( int index ){
		return ( index >=0 && index < 4*size );
	}
	int getLeftChild( int index ) {
		if ( validIndex(index) )
	 		return 2*index+1;
	 	return -1; 	
	}
	int getRightChild( int index ) {
		if ( validIndex(index) )
	 		return 2*index+2;
	 	return -1; 	
	}
	int getParent( int index ){
		if ( index >=0  )
			return index/2;
		return -1;
	}
	int createSegmentTree( int *a, int index, int l, int r ){
		/**
			This function creates segment tree recursively
		**/
		// Edge cases
		if ( !validIndex(index) ) return 0;
		// if current node is the leaf node then
		// store the value in the current node
		if ( l == r ) {
			segmenttree[ index ] = a[l];
			return a[l];
		}
		int mid = (l+r)/2;
		segmenttree[ index ] = createSegmentTree ( a, getLeftChild(index), l, mid ) +
							   createSegmentTree ( a, getRightChild(index), mid+1, r );
	 	return segmenttree[ index ];
	}
	void printSegmentTree () {
		for ( int i = 0; i < 4*size; i++ ){
			cout << segmenttree[i] << endl;
		}
	}
};

int main(){
	int a[5] = { 1, 3, -2, 8, -7 };
	cout << "size of a : " << ( sizeof(a) / sizeof( int ) ) << endl;
	SegmentTree segT( sizeof(a) / sizeof( int ) );
	segT.createSegmentTree ( a, 0, 0, 4 );
	segT.printSegmentTree();
	return 0;
}