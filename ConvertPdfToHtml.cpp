//
// Created by vradmin on 18-9-4.
//

#include <iostream>
#include <QDir>
#include <QDebug>
#include <fstream>
#include <QProcess>

int main() {
  QString work_dir_("/home/vradmin/Documents/paper");
  QDir dirPath(work_dir_);
  QList<QFileInfo> file(dirPath.entryInfoList(
      {"*.pdf"}));
  QString name = "";
  std::vector<QString> files_fn;
  for (int iter = 0; iter < file.size(); iter++) {
        name = work_dir_ + "/" + file[iter].fileName();
//    name = file[iter].fileName();
    if (file[iter].isFile()) {
      files_fn.push_back(name);
    }
  }

//  QProcess process;
  QString program;
  QStringList parameters;
  program = "pdf2htmlEX";
  int res;
  for (int iter = 0; iter < files_fn.size(); ++iter) {
    parameters.clear();
    parameters << "--process-outline" << "0" << "--fit-width" << "1080" << files_fn[iter];
//    process.start(program, parameters);
    res = QProcess::execute(program, parameters);
    if (res == -2) {
      printf("process cannot be started \n");
    }else if(res == -1){
      printf("process crashes \n");

    }else{
      printf("process return normally \n");
    }
  }

  return 0;
}