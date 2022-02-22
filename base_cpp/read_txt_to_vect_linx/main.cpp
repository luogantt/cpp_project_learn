
#include <iostream>  

#include <vector>
#include <fstream>
#include <string>


using namespace std;



string labels_txt_file = "../weights/classification_classes_ILSVRC2012.txt";
vector<string> readClassNames();


// 读取txt文件
//std::vector<String> readClassNames()
std::vector<string> readClassNames()
{
	std::vector<string> classNames;

	std::ifstream fp(labels_txt_file);
	if (!fp.is_open())
	{
		printf("could not open file...\n");
		exit(-1);
	}
	std::string name;
	while (!fp.eof())
	{
		std::getline(fp, name);
		if (name.length())
			classNames.push_back(name);
	}
	fp.close();
	return classNames;
}



int main()         // 返回值为整型带参的main函数. 函数体内使用或不使用argc和argv都可
{



	vector<string> labels = readClassNames();

	
	for (int i = 0; i < labels.size(); i++)
	{
		cout << "labels["<<i <<"]"<< labels[i] << endl;
	}


	//system("pause");
	return 0;
}

