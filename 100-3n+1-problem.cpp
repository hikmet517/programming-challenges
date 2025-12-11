#include <cstdint>
#include <iostream>


uint32_t get_cycle_length(uint32_t x)
{
	uint32_t cycle = 1;
	while (x != 1) {
		if (x % 2 == 0) {
			x = x / 2;
		}
		else {
			x = 3 * x + 1;
		}
		cycle++;
	}
	return cycle;
}


uint32_t find_max_cycle_length(uint32_t x, uint32_t y)
{
	uint32_t max = 0;
	for (uint32_t i = x; i <= y; i++) {
		uint32_t res = get_cycle_length(i);
		if (res > max) {
			max = res;
		}
	}
	return max;
}


int main()
{
	uint32_t a, b;
	while (std::cin >> a >> b) {
		uint32_t max_cycle;
		if (a > b) {
			max_cycle = find_max_cycle_length(b, a);
		}
		else {
			max_cycle = find_max_cycle_length(a, b);
		}
		std::cout << a << " " << b << " " << max_cycle << '\n';
	}
	return 0;
}
