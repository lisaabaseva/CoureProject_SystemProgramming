#ifndef SEC_LIBRARY
#define SEC_LIBRARY
#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <vector>
#include <sys/stat.h>
#include <iostream>
#include <string>
#include <dirent.h>
#include <libconfig.h>
#include <pwd.h>
#include <vector>
#include <string>
#include <check.hpp>
#include <type_packet.h>
using namespace std;

extern int fd_connect_to_daemon;

std::istream& operator>>(std::istream& is, right_t& r);
std::ostream& operator<<(std::ostream& os, const right_t& r);
std::ostream& operator<<(std::ostream& os, const std::vector<std::pair<string, bool>> list_storage);

#pragma region INNITALIZE
int sec_init();
#pragma endregion

#pragma region REQUEST_OPEN_DESCRIPTOR
int sec_openat(int uid, const char* filename, mode_t mode);
int sec_open(const char* filename, mode_t mode);
#pragma endregion

#pragma region REQUEST_CHECK_RIGHT
right_t sec_check(int uid, const char* filename, right_t rights);
#pragma endregion

#pragma region REQUEST_LIST_DIR
std::vector<std::pair<string, bool>> sec_list_storage(int target_uid);
#pragma endregion

#pragma region REQUEST_GRANT
right_t sec_grant(int uid, const char* filename, right_t right);
#pragma endregion

#pragma region REQUEST_REWOKE
right_t sec_revoke(int uid, const char* filename, right_t right);
#pragma endregion

#pragma region REQUEST_DELETE
int sec_unlink_at(int target_uid, const char* filename);
#pragma andregion

#endif // SEC_LIBRARY