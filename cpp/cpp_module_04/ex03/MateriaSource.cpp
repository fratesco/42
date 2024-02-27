#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		materia[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &src)
{
	for (int i = 0; i < 4; i++)
	{
		if (src.materia[i])
			materia[i] = src.materia[i]->clone();
		else
			materia[i] = NULL;
	}
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &src)
{
	for (int i = 0; i < 4; i++)
	{
		if (src.materia[i])
			materia[i] = src.materia[i]->clone();
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for(int i = 0; i < 4; i++)
	{
		if (materia[i])
			delete (materia[i]);
	}
}

void	MateriaSource::learnMateria(AMateria *materia)
{
	for(int i = 0; i < 4; i++)
	{
		if (!this->materia[i])
		{
			this->materia[i] = materia;
			break;
		}
	}
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if ((materia[i]) && (materia[i]->getType() == type))
		{
			AMateria	*tmp = materia[i]->clone();
			return (tmp);
		}
	}
	return (NULL);
}