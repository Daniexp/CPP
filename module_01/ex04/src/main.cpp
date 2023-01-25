#include <string>
#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
	std::string	cnt, filename, s1, s2;
	if (argc != 4)
	{
		std::cout << "./ex04 filename s1 s2" << std::endl;
		return (1);
	}
	std::ifstream file(argv[1]);
	if (file.fail())
		return (1);
	file.seekg(0, std::ios::end);
	cnt.resize(file.tellg());
	file.seekg(0, std::ios::beg);
	file.read(&cnt[0], cnt.size());
	file.close();
	filename = argv[1];
	s1 = argv[2];
	s2 = argv[3];
	size_t	pos=0;
	while (std::string::npos != (pos = cnt.find(s1,pos)))
	{
		cnt.erase(pos, s1.length());
		cnt.insert(pos, s2);
		pos += s2.length();
	}
	filename.append(".replace");
	std::ofstream outfile(&filename[0], std::ios::out | std::ios::trunc);
	if (outfile.fail())
		return (1);
	outfile << cnt;
	outfile.close();
	std::cout << filename << " has been created." << std::endl;
}
