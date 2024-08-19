/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 17:10:07 by lvichi            #+#    #+#             */
/*   Updated: 2024/08/19 17:10:07 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

std::string str_toupper(char *str);

int main(int argc, char **argv)
{
    if (argc == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    for (int i = 1; argv[i]; i++) {
        std::cout << str_toupper(argv[i]) << std::endl;
    }
    return (0);
}

std::string str_toupper(char *str) {
    std::string str_upper = "";

    for (int i = 0; str[i]; i++){
        str_upper += std::toupper(str[i]);
    }
    return (str_upper);
}
