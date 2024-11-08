/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 12:40:08 by akastler          #+#    #+#             */
/*   Updated: 2023/09/11 15:45:04 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void Contact::SetFirstName(std::string firstName) {
    this->_FirstName = firstName;
}

void Contact::SetLastName(std::string lastName) {
    this->_LastName = lastName;
}

void Contact::SetNickname(std::string nickname) {
    this->_Nickname = nickname;
}

void Contact::SetPhoneNumber(std::string phoneNumber) {
    this->_PhoneNumber = phoneNumber;
}

void Contact::SetDarkestSecret(std::string darkestSecret) {
    this->_DarkestSecret = darkestSecret;
}

std::string Contact::GetFirstName() const {
    return (this->_FirstName);
}

std::string Contact::GetLastName() const {
    return (this->_LastName);
}

std::string Contact::GetNickname() const {
    return (this->_Nickname);
}

std::string Contact::GetPhoneNumber() const {
    return (this->_PhoneNumber);
}

std::string Contact::GetDarkestSecret() const {
    return (this->_DarkestSecret);
}