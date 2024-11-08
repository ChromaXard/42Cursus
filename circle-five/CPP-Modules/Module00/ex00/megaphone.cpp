/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 16:48:43 by akastler          #+#    #+#             */
/*   Updated: 2023/08/25 14:23:32 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
    std::string string;
    int i = 0;

    if (argc > 1)
    {
        i++;
        while(i < argc)
        {
            int j = 0;
            string = argv[i];
            while (j < (int)string.length()) {
                string[j] = std::toupper(string[j]);
                j++;
            }
            std::cout<< string;
            i++;
        }
        std::cout << std::endl;
    }
    else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
}