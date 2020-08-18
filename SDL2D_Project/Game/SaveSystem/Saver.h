#ifndef SAVER_H
#define SAVER_H
#include <map>
#include <fstream>
using namespace std;
struct DataSaver {
	int xSize, YSize;
	int const MapSize;
	int XPos, YPos;
	
};
class  Saver
{
public:
	static Saver& getInstance();
	Saver(const Saver&) = delete;
	Saver(Saver&&) = delete;
	Saver& operator=(const Saver&) = delete;
	Saver& operator=(Saver&&) = delete;
	void SaveData(int case_);
 private:
	 enum DataCaseSaves
	 {
		 MapSave=0,
		 StateSave,
		 AutoSave, 
		 DevSave, 
		 LevelSave,
		 PlayerSave, 

	 };
	Saver();
	~Saver();
};

#endif