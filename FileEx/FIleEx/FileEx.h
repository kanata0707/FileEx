#ifndef FILEEX_H
#define FILEEX_H

#include <fstream>

class FileEx {
private:
	std::fstream m_fFile;
	std::wstring m_wstrFilePath;

public:
	FileEx();
	~FileEx();
	void Open();
	void Close();
	void Write();
	void Change();
};


#endif // !FILEEX_H
