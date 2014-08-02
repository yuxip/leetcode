#include<fstream>
#include<iostream>
#include<vector>

int Partition( std::vector<int>& sqlist, int low, int high, bool& lowmoved, bool& highmoved){

        lowmoved = false;
        highmoved = false;

        int mid = (low+high)/2;
        int pivot = -1;
        if(sqlist[low] > sqlist[high]){
                if(sqlist[low] < sqlist[mid]) pivot = low;
                else if(sqlist[high] > sqlist[mid]) pivot = high;
                else pivot = mid;
        }
        else if(sqlist[low] > sqlist[mid]) pivot = low;
        else{
                if(sqlist[high] > sqlist[mid]) pivot = mid;
                else pivot = high;
        }

        if(pivot!=low){
                int tmp_value = sqlist[low];
                sqlist[low] = sqlist[pivot];
                sqlist[pivot] = tmp_value;
        }

        int pivot_value = sqlist[low];
        while( low < high ){
		while(low < high && sqlist[high] >= pivot_value){
			if(sqlist[high] < sqlist[high-1])highmoved=true;
                        --high;
                }
                sqlist[low] = sqlist[high];
                while(low < high && sqlist[low] <= pivot_value){
			if(sqlist[low] > sqlist[low+1])lowmoved=true;
                        ++low;
                }
                sqlist[high] = sqlist[low];
        }

        sqlist[low] = pivot_value;

        return low;
}


void QSort( std::vector<int>& sqlist, int low, int high ){

        if(low < high){
		bool lowmoved = false;
		bool highmoved = false;
		int pivotloc = Partition(sqlist, low, high, lowmoved, highmoved);
	//	int pivotloc = Partition(sqlist, low, high);
		if(lowmoved)QSort(sqlist,low,pivotloc-1);
		if(highmoved)QSort(sqlist,pivotloc+1,high);
	//	QSort(sqlist,low,pivotloc-1);
	//	QSort(sqlist,pivotloc+1,high);
	}
}


void quickSort( std::vector<int>& sqlist ){

        QSort(sqlist,0,sqlist.size()-1);

}


int main(){


        std::fstream input("in2.txt",std::ios::in);
        std::vector<int> test(282);
        int i = 1;
        while(i<=282){
                input>>test[i-1];
                i++;
        }

        quickSort(test);

//	std::cout<<"after quick sort: "<<std::endl;
//	for(int i = 0; i < 282; i++)std::cout<<test[i]<<std::endl;
	return 1;
}
