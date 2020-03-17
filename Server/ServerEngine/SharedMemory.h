﻿#ifndef __SHARE_MEMORY_H__
#define __SHARE_MEMORY_H__
#include "DBInterface/DBInterface.h"

#define BLOCK_CHECK_CODE	0x5A

/**共享内存的状态
*/
enum SharedMemoryState
{
	SMS_NONE,  ///未使用，空闲状态
	SMS_USE,    //已经使用了，数据库服务器可以读取修改写入数据库
	SMS_LOCK,///锁住状态，逻辑服务器正在写入
	SMS_RELEASE,///逻辑服务器已经释放了。数据库服务器写入修改后可以置为SMS_NONE状态
	SMS_DELETE,///删除标志
};

///所有放到sharedMemory里的元素都必须是从ShareObject派生的
struct ShareObject
{
	ShareObject();

	///开始修改，标记为被占用
	void lock();

	///判断是否被占有用
	BOOL islock()const;

	///标记为个改完成。
	void unlock();

	void useit();

	///标记为已经释放了
	void release();

	void destroy();

	BOOL isDestroy() const;

	BOOL isRelease() const;

	time_t getLastMotifyTime();

	///是否在使用
	BOOL isUse() const;

	void reset();

	UINT32					   m_dwCheckCode;
	SharedMemoryState          m_State;
	time_t                     m_updatetime;	///最后一次修改时间
};

///记录每个T块的状态
struct _SMBlock
{
	UINT32			m_dwIndex;      //数据当前编号
	BOOL			m_bUse;         //是否在使用true是正在使用，false是没有使用
	BOOL			m_bNewBlock;	///是否是刚刚新创建的区块
	time_t			m_beforeTime;   //DS服务器更新完成后回写的信息时间。
	time_t          m_afterTime;
	_SMBlock()
	{
		m_dwIndex = 0;
		m_bUse = false;
		m_beforeTime = 0;
		m_afterTime = 0;
		m_bNewBlock = false;
	}
};

///共享内存页结构
struct shareMemoryPage
{
	char*        m_pdata;///指定共享内存地址
	_SMBlock*    m_pBlock;///数据块的头位置
	HANDLE       m_shm;///
};

class SharedMemoryBase
{
public:
	SharedMemoryBase(const UINT32& nModuleID, UINT32 rawblockSize, UINT32 nCountPerPage, BOOL noCreate = false);

	SharedMemoryBase(UINT32 rawblockSize, char* pdata, INT32 len);

	virtual ~SharedMemoryBase();
protected:

	typedef std::vector<shareMemoryPage> ShareMemoryPageMapping;
	///共享内存页映射.
	ShareMemoryPageMapping m_ShareMemoryPageMapping;

	UINT32			m_nCountperPage;	///页面容纳T类型数量
	UINT32			m_nPageCount;	///页数量
	UINT32			m_nCount;		///T类型的总个数,T类型必须是定长的。
	UINT32			m_nSpace;		///每个元素的宽度
	UINT32			m_rawblockSize;
	UINT32			m_nModuleID;
	BOOL			m_bEmpty;

	///所有数据头的集合
	typedef  std::map<INT32, _SMBlock*>    mapSMBlock;
	mapSMBlock                     m_mapSMBlock;///所有数据块头信息


	typedef std::map<void*, _SMBlock*>  mapUsedSMBlock;
	mapUsedSMBlock                 m_mapUsedSMBlock;	///所有使用了块的数据信息


	typedef std::map<INT32, _SMBlock*> mapFreeSMBlock;
	mapFreeSMBlock                 m_mapFreeSMBlock;///所有空闲的块信息
private:

	///创建一个新页
	BOOL NewPage();

	/**
	* @brief		初始化数据区域
	* @details		数据清0，并设置保护区域
	* @param[in]	rPage : 共享内存页
	* @return		void
	* @remarks
	*/
	void InitPage(shareMemoryPage& rPage);


public:

	///数据库服务器不需要初始化map,逻辑服务器才需要,所以分开
	void InitToMap();


	/**是否是首创共享内存*/
	BOOL IsFirstCreated();


	/**从共享内存里恢复其他页*/
	void ImportOtherPage();

	/**获取数量*/
	const UINT32 GetCount()const;

	/**获取还有多少块空闲内存
	*/
	UINT32 GetFreeCount()const;

	///获取已经使用了多少块
	UINT32 GetUseCount()const;

	/**通过id获取原始内存中的描述块指针
	*/
	virtual _SMBlock* GetSMBbyRawIndex(INT32 index);

	/**通过id获取原始内存中的描述块指针
	*/
	virtual ShareObject*  GetObjectByRawindex(UINT32 index);

	const UINT32 GetRawMemoryBlockSize();

	const INT32 GetBlockSize() { return m_rawblockSize; }

	/*处理已用区块中被数据库服务器释放的区块*/
	void ProcessCleanDirtyData();

	/*从空闲内存中分配一个块,如果没有了返回空
	@param isNewBlock 为true时会在保存期调用saveobject 的Create虚函数
	*/
	virtual ShareObject* NewObject(BOOL isNewBlock = false);

	/**释放一块已经不再使用的内存*/
	virtual BOOL DestoryObject(ShareObject* pobject);

	mapUsedSMBlock& GetUsedDataList()
	{
		return m_mapUsedSMBlock;
	}
};

template<typename T>
class SharedMemory : public SharedMemoryBase
{
public:
	SharedMemory(const UINT32& nModuleID, UINT32 nCountPerPage, BOOL noCreate = false)
		: SharedMemoryBase(nModuleID, sizeof(T), nCountPerPage, noCreate)
	{

	}

	T*  GetObjectByRawindex(UINT32 index)
	{
		return static_cast<T*>(SharedMemoryBase::GetObjectByRawindex(index));
	}

	T* NewObject(BOOL isNewBlock = false)
	{
		T* pTmp = static_cast<T*>(SharedMemoryBase::NewObject(isNewBlock));
		if (pTmp == NULL)
		{
			return NULL;
		}

		new(pTmp)(T);
		return pTmp;
	}

	_SMBlock* GetSMBbyRawIndex(INT32 index)
	{
		return SharedMemoryBase::GetSMBbyRawIndex(index);
	}

	BOOL DestoryObject(T* pobject)
	{
		return SharedMemoryBase::DestoryObject(pobject);
	}
};


template <typename T> class DataWriter
{
public:
	DataWriter(const UINT32& nModuleID, UINT32 nCount)
	{
		m_MemoryPool = NULL;
		m_nModuleID = nModuleID;
		m_nCount = nCount;
	}
	~DataWriter()
	{
		delete m_MemoryPool;
		m_MemoryPool = NULL;
	}

	/**数据库修改*/
	BOOL SaveModifyToDB(IDBInterface* pdb)
	{
		///共享内存不存在直接返回
		if (m_MemoryPool == NULL)
		{
			m_MemoryPool = new SharedMemory<T>(m_nModuleID, m_nCount, true);
		}
		if (m_MemoryPool == NULL)
		{
			return false;
		}

		if (m_MemoryPool->IsFirstCreated())
		{
			///共享内存还没创建
			delete m_MemoryPool;
			m_MemoryPool = NULL;
			return false;
		}

		INT32 newtimes = 0, writetimes = 0, deletetimes = 0, releasetime = 0;
		BOOL hasOprate = false; //是否有操作
		///获取所有修改过的数据,getRawMemoryBlockSize会重新计算所有共享块，
		UINT32 temblockSize = m_MemoryPool->GetRawMemoryBlockSize();
		for (UINT32 r = 0; r < temblockSize; r++)
		{
			_SMBlock* pBlock = m_MemoryPool->GetSMBbyRawIndex(r);
			if (pBlock == NULL)
			{
				continue;
			}
			if (pBlock->m_bUse == false)
			{
				continue;
			}
			T* pdata = m_MemoryPool->GetObjectByRawindex(r);
			if (pdata == NULL)
			{
				continue;
			}
			if (pdata->m_dwCheckCode != BLOCK_CHECK_CODE)
			{
				continue;
			}
			if (!pdata->isUse())
			{
				continue;
			}
			///正在修改数据,跳过
			if (pdata->islock())
			{
				continue;
			}
			///优先回调删除
			if (pdata->isDestroy())
			{
				pdata->Delete(pdb);
				m_MemoryPool->DestoryObject(pdata);
				hasOprate = true;
				deletetimes++;
				continue;
			}
			///其次回调新建
			if (pBlock->m_bNewBlock)
			{
				pBlock->m_beforeTime = time(NULL);
				pdata->Create(pdb);
				pBlock->m_bNewBlock = false;
				pBlock->m_afterTime = time(NULL);
				hasOprate = true;
				newtimes++;
				continue;
			}

			time_t lastMotifyTime;
			time_t beforeTime, afterTime;
			lastMotifyTime = pdata->getLastMotifyTime();
			beforeTime = pBlock->m_beforeTime;
			afterTime = pBlock->m_afterTime;
			BOOL needsave = false;
			///保存完毕的时间大于保存前的时间,那么上一次保存成功的
			if (afterTime >= beforeTime)
			{
				if (lastMotifyTime > beforeTime)
				{
					needsave = true;
				}
			}
			else
			{
				needsave = true;///上一次保存失败,立即保存
			}

			if (needsave)
			{
				pBlock->m_beforeTime = time(NULL);
				pdata->Update(pdb);
				hasOprate = true;
				writetimes++;
				pBlock->m_afterTime = time(NULL);
				continue;
			}


			if (pdata->isRelease())
			{
				///释放的时候执行一次保存...如果上次没有保存成功或者，释放前修改了就再保存一次
				if ((lastMotifyTime > 0) && (afterTime < beforeTime || lastMotifyTime > beforeTime))
				{
					pBlock->m_beforeTime = time(NULL);/// add by dsq
					pdata->Update(pdb);
					hasOprate = true;
					writetimes++;
					continue;
				}
				m_MemoryPool->DestoryObject(pdata);
				releasetime++;
			}

		}

		return hasOprate;
	}
private:
	SharedMemory<T>*	m_MemoryPool;///模块内存池
	UINT32				m_nCount;///共享内存大小
	UINT32				m_nModuleID;
};

#endif