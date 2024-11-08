/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 13:21:07 by akastler          #+#    #+#             */
/*   Updated: 2023/09/11 13:38:22 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void){
    FragTrap frag("Fragged");
    
    frag.attack("target");
    frag.takeDamage(20);
    frag.beRepaired(10);
    frag.highFivesGuys();
    return (0);
}