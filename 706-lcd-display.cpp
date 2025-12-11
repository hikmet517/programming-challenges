#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>
#include <array>

//   A
// F   B
//   G
// E   C
//   D
enum SegmentName {
	A = 0,
	B,
	C,
	D,
	E,
	F,
	G
};

using Segments = std::array<uint8_t, 7>;

const std::array<Segments, 10> digit_segments = {{
	// { A, B, C, D, E, F, G }
	{1, 1, 1, 1, 1, 1, 0},  // 0
	{0, 1, 1, 0, 0, 0, 0},  // 1
	{1, 1, 0, 1, 1, 0, 1},  // 2
	{1, 1, 1, 1, 0, 0, 1},  // 3
	{0, 1, 1, 0, 0, 1, 1},  // 4
	{1, 0, 1, 1, 0, 1, 1},  // 5
	{1, 0, 1, 1, 1, 1, 1},  // 6
	{1, 1, 1, 0, 0, 0, 0},  // 7
	{1, 1, 1, 1, 1, 1, 1},  // 8
	{1, 1, 1, 1, 0, 1, 1},  // 9
}};


char get_segment_char(Segments segments, SegmentName seg) {
	switch (seg) {
	case A:
	case G:
	case D:
		return segments[seg] ? '-' : ' ';
	case B:
	case C:
	case E:
	case F:
		return segments[seg] ? '|' : ' ';
	}
	return '?';
}


using Digits = std::vector<int>;

Digits num_to_digits(int num)
{
	std::vector<int> res;
	do
		{
			uint8_t digit = num % 10;
			res.push_back(digit);
			num /= 10;
		} while (num != 0);
	std::reverse(begin(res), end(res));
	return res;
}


int main()
{
	uint32_t size, num;
	while (std::cin >> size >> num) {
		if (size == 0 && num == 0) {
			break;
        }

		auto digits = num_to_digits(num);

		// draw A segments
		for (int d = 0; d < digits.size(); d++) {
			auto segments = digit_segments[digits[d]];
			std::cout << ' ';
			for (int i = 0; i < size; i++)
				std::cout << get_segment_char(segments, A);
			std::cout << ' ';
            if (d != digits.size() - 1)
				std::cout << ' ';	// space between digits
		}
		std::cout << '\n';

		// draw F and B segments
		for (int i = 0; i < size; i++) {
			for (int d = 0; d < digits.size(); d++) {
				auto segments = digit_segments[digits[d]];
				std::cout << get_segment_char(segments, F);
				for (int i = 0; i < size; i++)
					std::cout << ' ';
				std::cout << get_segment_char(segments, B);
				if (d != digits.size() - 1)
					std::cout << ' ';	// space between digits
			}
			std::cout << '\n';
		}

		// draw G segments
		for (int d = 0; d < digits.size(); d++) {
			auto segments = digit_segments[digits[d]];
			std::cout << ' ';
			for (int i = 0; i < size; i++)
				std::cout << get_segment_char(segments, G);
            std::cout << ' ';
            if (d != digits.size() - 1)
				std::cout << ' ';	// space between digits
		}
		std::cout << '\n';

		// draw E and C segments
		for (int i = 0; i < size; i++) {
			for (int d = 0; d < digits.size(); d++) {
				auto segments = digit_segments[digits[d]];
				std::cout << get_segment_char(segments, E);
				for (int i = 0; i < size; i++)
					std::cout << ' ';
				std::cout << get_segment_char(segments, C);
				if (d != digits.size() - 1)
					std::cout << ' ';	// space between digits
			}
			std::cout << '\n';
		}

		// draw D segments
		for (int d = 0; d < digits.size(); d++) {
			auto segments = digit_segments[digits[d]];
			std::cout << ' ';
			for (int i = 0; i < size; i++)
				std::cout << get_segment_char(segments, D);
			std::cout << ' ';
            if (d != digits.size() - 1)
				std::cout << ' ';	// space between digits
		}
		std::cout << '\n';

        // newline after each number
		std::cout << '\n';
	}
	return 0;
}
