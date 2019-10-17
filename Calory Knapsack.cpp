#include <iostream>
#include <algorithm>

using namespace std;

struct Item {
	char food[20];
	int value;
	int calories;
};

int length;

bool cmv(const Item &p1, const Item &p2){
    if(p1.value <= p2.value){
        return false;
	}
    else{
    	return true;
    }
}

bool cmc(const Item &p1, const Item &p2){
    if(p1.calories <= p2.calories){
        return false;
    }
    else{
        return true;
    }
}
//함수 정의 다시 
bool cmd(const Item &p1, const Item &p2){
	double x = (p1.value%p1.calories); 
	double y =(p2.value%p2.calories);
    if(x >= y){
    	return false;
    }
    else{
    	return true;
    }
}

//정렬은 내림차순으로 한번만 사용할 것! 
int testGreedy(Item i[],int budget, char s){
	if(s=='v'){
		sort(i,i+length,cmv);
	}else if(s=='c'){
		sort(i,i+length,cmc);
	}else if(s=='d'){
		sort(i,i+length,cmd);
	}
	cout<<budget<<"calories"<<"\n";
	int sum = 0;
	int num = 0;
	int val = 0;
	for(int j=0; j<length; j++){
		sum= sum+i[j].calories;
		num++;
		val = val+i[j].value;
		if(sum>budget){
			sum = sum - i[j].calories; 
			val = val - i[j].value;
			num--;

		} 
	}

	cout<<"Total value of items taken = "<<val<<"\n";
	
	for(int j=0; j<num; j++){
		cout<<i[j].food<<"        : <"<<i[j].value<<","<<i[j].calories<<">"<<"\n";
	}

}

int testGreedys(int budget){
	Item i[8]={{"Wine",89,123},{"Bear",90,154},{"Pizza",95,258},{"Burger",100,354},{"Fries",90,365},
			{"Coke",79,150},{"Apple",50,95},{"Donut",10,195}};
	length = sizeof(i) / sizeof(struct Item);
	cout<<"Use greedy by value to allocate"<<"\n";
	testGreedy(i,budget,'v');
	cout<<"Use greedy by cost to allocate"<<"\n";
	testGreedy(i,budget,'c');
	cout<<"Use greedy by density to allocate"<<"\n";
	testGreedy(i,budget,'d');
}

int main(void){
	int budget = 750;
	testGreedys(budget);
}
