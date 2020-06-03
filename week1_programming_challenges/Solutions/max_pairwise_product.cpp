#include <iostream>
#include <vector>
#include <algorithm>

unsigned long long MaxPairwiseProduct(const std::vector<unsigned long long>& numbers) {

	unsigned int index_1=-1;
	for (int i = 0; i < numbers.size(); i++)
	{
		if((index_1==-1)||(numbers[i]>numbers[index_1]))
		{
			index_1=i;
		}
	}

	unsigned int index_2=-1;
	for (int i = 0; i < numbers.size(); i++)
	{
		if((index_1!=i)&&((index_2==-1)||(numbers[i]>numbers[index_2])))
		{
			index_2=i;
		}
	}
    unsigned long long result = numbers[index_1]*numbers[index_2];
    return result;
}

int main() {
    unsigned int n;
    std::cin >> n;
    std::vector<unsigned long long> numbers(n);
    for (unsigned int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}
