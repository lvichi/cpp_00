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
#include "Contact.hpp"

#define MAX_CONTACTS 8

using std::string;
using std::cout;

class PhoneBook{
    private:
        Contact contacts[MAX_CONTACTS];
        int     last_index;
    public:
        PhoneBook();
        ~PhoneBook();
        void    add_contact(Contact contact);
        int     display_contacts(void);
        void    display_contact(int index);
};
