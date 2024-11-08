/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:56:00 by akastler          #+#    #+#             */
/*   Updated: 2023/08/30 17:34:57 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Invalid number of arguments (filename, search, replace)" << std::endl;
		return 1;
	}
	std::string filename = argv[1];
	std::string search = argv[2];
	std::string replace = argv[3];
	std::ifstream ifs(filename);
	std::ofstream ofs(filename + ".replace");
	if (!ifs || !ofs)
	{
		std::cout << "Error opening file" << std::endl;
		return 1;
	}
	std::string line;
	std::string content;
	while (std::getline(ifs, line))
	{
		content += line;
		content += '\n';
	}
	ifs.close();
	while(1)
	{
		if (content.find(search) != std::string::npos) {
        	std::string beforeOccurrence = content.substr(0, content.find(search));
        	content =  beforeOccurrence + replace + content.substr(content.find(search) + search.length());
		}
		else
		{
			break;
		}
	}
	ofs << content << std::endl;
	ofs.close();
}