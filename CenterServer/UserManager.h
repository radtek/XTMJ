#ifndef _USER_MANAGER_H_
#define _USER_MANAGER_H_

#include "LSingleton.h"
#include "DUser.h"

class UserManager : public LSingleton<UserManager>
{
public:
	UserManager();
	~UserManager();

	virtual	bool		Init();
	virtual	bool		Final();

	void	addUser(boost::shared_ptr<DUser> user);
	void	delUser(const Lstring& strUserId);
	void	delUser(Lint iUserId);

	boost::shared_ptr<CSafeUser> getUser(const Lstring& strUserId);
	boost::shared_ptr<CSafeUser> getUser(Lint iUserId);
public:
	void LoadUserIdInfo(Lint serverID);
public:
	void SaveUser(DUser* user);
	void SaveCardInfo(DUser* user,Lint cardType, Lint count, Lint operType, const Lstring& admin, const Lstring& remark="");
	void SaveUserLastLogin(DUser* user);
protected:
	bool	_loadUserInfoFromDB();
	void	_addUser(boost::shared_ptr<DUser> user);

	void	_loadTestData();		//压力测试
protected:
	void	_loadUserInfoFromDB(int iBeginIndex, int iCount);
private:
	bool m_bLoadUserSuccess;
private:
	boost::mutex m_mutexQueue;

	std::map<Lstring, boost::shared_ptr<DUser> > m_mapUUID2User;
	std::map<Lint, boost::shared_ptr<DUser> > m_mapId2User;
};

#define gUserManager UserManager::Instance()

#endif