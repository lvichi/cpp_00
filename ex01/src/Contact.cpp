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

#include "Contact.hpp"

// Constructor
Contact::Contact() {
}

// Destructor
Contact::~Contact(){
}

// Sets the first name
void    Contact::set_first_name(std::string first_name) {
    this->first_name = first_name;
}

// Sets the last name
void    Contact::set_last_name(std::string last_name) {
    this->last_name = last_name;
}

// Sets the nickname
void    Contact::set_nickname(std::string nickname) {
    this->nickname = nickname;
}

// Sets the phone number
void    Contact::set_phone_number(int phone_number) {
    this->phone_number = phone_number;
}

// Sets the darkest secret
void    Contact::set_darkest_secret(std::string darkest_secret) {
    this->darkest_secret = darkest_secret;
}

// Returns the first name
std::string Contact::get_first_name(void) {
    return this->first_name;
}

// Returns the last name
std::string Contact::get_last_name(void) {
    return this->last_name;
}

// Returns the nickname
std::string Contact::get_nickname(void) {
    return this->nickname;
}

// Returns the phone number
int Contact::get_phone_number(void) {
    return this->phone_number;
}

// Returns the darkest secret
std::string Contact::get_darkest_secret(void) {
    return this->darkest_secret;
}
