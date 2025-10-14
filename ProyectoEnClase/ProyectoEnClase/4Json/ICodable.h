#pragma once
#include <json/json.h>
#include <functional>
#include <string>

class ICodable
{
public:
	typedef std::function <ICodable * ()> SubClassDecode;
	typedef std::map <std::string, SubClassDecode> DecodeMap;

public:
	static std::string DecodeKey();
	static void SaveDeocdeprocess(std::string className, SubClassDecode decodeProcess);

	template <typename T, typename = typename std::enable_if<std::is_base_of<ICodable, T>::value>::type>
	static void SaveDecodeProcess()
	{
		SaveDecodeProcess(typeid(T).name(), []()
			{
				return new T();
			});
	}
	virtual Json::Value Code() = 0;
	virtual void Decode(Json::Value json); 

	template <typename T, typename = typename std::enable_if<std::is_base_of<ICodable, T>::value>::type>
	static T* FromJson(Json::Value json)
	{
		std::string className = json[DecodeKey()].asString();
		ICodable* codable = (*GetDecodeMap())[className]();

		//Otra forma de hacer exactamente lo mimsmo que la linea de ariba
		/*	DecodeMap* decodeMap = GetDecodeMap();
		SubClassDecode decodeLamda = (*decodeMap)[className];
		ICodable codable = decodeLamda(); */

		T* codableCasted = dynamic_cast<T*>(codable);

		codableCasted->Decode(json);

		return codableCasted;
	}
	

protected:



private:
	static DecodeMap* GetDecodeMap();

};