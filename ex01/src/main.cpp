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
#include <sstream>
#include "PhoneBook.hpp"
#include "Contact.hpp"

int string_to_int(const std::string& str);

int main(void)
{
    PhoneBook phonebook;
    Contact contact;

    while (1)
    {
        std::string command;
        std::cout << "Enter a command: ";
        std::cin >> command;
        if (command == "ADD")
        {
            std::string first_name = "";
            std::string last_name = "";
            std::string nickname = "";
            std::string phone_number = "";
            std::string darkest_secret = "";

            while (first_name == "") {
                std::cout << "Enter first name: ";
                std::cin >> first_name;
                if (first_name == "")
                    std::cout << "First name cannot be empty" << std::endl;
                contact.set_first_name(first_name);
            }

            while (last_name == "") {
                std::cout << "Enter last name: ";
                std::cin >> last_name;
                if (last_name == "")
                    std::cout << "Last name cannot be empty" << std::endl;
                contact.set_last_name(last_name);
            }

            while (nickname == "") {
                std::cout << "Enter nickname: ";
                std::cin >> nickname;
                if (nickname == "")
                    std::cout << "Nickname cannot be empty" << std::endl;
                contact.set_nickname(nickname);
            }

            while (phone_number == "") {
                std::cout << "Enter phone number: ";
                std::cin >> phone_number;
                if (phone_number == "")
                    std::cout << "Phone number cannot be empty" << std::endl;
                contact.set_phone_number(string_to_int(phone_number));
            }

            while (darkest_secret == "") {
                std::cout << "Enter darkest secret: ";
                std::cin >> darkest_secret;
                if (darkest_secret == "")
                    std::cout << "Darkest secret cannot be empty" << std::endl;
                contact.set_darkest_secret(darkest_secret);
            }

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
                std::cin >> index;
                if (string_to_int(index) < 0 || string_to_int(index) > contact_count) {
                    std::cout << "Invalid index" << std::endl;
                    continue;
                }
                break;
            }
            phonebook.display_contact(string_to_int(index));
        }
        else if (command == "EXIT")
            break;
        else
            std::cout << "Invalid command" << std::endl;
    }
    return 0;
}

int string_to_int(const std::string& str) {
    std::stringstream ss(str);
    int num;
    ss >> num;
    return num;
}
