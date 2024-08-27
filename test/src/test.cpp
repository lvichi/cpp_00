#include <iostream>
#include <string>

int main(void) {
	std::string str = "";

	std::cout << "Enter a string: ";
	std::getline(std::cin, str);
	std::cout << "You entered: " << str << std::endl;
	std::cout << "Size of string: " << str.size() << std::endl;
	std::cout << "Length of string: " << str.length() << std::endl;

	size_t	i = 0;
	int		len = 0;

	while (i < str.size()) {
		if ((str[i] & 0x80) == 0x00)
			// 1-byte character: 0xxxxxxx
			i += 1;
		else if ((str[i] & 0xE0) == 0xC0)
			// 2-byte character: 110xxxxx 10xxxxxx
			i += 2;
		else if ((str[i] & 0xF0) == 0xE0)
			// 3-byte character: 1110xxxx 10xxxxxx 10xxxxxx
			i += 3;
		else if ((str[i] & 0xF8) == 0xF0)
			// 4-byte character: 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
			i += 4;
		else
			// Invalid utf8 character
			i++;
		len++;
	}
	std::cout << "Length of string utf8: " << len << std::endl;
}
