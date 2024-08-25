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

using std::string;

class Contact {
    private:
        string first_name;
        string last_name;
        string nickname;
        int phone_number;
        string darkest_secret;
    public:
        Contact();

        ~Contact();

        void    set_first_name(string first_name);

        void    set_last_name(string last_name);

        void    set_nickname(string nickname);

        void    set_phone_number(int phone_number);

        void    set_darkest_secret(string darkest_secret);

        string  get_first_name(void);

        string  get_last_name(void);

        string  get_nickname(void);

        int     get_phone_number(void);

        string  get_darkest_secret(void);
};
