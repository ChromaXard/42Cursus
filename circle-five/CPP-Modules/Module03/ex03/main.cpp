/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 13:21:07 by akastler          #+#    #+#             */
/*   Updated: 2023/09/14 16:07:36 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void){
    DiamondTrap test("testeuh");
    DiamondTrap test2;

    std::cout << std::endl;
    test.whoAmI();
    test2.whoAmI();
    test2.attack("lui");
    std::cout << std::endl;
    return (0);
}