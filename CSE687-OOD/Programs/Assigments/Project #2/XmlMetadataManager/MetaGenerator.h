#ifndef META_GENERATOR_H
#define META_GENERATOR_H
/////////////////////////////////////////////////////////////////////////
//  MetaGenerator.h    -  facility to generator metadata xml files     //
//  ver 1.0                                                            //
//  Language:       Visual C++, ver 6.0                                //
//  Platform:       MacBook Pro, Windows7 Pro				           //
//  Application:    CSE687 project #2	                               //
//  Author:         Ider Zheng, Syracuse University					   //
//                  (315) 560-4977, ider.cs@gmail.com				   //
/////////////////////////////////////////////////////////////////////////


#include "xmlTran.h"
#include "PackageInfo.h"
#include "IIncludes.h"
#include <string>

class IMetaGenerator
{
public:
	virtual std::string GetMetadata(const std::string& filePath) = 0;
	virtual std::string GetMetadata(const PackageInfo& pack) = 0;
};


class MetaGenerator:public IMetaGenerator
{
public:
	MetaGenerator(IInclude* include):inc(include){};
	~MetaGenerator(){delete inc;}
	virtual std::string GetMetadata(const std::string& filePath);
	virtual std::string GetMetadata(const PackageInfo& pack);
	std::string GetKeyName(const std::string& filePath);
	void Clear();
private:
	void GenerateReferences(const std::string& filePath);
	xmlElem meta;
	xmlRep packInfo;
	xmlRep references;
	IInclude* inc;
};

#endif