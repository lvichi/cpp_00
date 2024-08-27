/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by lvichi            #+#    #+#             */
/*   Updated: 2024/08/21 17:40:27 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"
#include "Contact.hpp"

std::string user_input(std::string var_name);

int main(void)
{
    PhoneBook phonebook;
    Contact contact;

    while (1)
    {
        std::string command;
        std::cout << "Enter a command: ";
        std::getline(std::cin, command);
        if (command == "ADD")
        {
            std::string first_name = user_input("first name");
            std::string last_name = user_input("last name");
            std::string nickname = user_input("nickname");
            std::string phone_number = user_input("phone number");
            std::string darkest_secret = user_input("darkest secret");

            contact.set_first_name(first_name);
            contact.set_last_name(last_name);
            contact.set_nickname(nickname);
            contact.set_phone_number(phone_number);
            contact.set_darkest_secret(darkest_secret);

            phonebook.add_contact(contact);
        }
        else if (command == "SEARCH")
        {
            std::string index;
            int         contact_count;

            contact_count = phonebook.display_contacts();
            if (contact_count == 0)
                continue;
            while (1) {
                std::cout << "Enter index: ";
                std::getline(std::cin, index);
                if (index[1] || index[0] < '0' || index[0] >= (contact_count + '0')) {
                    std::cout << "Invalid index" << std::endl;
                    continue;
                }
                break;
            }
            phonebook.display_contact(index[0] - '0');
        }
        else if (command == "EXIT")
            break;
        else
            std::cerr << "--Error: invalid command--" << std::endl;
    }
    return 0;
}

std::string user_input(std::string var_name) {
    std::string str = "";

    while (str == "") {
        std::cout << "Enter " << var_name << ": ";
        std::getline(std::cin, str);
        if (str == "")
            std::cerr << "--Error: " << var_name << " cannot be empty" << std::endl;
    }
    return str;
}
