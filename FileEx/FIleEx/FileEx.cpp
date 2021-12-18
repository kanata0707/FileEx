#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include "FileEx.h"

FileEx::FileEx() {
	m_fFile;
	m_wstrFilePath = L"C:\\work\\VisualStudio\\CPP_FileEx\\FIleEx\\試験用ディレクトリ\\000000_0.vsb";

}

FileEx::~FileEx() {
}

void FileEx::Open() {
	m_fFile.open(m_wstrFilePath, std::ios::out | std::ios::binary);
	if (!m_fFile) {
		std::cout << "ファイルが開けません";
	}
}

void FileEx::Close() {
	m_fFile.close();
}

void FileEx::Write() {

	char cData[64];
	memset(cData, '0', sizeof(cData));
	for (int i = 0; i < 64; i++) {
		cData[i] = i;
	}

	m_fFile.write(cData, sizeof(cData));
}

void FileEx::Change() {
	Close();

	int iPos = m_wstrFilePath.rfind(L"_");
	iPos -= 6;
	std::wstring wstrSub = m_wstrFilePath.substr(iPos, 6);
	int iFileName = std::stoi(wstrSub);
	if (iFileName < 999999) {
		iFileName++;
		std::wostringstream sout;
		sout << std::setfill(L'0') << std::setw(6) << iFileName;
		wstrSub = sout.str();
		m_wstrFilePath.replace(iPos, 6 ,wstrSub);
		Open();
	}
	else {
		std::cout << "これ以上ファイルを作成できません";
	}



}