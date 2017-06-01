#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <boost/assign/list_of.hpp>

std::vector<int> sortArray(std::vector<int>);


int main()
{

	std::vector<int> testArr = boost::assign::list_of(13)(22)(342)(23)(12)(5)(134)(22)(31)(1)(233);

	std::cout << "Before sort: " << std::endl;
	for(int i = 0; i < testArr.size(); i++)
	{
		std::cout << testArr[i] << " ";
	}
	std::cout << "\n" << std::endl;

	std::vector<int> after = sortArray(testArr);
	
	std::cout << "After sort: " << std::endl;
	for(int i = 0; i < after.size(); i++)
	{
		std::cout << after[i] << " ";
	}

	return 0;
}



    //Function only sorts odd numbers in ascending order
    //while leaving even #'s in array spot
    //My strategy is to export all odds to an outside vector
    //then leave a -1 in their place (since we deal w/only +integers)
    //After that I go through odds and put them in spots of -1 

std::vector<int> sortArray(std::vector<int> array)
{
     std::vector<int> odds;
       
     //Find all odds and move them to odds vector
     //Since only pos integers, replace -1 in their spot
     for(int i = 0; i < array.size(); i++)
     {
         if(array[i] % 2 == 1)
         {
               odds.push_back(array[i]);
               array[i] = -1;
          }
     }
          
    //Sort the odds ascending
     std::sort (odds.begin(), odds.end());
          
     //Iterator for position of -1 in array
     int pos = 0;
          
     //Move through array, if == -1, make equal
     //to the next odd number in array
     for (int i = 0; i < odds.size(); i++)
     {
         for (int j = pos; j < array.size(); j++)
         {
             if (array[j] == -1)
             {
                array[j] = odds[i];
                pos++;
                break;
             }
              
                pos++;
        }
     }
   
      return array;
}












