/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by lvichi            #+#    #+#             */
/*   Updated: 2024/08/21 17:42:40 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

// Constructor
PhoneBook::PhoneBook() {
    this->last_index = 0;
}

// Destructor
PhoneBook::~PhoneBook(){
}

// Adds a contact to the phonebook
void    PhoneBook::add_contact(Contact contact) {
    if (this->last_index < MAX_CONTACTS)
        this->contacts[this->last_index] = contact;
    else {
        this->last_index = 0;
        this->contacts[this->last_index] = contact;
    }
    this->last_index++;
}

// Displays all contacts in the phonebook
int    PhoneBook::display_contacts(void) {
    int i = 0;

    std::cout << std::setw(13) << std::right << "First Name" << "|";
    std::cout << std::setw(10) << std::right << "Last Name"  << "|";
    std::cout << std::setw(10) << std::right << "Nickname"   << "|";
    std::cout << std::setw(10) << std::right << "Phone Num"  << std::endl;

    while (i < MAX_CONTACTS && !this->contacts[i].get_first_name().empty()) {
        std::cout << i << ": ";
        std::cout << std::setw(10)  << std::setfill(' ')    << std::right
                  << this->_print_info(this->contacts[i].get_first_name())   << "|";
        std::cout << std::setw(10)  << std::setfill(' ')    << std::right
                  << this->_print_info(this->contacts[i].get_last_name())    << "|";
        std::cout << std::setw(10)  << std::setfill(' ')    << std::right
                  << this->_print_info(this->contacts[i].get_nickname())     << "|";
        std::cout << std::setw(10)  << std::setfill(' ')    << std::right
                  << this->_print_info(this->contacts[i].get_phone_number()) << std::endl;
        i++;
    }
    return i;
}

// Displays a contact in the phonebook
void    PhoneBook::display_contact(int index) {
    if (this->contacts[index].get_first_name() != "") {
        cout << this->contacts[index].get_first_name() 		<< std::endl;
        cout << this->contacts[index].get_last_name() 		<< std::endl;
        cout << this->contacts[index].get_nickname() 		<< std::endl;
        cout << this->contacts[index].get_phone_number() 	<< std::endl;
        cout << this->contacts[index].get_darkest_secret() 	<< std::endl;
    }
    else
        cout << "Contact not found" << std::endl;
}

// Return the info of a contact right aligned and limited to 10 characters
string    PhoneBook::_print_info(string info) {
	int	info_len = this->_utf8_strlen(info);

	if (info_len > 10)
		return this->_utf8_substr(info, 0, 9) + ".";
	else
		return std::string(10 - info_len, ' ') + info;
}


// Count the number of characters in a UTF-8 string
int		PhoneBook::_utf8_strlen(string str) {
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

	return len;
}


// Return part of UTF-8 string (utf8_substr)
string		PhoneBook::_utf8_substr(string str, int start, int len) {
	size_t	byte_start = PhoneBook::_utf8_byte_index(str, start);
	size_t	byte_end = PhoneBook::_utf8_byte_index(str, start + len);

	return str.substr(byte_start, byte_end - byte_start);
}


// Return the byte index of a character in a UTF-8 string
size_t		PhoneBook::_utf8_byte_index(string str, int char_pos) {
	size_t	i = 0;
	int 	char_count = 0;

	while (i < str.size() && char_count < char_pos) {
		if ((str[i] & 0x80) == 0x00)
			i += 1;
		else if ((str[i] & 0xE0) == 0xC0)
			i += 2;
		else if ((str[i] & 0xF0) == 0xE0)
			i += 3;
		else if ((str[i] & 0xF8) == 0xF0)
			i += 4;
		else
			i++;
		char_count++;
	}

	return i;
}
