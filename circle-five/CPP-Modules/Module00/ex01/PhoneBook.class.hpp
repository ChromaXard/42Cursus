/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:47:19 by akastler          #+#    #+#             */
/*   Updated: 2023/09/11 15:44:15 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

class PhoneBook
{
	public:
		void AddContact(void);
        void PrintBook(void);
        void PrintContact(void);
		void ExitPhone(void);
	private:
		Contact		_Contacts[8];
        void _PrintAddHeader(void);
		std::string _TruncStr(std::string str);
		std::string _ReplaceSpace(std::string str);
		int _VerifyNumber(std::string number);
		int			_AddNumber;
};