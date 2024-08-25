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

    std::cout << "   First Name| Last Name|  Nickname| Phone Num" << std::endl;

    while (this->contacts[i].get_first_name() != "") {
        cout << i << ": ";
        cout << this->contacts[i].get_first_name() << "|";
        cout << this->contacts[i].get_last_name() << "|";
        cout << this->contacts[i].get_nickname() << "|";
        cout << this->contacts[i].get_phone_number() << std::endl;
        i++;
    }
    return i;
}

// Displays a contact in the phonebook
void    PhoneBook::display_contact(int index) {
    if (this->contacts[index].get_first_name() != "") {
        cout << this->contacts[index].get_first_name() << std::endl;
        cout << this->contacts[index].get_last_name() << std::endl;
        cout << this->contacts[index].get_nickname() << std::endl;
        cout << this->contacts[index].get_phone_number() << std::endl;
        cout << this->contacts[index].get_darkest_secret() << std::endl;
    }
    else
        cout << "Contact not found" << std::endl;
}
