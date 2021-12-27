// Copyright 2021 Yuriy <yuralong.skiy@mail.ru>

#include <boost/filesystem.hpp>
#include <iostream>
#include <vector>

#include "AccountInfo.hpp"

#ifndef INCLUDE_ITERATION_HPP_
#define INCLUDE_ITERATION_HPP_

#define  StemSize 25

void create_path(int argc, char* argv[], boost::filesystem::path& p);

void directory_iteration(const boost::filesystem::path& p,
                         std::vector<AccountInfo>& accs,
                         std::vector<File>& files);
void filename_parse(const boost::filesystem::path& p,
                    std::vector<AccountInfo>& accs,
                    std::vector<File>& files);
void open_symlink(const boost::filesystem::path& p,
                  std::vector<AccountInfo>& accs,
                  std::vector<File>& files);

bool check_filename(const boost::filesystem::path& p);
void switch_path(const boost::filesystem::path& p,
                 std::vector<AccountInfo>& accs,
                 std::vector<File>& files);

void print_files(const std::vector<File>& files);
void print_acc_inf(const std::vector<AccountInfo>& accs);

#endif // INCLUDE_ITERATION_HPP_
