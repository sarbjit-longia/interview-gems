#include <iostream>
#include <array>

class Sorting{

public:
	static void BubbleSort(int arr[], int length){
		for(int i = 0;i < length; i++){
			for(int j = 0;j < length; j++){
				if(arr[i] < arr[j])
					std::swap(arr[i], arr[j]);
			}
		}
	}

	static void InsertionSort(int arr[], int length){
		for(int i = 1 ; i < length; i++){
			int j = i;
			while( j > 0){
				if(arr[j] < arr[j-1]) std::swap(arr[j], arr[j-1]);
				j--;
			}
		}
	}

	static void SelectionSort(int arr[], int length){
		for(int i = 0; i < length; i++){
			for(int j = i; j < length; j++){
				if(arr[j] < arr[i]) std::swap(arr[j], arr[i]);
			}
		}
	}
};

void RunAlgo(std::function<decltype(Sorting::SelectionSort)> func, std::array<int, 6> arr){
	func(arr.data(), 6);
	std::copy(arr.begin(), arr.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout<<"\n";
}

int main(int argc, char* argv[]){
	std::array<int, 6> arr = { 4, 2, 9, 0, -1, -1};
	Sorting s;

	RunAlgo(s.BubbleSort, arr);
	RunAlgo(s.SelectionSort, arr);
	RunAlgo(s.InsertionSort, arr);

	return 0;
}


