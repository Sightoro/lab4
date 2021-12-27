// Copyright 2021 Yuriy <yuralong.skiy@mail.ru>

#include "AccountInfo.hpp"

#include <iostream>

AccountInfo::AccountInfo(std::string& account, std::string& broker,
                         std::string& last_date)
    :_account(account)
      , _broker(broker)
      , _last_date(last_date)
      , _count(1) {}

AccountInfo::~AccountInfo() = default;

std::string AccountInfo::get_account() const { return _account; }
std::string AccountInfo::get_broker() const { return _broker; }
std::string AccountInfo::get_last_date() const { return _last_date; }
unsigned int AccountInfo::get_count() const { return _count; }

void AccountInfo::inc_count() { ++_count; }
void AccountInfo::set_date(std::string& new_date) { _last_date = new_date; }

File::File(std::string& filename, std::string& broker)
    :_filename(filename)
      , _broker(broker) {}
File::~File() = default;

void File::print_file() const {
  std::cout << _broker << " " << _filename << std::endl;
}
