//cpp输入和输出
#include <fstream>
#include <iostream>
#include <string> //getline函数
#include <iomanip>
#include <Windows.h>
#include <vector>


using namespace std;

//struct xyzT
//{
//	float x, y, z, T;
//};

int main()
{
	LARGE_INTEGER t1, t2, tc;
	QueryPerformanceFrequency(&tc);
	QueryPerformanceCounter(&t1);

	vector<string> xVec, yVec, zVec,tVec;

	//输入
	string strTemp, inputFileName = R"(E:\test\C++\testInput\inputDataFile.dat)";//取消转义字符R在VS2010中报错
	ifstream in(inputFileName);
	getline(in, strTemp);//逐行读取 换行区分
	const char * tt = strTemp.c_str(); // 把string对象转换成c中的字符串样式。c_str()接口是string类的一个函数,返回的是字符串的首地址。使用strlen(tt)取得C风格字符串的长度，不包括空字符
	int numOfNodes = atoi(tt);//将C风格字符串（C string）转成数字


	for (int i = 0, j = 0; i < numOfNodes + 2; i++)
	{
		getline(in, strTemp);
		if (bool(strstr(strTemp.c_str(), "(")) || bool(strstr(strTemp.c_str(), ")"))) 	continue; //如果一行内有(或)则跳过
		xVec.push_back(strTemp);
		j++;
	}
	for (int i = 0, j = 0; i < numOfNodes + 2; i++)
	{
		getline(in, strTemp);
		if (bool(strstr(strTemp.c_str(), "(")) || bool(strstr(strTemp.c_str(), ")"))) 	continue;
		j++;
	}
	for (int i = 0, j = 0; i < numOfNodes + 2; i++)
	{
		getline(in, strTemp);
		if (bool(strstr(strTemp.c_str(), "(")) || bool(strstr(strTemp.c_str(), ")"))) 	continue;
		//nodeArr[j].z = atof(strTemp.c_str());
		j++;
	}
	for (int i = 0, j = 0; i < numOfNodes + 2; i++)
	{
		getline(in, strTemp);
		if (bool(strstr(strTemp.c_str(), "(")) || bool(strstr(strTemp.c_str(), ")"))) 	continue;
		//nodeArr[j].T = atof(strTemp.c_str());
		j++;
	}
	QueryPerformanceCounter(&t2);
	printf("Use Time:%f\n", (t2.QuadPart - t1.QuadPart)*1.0 / tc.QuadPart);



	//QueryPerformanceFrequency(&tc);
	//QueryPerformanceCounter(&t1);

	////输出
	//string outputFileName = R"(E:\test\C++\testInput\outputDataFile.dat)";
	//ofstream fout(outputFileName);
	//for (int i = 0; i < numOfNodes; i++)
	//{
	//	fout << setw(12) << setprecision(3) << nodeArr[i].x << '\t' //setw需要包括<iomanip>
	//		<< setw(12) << setprecision(3) << nodeArr[i].y << '\t'
	//		<< setw(12) << setprecision(2) << nodeArr[i].z << '\t'
	//		<< setw(12) << setprecision(3) << nodeArr[i].T << '\n';
	//}
	//cout << "输出完毕" << endl;

	//fout.close();

	//nodeArr = NULL;

	//QueryPerformanceCounter(&t2);
	//printf("Use Time:%f\n", (t2.QuadPart - t1.QuadPart)*1.0 / tc.QuadPart);



	cin >> strTemp;
	return 0;
}