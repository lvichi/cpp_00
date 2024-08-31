/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by lvichi            #+#    #+#             */
/*   Updated: 2024/08/21 17:43:13 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

#include <iostream>
#include <iomanip>
#include "Contact.hpp"

#define MAX_CONTACTS 8

using std::string;
using std::cout;

class PhoneBook{
    private:
        Contact contacts[MAX_CONTACTS];
        int     last_index;

		// Return the info of a contact right aligned and limited to 10 characters
		string    	_print_info(string info);

		// Count the number of characters in a UTF-8 string
		int			_utf8_strlen(string str);

		// Return part of UTF-8 string (utf8_substr)
		string		_utf8_substr(string str, int start, int len);

		// Return the byte index of a character in a UTF-8 string
		size_t		_utf8_byte_index(string str, int char_pos);

    public:
        PhoneBook();
        ~PhoneBook();
        void    add_contact(Contact contact);
        int     display_contacts(void);
        void    display_contact(int index);
};
