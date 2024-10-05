#include <iostream>
using namespace std;

bool ok(int q[]){
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if(i!=j && q[i]==q[j]){
				return false;
			}
		}
	}
	return true;
}

int main(){
	int numSolutions = 0;
	int q[8]={};
	for(int i0=0;i0<8;i0++){
		q[0]=i0;
		for(int i1=0;i1<8;i1++){
			q[1]=i1;
			for(int i2=0;i2<8;i2++){
				q[2]=i2;
				for(int i3=0;i3<8;i3++){
					q[3]=i3;
					for(int i4=0;i4<8;i4++){
						q[4]=i4;
						for(int i5=0;i5<8;i5++){
							q[5]=i5;
							for(int i6=0;i6<8;i6++){
								q[6]=i6;
								for(int i7=0;i7<8;i7++){
									q[7]=i7;
									if(ok(q)){
										cout << "Solution #" << ++numSolutions << ":\n"; //This prints our solution number in the order it was found.
										for(int i = 0;i<8;i++){ //Simple nested for loop to print our board
											for(int j = 0;j<8;j++){
												cout << ((j==q[i])?"1 ":"0 ");
											}
											cout << endl;
										}
									cout << endl;
									}
								}
							}
						}						
					}
				}
			}
		}
	}
	return 0;
}