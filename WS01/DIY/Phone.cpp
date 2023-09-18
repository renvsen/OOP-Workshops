#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "cStrTools.h"
#define MAX_NAME_LENGTH	50

using namespace std;

namespace sdds {
	struct contacts
	{
		char name[MAX_NAME_LENGTH];
		char areaCode[4];
		char prefix[4];
		char number[5];
	};

	void phoneDir(const char* programTitle, const char* fileName) {
		
		contacts phoneBook[MAX_NAME_LENGTH] = { {" "}, {" "}, {" "}, {" "} };
		char nameSearched[MAX_NAME_LENGTH];
		char lowerNameSearched[MAX_NAME_LENGTH];
		char lowerDirName[MAX_NAME_LENGTH];

		int i = 0;

		FILE* fp;

		cout << programTitle << " phone direcotry search" << endl << "-------------------------------------------------------" << endl;

		fp = fopen(fileName, "r");

		if (fp == NULL) 
		{
			cout << fileName << " file not found!" << endl;
		}
		else
		{
			while (fscanf(fp, "%[^\t]\t%s\t%s\t%s\n", phoneBook[i].name, phoneBook[i].areaCode, phoneBook[i].prefix, phoneBook[i].number) != EOF)
			{
				i++;
			}

			fclose(fp);

			do 
			{
				cout << "Enter a partial name to search (no spaces) or enter '!' to exit" << endl << "> ";

				cin >> nameSearched;

				if (nameSearched[0] == '!')
				{

				}
				else
				{
					for (i = 0; i < MAX_NAME_LENGTH; i++)
					{
					
						toLowerCaseAndCopy(lowerNameSearched, nameSearched);
						toLowerCaseAndCopy(lowerDirName, phoneBook[i].name);

						if (strStr(lowerDirName, lowerNameSearched) != NULL)
						{
							cout << phoneBook[i].name << ": (" << phoneBook[i].areaCode << ") " << phoneBook[i].prefix << "-" << phoneBook[i].number << endl;
						}
					}
				}

			} while (nameSearched[0] != '!');
	
		}

		cout << "Thank you for using " << programTitle << " directory." << endl;
	}
}