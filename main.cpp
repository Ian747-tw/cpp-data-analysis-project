#include "data_reader.hpp"
#include "func.hpp"

#include <iostream>

using namespace std;

int main(int argc, char **argv) {
  if (argc < 2) {
    cerr << "Usage: " << argv[0] << " /path/to/data/file\n";
    return 1;
  }

  Dataset data = read_data(argv[1]);
  if (data.sale.empty()) {
    cerr << "No data loaded. Check the file path.\n";
    return 1;
  }

  cout << "Rows read: " << data.sale.size() << "\n";
  cout << "First row user_id: " << data.user_id[0] << "\n";
  return 0;
}
