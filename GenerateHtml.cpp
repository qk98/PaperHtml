#include <iostream>
#include <QDir>
#include <QDebug>
#include <fstream>

int main() {
  QString work_dir_("/home/vradmin/CLionProjects/untitled6");
  QDir dirPath(work_dir_);
  QList<QFileInfo> file(dirPath.entryInfoList(
      {"*.html"}));
  QString name = "";
  std::vector<QString> files_fn;
  for (int iter = 0; iter < file.size(); iter++) {
//    name = work_dir_ + "/" + file[iter].fileName();
    name = file[iter].fileName();
    if (file[iter].isFile()) {
      files_fn.push_back(name);
    }
  }

  std::ofstream f_index("save/index.html");
  f_index << "<!DOCTYPE html>" << std::endl;
  f_index << "<html>" << std::endl;
  f_index << "<head>" << std::endl;
  f_index << "<title> Papers </title>" << std::endl;
  f_index << "</head>" << std::endl;
  f_index << "<body>" << std::endl;
  f_index << "<h1> Paper list </h1>" << std::endl;


  QString res;
  for (int iter = 0; iter < files_fn.size(); ++iter) {
    if (files_fn[iter] == "index.html") {
      continue;
    }
    f_index << "<p>" << std::endl;
    res = "<a href=\"http://127.0.0.1:8088/" + files_fn[iter] + "\">" + files_fn[iter] + "</a>";
    f_index << res.toStdString() << std::endl;
    f_index << "<p>" << std::endl;
  }

  f_index << "</body>" << std::endl;
  f_index << "</html>" << std::endl;

  return 0;
}