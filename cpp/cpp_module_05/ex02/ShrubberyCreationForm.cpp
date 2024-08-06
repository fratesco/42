#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("undefined")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string targ) : AForm("ShrubberyCreationForm", 145, 137), target(targ)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) :  AForm("ShrubberyCreationForm", 145, 137), target(src.target)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::action() const
{
	std::ofstream fout(target + "_shrubbery");
	fout<<"░░░░░░░░░░░░░░░░░░░░▄▄▄▄▄▄▄░░░░░░░\n░░░░░░░░▄▄▄░░░░░░▄███████████▄░░░░\n░░░░▄█████████▄▄███████████████▄░░\n░░██████████████████████▀░░░░▀▀▀█▄\n░▀▀░░░▄▄██████████████████▄░░░░░░░\n░░░▄████████████████████████▄░░░░░\n░░▄████▀▀██████▀████░░▀██████▄░░░░\n░▄███▀░░██████░░░███▄░░░░█████░░░░\n░██▀░░░██████░░░░████░░░░░████░░░░\n░█▀░░░░█████░░░░░█████░░░░░██▀░░░░\n░▀░░░░░█████░░░░░█████░░░░░██░░░░░\n░░░░░░░░███░░░░░░█████░░░░░▀░░░░░░\n░░░░░░░░░██░░░░░░█████░░░░░░░░░░░░\n░░░░░░░░░░▀█░░░░░█████░░░░░░░░░░░░\n░░░░░░░░░░░░░░░░██████░░░░░░░░░░░░\n░░░░░░░░░░░░░░░▄██████░░░░░░░░░░░░\n░░░░░░░░░▄▄▄▄▄▄███████▄▄░░░░░░░░░░\n▄▄▄██████████████████████▄▄▄░░░░░░\n▀█████████████████████████▀▀░░░░░░\n";
}