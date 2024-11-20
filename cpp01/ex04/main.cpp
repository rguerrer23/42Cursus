#include <iostream>
#include <fstream>

std::string replaceContent(std::string buffer, std::string s1, std::string s2)
{
	if (s1.empty())
		return buffer;

	size_t s1_len = s1.length();
	size_t s2_len = s2.length();
	size_t pos = 0;

	pos = buffer.find(s1);
	while (pos != std::string::npos)
	{
		buffer.erase(pos, s1_len);
		buffer.insert(pos, s2);
		pos = buffer.find(s1, pos + s2_len);
	}
	return buffer;
}

int main(int ac, char **av)
{

	if (ac != 4)
	{
		std::cerr << "Usage: ./replace filename s1 s2" << std::endl;
		return 1;
	}
	const std::string filename = av[1];
	const std::string s1 = av[2];
	const std::string s2 = av[3];
	std::string buffer;
	std::ifstream infile;
	std::ofstream outfile;

	infile.open(av[1]);
	if (!infile.is_open())
	{
		std::cerr << "Error: could not open file" << std::endl;
		return 1;
	}
	outfile.open((filename + ".replace").c_str());
	if (!outfile.is_open())
	{
		std::cerr << "Error: could not create file" << std::endl;
		return 1;
	}
	while (std::getline(infile, buffer))
	{
		buffer = replaceContent(buffer, s1, s2);
		outfile << buffer;
		if (!infile.eof())
			outfile << std::endl;
	}
	infile.close();
	outfile.close();
	return 0;
}
