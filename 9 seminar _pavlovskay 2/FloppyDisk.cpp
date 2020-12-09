#include "FloppyDisk.h"

void FloppyDisk::comand()
{
	std::string name_file;
	int size_file;

	std::cin >> name_file >> size_file;

	char com = 0;
	std::cin >> com;
	switch (com)
	{
	case '1':
		try
		{
			this->write_file(name_file, size_file);
		}
		catch (const std::exception& ex)
		{
			std::cout << ex.what();
		}
		break;
	case '0':
		try
		{
			this->delete_file(name_file, size_file);
		}
		catch (const std::exception& ex)
		{
			std::cout << ex.what();
		}
		break;
	default:

		std::cout << "\nErorr!";
		std::cout << "No comand: ";
		break;
	}

}

void FloppyDisk::print_list()
{
	for (int i = 0; i < busy.GetSize(); i++)
	{
		std::cout << busy[i].name_file << " " << busy[i].size_file << "  Bit" << std::endl;
	}



}

void FloppyDisk::write_file(std::string name_file, int size_file)
{
	
	
	bool flag = true;
	for (int i = 0; i < free.GetSize(); i++)
	{
		if (size_file < free[i])
		{
			free[i] -= size_file;
			flag = false;
		}
	}

	if (flag)
		throw std::exception("Error!\n No disk space.\n");///////////////////////////////////////////////////////////////
	
	else
	{
		try
		{
			//File file(name_file, size_file);
			busy.push_front(File(name_file, size_file));
		}
		catch (const std::exception& ex)
		{
			std::cout << ex.what();

		}
	}

}

void FloppyDisk::delete_file(std::string name_file, int size_file)
{

	int idelete = 0;
	int counter = 0;
	for (int i = 0; i < busy.GetSize(); i++)
	{
		if ((busy[i].name_file == name_file) && (busy[i].size_file == size_file))
			idelete = i;
		else
			counter++;
	}

	if (counter == busy.GetSize())
		throw std::exception("Error!\n No disk file.\n");
	else
	{
		free.push_front(busy[idelete].size_file);
		busy.removeAt(idelete);
	}
}