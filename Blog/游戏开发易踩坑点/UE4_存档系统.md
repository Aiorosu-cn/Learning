[TOC]

在学习UE4蓝图时,学习Save 系统,在最后,还需要用到`save game to slot`这个节点,

按照我的想象,只需要把  SaveGameObject的数据,保存到硬盘上就行了,为啥那么还需要这个操作

# savegame to slot

save game to slot 节点调用后，如果在没打包之前会在项目文件本地建立SaveGames文件夹下保存.sav。

那么这个节点就是把内存中的数据保存到硬盘吗?

```cpp
bool UGameplayStatics::SaveGameToSlot(USaveGame* SaveGameObject, const FString& SlotName, const int32 UserIndex)
{
	// This is a wrapper around the functions reading to/from a byte array
	TArray<uint8> ObjectBytes;
	if (SaveGameToMemory(SaveGameObject, ObjectBytes))
	{
		return SaveDataToSlot(ObjectBytes, SlotName, UserIndex);
	}
	return false;
}

//这里调用了2个,一个是 tO memory,一个是 save data to slot


//FMemoryWriter负责USaveGame的属性序列化到内存，FObjectAndNameAsStringProxyArchive负责将序列化的属性转换成可读的文字。SaveGameObject->Serialize(Ar)开始真正的执行序列化操作，
//具体序列化的逻辑是集成在UObject里面 在void UObject::Serialize(FStructuredArchive::FRecord Record) 里 ,Engine\Source\Runtime\CoreUObject\Private\UObject\Obj.cpp
//得到的结果存储在OutSaveData
bool UGameplayStatics::SaveGameToMemory(USaveGame* SaveGameObject, TArray<uint8>& OutSaveData )
{
	if (SaveGameObject)
	{
		FMemoryWriter MemoryWriter(OutSaveData, true);

		FSaveGameHeader SaveHeader(SaveGameObject->GetClass());
		SaveHeader.Write(MemoryWriter);

		// Then save the object state, replacing object refs and names with strings
		FObjectAndNameAsStringProxyArchive Ar(MemoryWriter, false);
		SaveGameObject->Serialize(Ar);

		return true; // Not sure if there's a failure case here.
	}

	return false;
}
//根据前面得到的序列化后的OutSaveData，进行本地磁盘的存储SaveGame
bool UGameplayStatics::SaveDataToSlot(const TArray<uint8>& InSaveData, const FString& SlotName, const int32 UserIndex)
{
	ISaveGameSystem* SaveSystem = IPlatformFeaturesModule::Get().GetSaveGameSystem();

	if (SaveSystem && InSaveData.Num() > 0 && SlotName.Len() > 0)
	{
		// Stuff that data into the save system with the desired file name
		return SaveSystem->SaveGame(false, *SlotName, UserIndex, InSaveData);
	}

	return false;
}

//具体存储到本地的逻辑
virtual bool SaveGame(bool bAttemptToUseUI, const TCHAR* Name, const int32 UserIndex, const TArray<uint8>& Data) override
{
	return FFileHelper::SaveArrayToFile(Data, *GetSaveGamePath(Name));
}

//load 同理
USaveGame* UGameplayStatics::LoadGameFromSlot(const FString& SlotName, const int32 UserIndex)
{
	// This is a wrapper around the functions reading to/from a byte array
	TArray<uint8> ObjectBytes;
	if (LoadDataFromSlot(ObjectBytes, SlotName, UserIndex))
	{
		return LoadGameFromMemory(ObjectBytes);
	}

	return nullptr;
}

static USaveGame* LoadGameFromMemory(const TArray<uint8>& InSaveData);
static bool LoadDataFromSlot(TArray<uint8>& OutSaveData, const FString& SlotName, const int32 UserIndex);
```

