/*******************
* Problem: Design and implement a parking garage management system.
*
* DETAILS:
*   The garage has different size spaces for different types of vehicles
*   (compact/full/motorcycle/truck). The system should track available and
*   used spaces for each type, so it can refuse admittance to vehicles when
*   space for that type is full.
*
* NOTES:
*   - There is a camera at the entrance that provides you the approached
*     vehicle type and plate number. You should only let the vehicle in if
*     there is a free space for this type of vehicle.
*   - The assumption is that once the vehicle goes in it, will park in a space
*     designated for its type.
*   - When the vehicle exits, another camera gives you the plate number. You
*     should calculate the fee based on the vehicle type and length of stay.
*
* INSTRUCTIONS: Implement the following interface which will be called by
*               the garage hardware. You may choose to implement these as
*               free functions or class methods, whichever you feel is best,
*               but explain your choice.
*/

// Initializes the parking Garage with the provided table of available slots
// and prices per vehicle type.
// TODO: Choose sensible types for arguments and return value (if any).
void Initialize(? num_available_spaces_per_type,
             ? price_per_minute_per_type);

// Called once new vehicle approaches with the type and plate.
// Should return whether there is a free spot for the type
// TODO: Choose sensible types for arguments and return value (if any).
bool OnEnter(? plate, ? vehicleType);

// Called once vehicle approaches exit with the plate.
// Should return the fee to charge.
// TODO: Choose sensible types for arguments and return value (if any).
double OnExit(? plate);


unordered_map<string, unordered_map<string, VehicleInfo> > spaces_;
// spaces_ = { { "car" : {"XYZA123", struct VehicleInfo} }


typedef enum VehicleType_{
  CAR = 0,
  TRUCK,
  MOTORCYCLE
}VehicleType;

struct VehicleInfo{
  VehicleInfo(string plate) {
      enter_timestamp = time();
      plate_number = plate;
  }

  long long enter_timestamp;
  string plate_number;
};

class Garage final {

public:
  Garage(unordered_map<VehicleType,int>& spaces, unordered_map<VehicleType, double>& price_per_minute);
  bool OnEnter(string plate,  VehicleType type);
  double OnExit(string plate);

 private:
  unordered_map<VehicleType,double> price_;
  unordered_map<VehicleType,int> spaces_;
  unordered_map<VehicleType, unordered_map<string, VehicleInfo> > space_data_;
  unordered_map<string, Vehicletype> plate_to_type_;
};

Garage(unordered_map<VehicleType,int>& spaces, unordered_map<VehicleType, double>& price_per_minute)
  : price_(price_per_minute), spaces_(spaces){

}


/*

  [Validation Service]  -> [Kafka] -> [Consumers]

                      [Redis]


*/

// car, XYZ
// truck, ABC
// "unknow, AHB
// car, ""

bool Garage::OnEnter(string plate,  VehicleType type){

   if(spaces_.find(type) == spaces_.end()){
      throw std::runtime_exception("Vehicle Type not supported");
   }
   if(plate.length() == 0){
      return false;
   }
   // Find if we have space
   auto it = space_data_.find(type);
   if(it == space_data.end()){
       space_data_[type][plate] = VehicleInfo(plate);
       plate_to_type_[plate] = type;
       return true;
   }
   else if(it->second.size() >= spaces_[type].second){
        return false;
   }
   it->second[plate] = VehicleInfo(plate);
   plate_to_type_[plate] = type;
   return true;
}

bool Garage::OnExit(string plate) {
   if(plate.length() == 0){
      throw std::runtime_exception("Vehicle not found");
   }
   auto type = plate_to_type_[plate];
   auto info = space_data_[type][plate];
   // Calculate fare
   auto now = time();
   auto start = info.enter_timestamp;
   double fare = ((now - start) / 60) * price_[type];
   // refactor into funtion
   plate_to_type.erase(plate);
   space_data_[type].erase(plate);
   return fare;
}



////////////
// write a function which takes these input parameters:
// - an array of integers
// - another integer, call it S
// the function should return an integer which gives the number of triples <a,b,c> where the following conditions hold:
// a+b+c <= S
// a, b, and c are all members of the array.


// (a + b) <= S-c
// int twoSum(int splusc);
// for(int i = 0;i < arr.size(); i++){
    count += twoSum(S-arr[i]);
}



int function(vector<int>& arr, int S); //


class Triplets final {

public:
  void backtrack(int idx, vector<int>& subset);
  int findTriplets(vector<int>& arr, int S);

  int twoSum(int index);
  int findTripletsEx(vector<int>& arr, int S);

private:
  vector<int> arr_;
  int target_;
  vector<std::vector<int>> result_;
};

int Triplets::findTripletsEx(vector<int>& arr, int S){ // O(n^2)

  if(arr.size() < 3 ) return 0;
  std::sort(arr.begin(), arr.end()); // O(N Log N)

  arr_ = arr;
  target_ = S;
  int count =0 ;

  for(int i = 0; i < arr.size(); i++){ // O(N)
    count += twoSum(i);
  }
  return count;
}

int twoSumOptimized(int index){
  int target = target_ - arr_[index];

  int count = 0;

  // 1. Value at idx > target return 0
  // 2.
  // target = 1,   1, 2, 3, 5,

  // two pointer approach
  int left = index + 1;
  int right  arr_.size() -1;

  while(left < right) { // O(N + M)

    while(arr_[right] + arr_[left] > target) right--;
    count+= right - left;
    left++;
  }

  return count;
}


int twoSum(int index){
  int target = target_ - arr_[index];

  int count = 0;
  unorderd_map<int, int> cache;


  for(int i = index + 1; i < arr_.size(); i++){ // O(n^2)
    for(int j = i + 1; j < arr_.size(); j++){
      if(arr_[i] + arr_[j] <= target) count++;
    }
  }
  return count;
}


int Triplets::findTriplets(vector<int>& arr, int S){
   arr_ = arr;
   target_ = S;
   vector<int> subset;
   backtrack(0, subset);
   return result_.size();
}

// arr = [1, 2, 3, 4, 5, 6, 2, 2, 2]  S = 6
// result = [1, 2, 3], [2, 2, 2, ], [1, 2, 2]

// 1, 2, 3, 4, 5         == O() * N * N

// (3) -> (3 * n-1) -> (3 * n-1) * (n-1)

// combination = nc3 = n!/ 3!(n-3)!


void Triplets::backtrack(int idx, vector<int>& subset){ // O(n!/ 3!(n-3)!)
   // check if we have the result
   if(subset.size() == 3){
      auto sum = std::accumulate(subset.begin(), subset.end(), 0);
      if(sum <= target_){
        result_.push_back(subset);
      }
      return;
   }

   for(int i = idx; i < arr_.size(); i++){
        subset.push_back(arr_[i]);
        backtrack(i + 1, subset);
        subset.pop_back();
   }
}
// [1, 2,

//[1, 2, 3],