// Copyright 2021 Yuriy <yuralong.skiy@mail.ru>

#include "iteration.hpp"

void create_path(int argc, char* argv[], boost::filesystem::path& p) {
  if (argc < 2) {
    p = boost::filesystem::current_path();
  } else {
    boost::filesystem::path new_p(argv[1]);
    p = new_p;
  }
}

void directory_iteration(const boost::filesystem::path& p,
                         std::vector<AccountInfo>& accs,
                         std::vector<File>& files) {
  for (const boost::filesystem::directory_entry& x :
       boost::filesystem::directory_iterator(p)) {
    switch_path(x.path(), accs, files);
  }
}

void filename_parse(const boost::filesystem::path& p,
                    std::vector<AccountInfo>& accs,
                    std::vector<File>& files) {
  //Check for correct
  if (!check_filename(p)) return;

  //Get information from filename
  std::string filename = p.filename().string();
  std::string broker = p.parent_path().filename().string();
  std::string account = filename.substr(8, 8);
  std::string date = filename.substr(17, 8);

  //Add files for print
  File new_file = File(filename, broker);
  files.push_back(new_file);

  //Check for account exist
  for (auto& i : accs) {
    if (i.get_account() == account && i.get_broker() == broker) {
      i.inc_count();
      if (i.get_last_date() < date) i.set_date(date);
      return;
    }
  }

  //Add new account
  AccountInfo new_acc = AccountInfo(account, broker, date);
  accs.push_back(new_acc);
}

void open_symlink(const boost::filesystem::path& p,
                  std::vector<AccountInfo>& accs,
                  std::vector<File>& files) {
  boost::filesystem::path new_p = boost::filesystem::read_symlink(p);
  if (boost::filesystem::exists(new_p)) switch_path(new_p, accs, files);
}

bool check_filename(const boost::filesystem::path& p) {
  std::string stem = p.stem().string();
  std::string check_str = "balance_";

  if (stem.size() != StemSize) return false;
  if (stem[16] != '_') return false;
  for (std::size_t i = 0; i < check_str.size(); ++i) {
    if (stem[i] != check_str[i]) return false;
  }
  return true;
}

void switch_path(const boost::filesystem::path& p,
                 std::vector<AccountInfo>& accs,
                 std::vector<File>& files) {
  if (boost::filesystem::is_symlink(p)) {
    open_symlink(p, accs, files);
  } else if (boost::filesystem::is_regular_file(p)) {
    filename_parse(p, accs, files);
  } else if (boost::filesystem::is_directory(p)) {
    directory_iteration(p, accs, files);
  }
}

void print_files(const std::vector<File>& files) {
  if (files.empty()) {
    std::cout << "Balance files were not found" << std::endl;
    return;
  }
  for (auto& i : files) {
    i.print_file();
  }
}

void print_acc_inf(const std::vector<AccountInfo>& accs) {
  if (accs.empty()) return;
  std::cout << std::endl << "|----------FILES INFORMATION----------|\n"
            << std::endl;
  for (const auto& i : accs) {
    std::cout << "account:[" << i.get_account() << "] "
              << "files:[" << i.get_count() << "] "
              << "last_date:[" << i.get_last_date() << "] "
              << "broker:[" << i.get_broker() << "]" << std::endl;
  }
}
