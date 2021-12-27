#include <iostream>
#include "iteration.hpp"

int main(int argc, char* argv[]) {

  boost::filesystem::path p;
  create_path(argc, argv, p);

  std::vector<AccountInfo> accs = {};
  std::vector<File> files = {};

  try
  {
    if (boost::filesystem::exists(p)) {
      switch_path(p, accs, files);
    } else {
      std::cout << p << "doesn't exist!" << std::endl;
    }
  }
  catch (const boost::filesystem::filesystem_error& ex)
  {
    std::cout << ex.what() << std::endl;
  }

  print_files(files);
  print_acc_inf(accs);

  return 0;
}
