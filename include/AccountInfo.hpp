// Copyright 2021 Yuriy <yuralong.skiy@mail.ru>

#include <string>

#ifndef INCLUDE_ACCOUNTINFO_HPP_
#define INCLUDE_ACCOUNTINFO_HPP_

class AccountInfo {
 public:
  AccountInfo(std::string& account,
              std::string& broker,
              std::string& last_date);
  ~AccountInfo();

 public:
  std::string get_account() const;
  std::string get_broker() const;
  std::string get_last_date() const;
  unsigned get_count() const;

  void inc_count();
  void set_date(std::string& new_date);


 private:
  std::string _account;
  std::string _broker;
  std::string _last_date;
  unsigned _count;
};

class File {
 public:
  File(std::string& filename, std::string& broker);
  ~File();

 public:
  void print_file() const;


 private:
  std::string _filename;
  std::string _broker;
};

#endif  // INCLUDE_ACCOUNTINFO_HPP_
