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

std::string str_toupper(const std::string& str);
std::string str_trim(const std::string& str);


int main(int argc, char **argv)
{
    std::string str = "";

    if (argc == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    for (int i = 1; argv[i]; i++) {
        str = str_toupper(argv[i]);
        str = str_trim(str);

        std::cout << str;
        if (argv[i + 1])
            std::cout << " ";
    }
    std::cout << std::endl;
    return (0);
}

std::string str_toupper(const std::string& str)
{
    std::string str_upper = "";

    for (int i = 0; str[i]; i++){
        str_upper += std::toupper(str[i]);
    }
    return (str_upper);
}

std::string str_trim(const std::string& str)
{
    int         i = -1;
    int         j = str.length();
    std::string str_trimmed = "";

    while (str[++i])
        if (str[i] != ' ' && str[i] != 9 && str[i] != 10 && str[i] != 11 && str[i] != 13)
            break;
    while (str[--j])
        if (str[j] != ' ' && str[j] != 9 && str[j] != 10 && str[j] != 11 && str[j] != 13)
            break;
    while (i <= j)
        str_trimmed += +str[i++];
    return str_trimmed;
}
